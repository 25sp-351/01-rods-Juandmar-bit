CC = clang 
CFLAGS = -Wall
EXEC = rodcut 
SRC = rod_cutter.c 

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

run: $(EXEC)
	@echo "Running program..."
	./$(EXEC) $(ROD_LENGTH) $(INPUT_FILE)

clean:
	rm -f $(EXEC)
