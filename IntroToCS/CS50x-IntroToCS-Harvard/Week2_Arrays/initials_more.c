/*

File:        initials_more.c  
Assignment:  Problem Set 2, Initials (more comfortable)
Course:      CS250, 2017
Institution: Harvard
Access:      edX
Author:      Lucas Brown (LMBRO)
Date:        September 29, 2017

This is an assignment and course are part of the OSSU curriculum: https://github.com/ossu/computer-science


Summary
--------
Implement a program that, given a person’s name, prints a person’s initials, per the below.

$ ./initials
Regulus Arcturus Black
RAB


Specification
--------------
Design and implement a program, initials, that, given a person’s name, prints a person’s initials.
- Implement your program in a file called initials.c in a directory called initials.
    - LMBRO: I'm doing this on my own machine, not the CS50 IDE, so it won't be in the initials directory.
- Your program should prompt a user for their name using get_string to obtain their name as a string.
    - LMBRO: I'm not using the CS50 Library, so I don't have access to get_string or what they call 'string'.
    - LMBRO: Instead, I'll use fgets to get a C-Style string, a char array
- You may assume that the user’s input will contain only letters (uppercase and/or lowercase) plus single spaces between words. You don’t need to worry about names like Joseph Gordon-Levitt, Conan O’Brien, or David J. Malan!
- However, the user's input might be sloppy, in which case there might be one or more spaces at the start and/or end of the user's input or even multiple spaces in a row.
- Your program should print the user’s initials (i.e., the first letter of each word in their name) with no spaces or periods, followed by a newline (\n).

*/
