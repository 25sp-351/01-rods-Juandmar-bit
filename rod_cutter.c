#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int length;
    int value;
    int counter;
} PieceInfo;

// Open the file
FILE* openFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    return file;
}

// Function to read prices and update pieces
int readPricesAndUpdateItems(FILE* file, PieceInfo** pieces, int* pieceCount, int suppliedRodLength) {
    int length, value;

    while (fscanf(file, "%d, %d", &length, &value) == 2) {
        if(value < 0 || length < 0) {
            printf("Error: Negative values found in the list.\n\n");
            return -1;
        }

        while (length <= suppliedRodLength) {
            suppliedRodLength -= length;

            // Check if this piece already exists in the list
            if (*pieceCount > 0 && 
                (*pieces)[*pieceCount - 1].value == value && 
                (*pieces)[*pieceCount - 1].length == length) {
                (*pieces)[*pieceCount - 1].counter++; // Update counter
            } else {
                // Add a new piece
                *pieces = (PieceInfo*)realloc(*pieces, sizeof(PieceInfo) * (*pieceCount + 1));
                if (*pieces == NULL) {
                    printf("Memory allocation failed\n");
                    exit(1);
                }
                (*pieces)[*pieceCount].length = length;
                (*pieces)[*pieceCount].value = value;
                (*pieces)[*pieceCount].counter = 1;
                (*pieceCount)++;
            }
        }
    }
    // Check if there are any non-integer values
    if (!feof(file)) {
        printf("Error: Non-integer values found in the list.\n\n");
        return -1;
    }
    return suppliedRodLength; // Return the remaining rod length
}

int calculateTotalValue(PieceInfo* pieces, int pieceCount) {
    int totalValue = 0;
    for (int i = 0; i < pieceCount; i++) {
        totalValue += pieces[i].value * pieces[i].counter;
    }
    return totalValue;
}

void printResults(PieceInfo* pieces, int pieceCount, int remainder, int totalValue) {
    
    for (int i = 0; i < pieceCount; i++) {
        printf("%d @ %d = %d\n", pieces[i].counter, pieces[i].length, pieces[i].value * pieces[i].counter);
    }
    printf("Remainder: %d\n", remainder);
    printf("Total Value: %d\n\n", totalValue);
}

void freeResources(PieceInfo* pieces, FILE* file) {
    free(pieces);
    fclose(file);
}

int main(int argc, char* argv[]) {

    int suppliedRodLength = atoi(argv[1]), pieceCount = 0, remainder;
    if (suppliedRodLength <= 0) {
        printf("Error: Invalid rod length\n");
        exit(1);
    }
    
    if (argc < 2) {
        printf("Supplied Rod Length: %d\n", suppliedRodLength);
        return 1;
    }

    PieceInfo* pieces = (PieceInfo*)malloc(sizeof(PieceInfo));
    if (pieces == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    FILE* file = openFile(argv[2]);
    remainder = readPricesAndUpdateItems(file, &pieces, &pieceCount, suppliedRodLength);
    if (remainder != -1) {
        int totalValue = calculateTotalValue(pieces, pieceCount);
        printResults(pieces, pieceCount, remainder, totalValue);
    }
    freeResources(pieces, file);

    return 0;
}
