Micah Joseph Grande
micah.grande@gmail.com

prog2 is a series of 6 projects that build upon the last to make more complicated programs. They use the same base structure made in prog2_1.

prog2_1 takes a user imputted string and seperates each word by printing back each word on a new line with "=" on either side of the word.

prog2_2 has the user enter a string and splits it into sperate tokens seperated by a spacebar input. Each token is scanned and it is displayed on a new line whether the token is a string or integer.

prog2_3 has the user enter up to 2 tokens and displays whether they are ints or strings. If more than 2 tokens are entered, the user is given an error and is prompted to try again.

prog2_4 limits the number of characters to 20 chars and displays an error if its too long. The user is limited to 2 tokens, and it displays whether they are ints or strings. The program keeps going until the user types "quit" in any form of capitalization.

prog2_5 limits the number of characters to 65 and 2 tokens. If the user goes over either restriction, they will be given an error and prompted to try again. The program also limits them to a single string or a string and integer in that order. If the user enters the wrong token(s), they are given an error and are prompted to try again. If the user types "quit" in any form of capitalization, the program will end.

prog2_6 requires the user to enter an integer as a command line argument when executing the file. If the user enters the wrong amount of arguments or a non-integer, they will be given an error and the program will stop. Once they give an integer, the user will then be prompted like they are in prog2_5. They will be given the same restrictions and output as in prog2_5 including being able to quit out of the program at any time.

Each program can be compiled using the C compiler command "gcc". Each program, with the exception of prog2_6.c can then be run by executing the file in the command prompt by entering "./a.out" unless the name was changed during the compiling process. prog2_6, as stated in the above paragraph, can be run by executing the program as stated in the sentence beforehand followed by a " " and integer.