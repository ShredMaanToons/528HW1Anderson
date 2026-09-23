# 528HW1Anderson

## Section 1: Review Questions
### 1) a) What is the difference between a compiler and an interpreter?


### 1) b) What is the output of a C program’s main() function by default?


### 2) What are header files in C and what is the purpose of the #include directive?


### 3) Explain how to declare and define a function in C. What is the purpose of the return statement in a function? Can a function have more than one return statement?


### 4) What is type casting? Provide an example C function that demonstrates explicit type casting from double to int. The function should accept two arguments that are both double and return their sum as an integer.


### 5) Explain the difference between local and global variables. Provide an example of each.


### 6) How are strings declared and initialized in C? What is the role of the null terminator ‘\0’?


### 7) What is a pointer in C? How do you pass a pointer to a function? What advantages are there to passing a pointer instead of a value?


### 8) What does the * operator and the & operator do in the context of pointers?


### 9) What is the difference between while and do…while loops?


### 10) What does the break statement do? How is it different from the continue statement?


### 11) Explain the use of bitwise operators (i.e. &, |, ^, ~, <<, >>) in C. Which bitwise operators can be used to set, clear, toggle, or check a specific bit in an integer variable?


### 12) What is the purpose of the PxSEL0 and PxSEL1 GPIO registers? Write two statements that select the GPIO function for the pins P1.0 and P1.7.


### 13) Write a void function named P1_1_and_P1_4_Init that configures P1.1 and P1.4 as GPIO inputs with pull-up resistors enabled.


### 14) Write a void function named Buttons_Init that configures the following pins as GPIO inputs with pull-down resistors enabled:
#### P3.1, P3.6, P5.0, P5.4


### 15) Write a void function named LEDs_Init that configures the following pins as GPIO outputs. Initialize the pins to zero.
#### P7.0 to P7.7

## Section 2: Programming assignments
---
### Integer Size and Magnitude
#### Write a C program that reports whether a number is positive, negative, or zero, and prints its absolute value.

### Design Requirements:
1. Prompt the user to enter an integer.
2. Use if/else to classify the sign.
3. Compute the absolute value of the integer. You can use the built-in function abs() from the stdlib.h library. Refer to this Stack Overflow example.
4. Print both the classification (i.e. positive, negative, or zero) and the absolute value.

#### Name your source file as sign_and_magnitude.c and write at least five test cases to verify the functionality of your program. Provide a screenshot of your program’s output in your GitHub repository that shows all test cases.


---
### Bit Counter
#### Write a C program that counts how many bits are set to 1 in an unsigned 32-bit integer.

### Design Requirements:
1. Prompt the user to enter an unsigned 32-bit integer and add a condition that checks if the user has entered a valid integer. Otherwise, display an error message if the user has entered an invalid value.
2. Implement a loop using n &= (n – 1) to count the set bits.
3. Display the result to the user. Include your name in the output.

#### Name your source file as bit_counter.c and write at least five test cases to verify the functionality of your program. Provide a screenshot of your program’s output in your GitHub repository that shows all test cases. Example screenshots are shown below.


---
### Fibonacci
#### Write a C program that computes the Nth Fibonacci sequence using an iterative approach for n > 1.

### Design Requirements:
1. Prompt the user to enter an integer N, where N >= 2. Add a condition that checks if the user has entered a valid integer. Otherwise, display an error message if the user has entered an invalid value.
2. Use a loop to compute the Fibonacci sequence. Do not use recursion.
3. Display the Nth Fibonacci sequence. Include your name in the output.

#### Name your source file as fibonacci.c and write at least three test cases to verify the functionality of your program. Provide a screenshot of your program’s output in your GitHub repository that shows all test cases. Example screenshots are shown below.

