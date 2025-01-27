Cases scenearios for the Rod Cutting Problem
Given the supplied rod length in the command terminal and a list in with the length desire to be cut and its value. Length to be cut in descending order.
1. First Case: Positive values only and a small supplied rod length of 46.
   
    Given List:
   
    32, 13
   
    16, 7
   
    8, 4
   
    4, 2
   
    2, 1
   
    Test results:
   
    1 @ 32 = 13
   
    1 @ 8 = 4
   
    1 @ 4 = 2
   
    Remainder: 1
   
    Total Value: 19
   
3. Second Case: Positive values only and a large supplied rod length of 300.
   
    Given List:
   
    32, 13
   
    16, 7
   
    8, 4
   
    4, 2
   
    2, 1
   
    Test results:
   
    9 @ 32 = 117
   
    1 @ 8 = 4
   
    1 @ 4 = 2
   
    Remainder: 0
   
    Total Value: 123
   
5. Third Case: A negative value in the list either for length or price 
    and supplied rod length 87:
   
    Given List:

    13, 13
   
    6, 7
   
    8, 4
   
    -4, 2
   
    2, 1
   
    Test results:
   
    Error: Negative values are not allowed
   
7. Fourth Case: A non-integer value is given in the list and 
    supplied rod length 56.
   
    Given List:

    13, 13
   
    jump, 7
   
    8, 4
   
    4, 2
   
    2, 1
   
    Test resuts:
   
    Error: Non-integer values allowed
