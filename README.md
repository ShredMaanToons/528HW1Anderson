# 528HW1Anderson

## Section 1: Review Questions
### 1) a) What is the difference between a compiler and an interpreter?
A compiler converts human readable code into machine code without running it, the interpreter on the other hand runs the human readable code line by line without create the machine code version seperately.

### 1) b) What is the output of a C program’s main() function by default?
integer
> [!TIP]
> **int** main(void)

### 2) What are header files in C and what is the purpose of the #include directive?
Header files declare each function and contain documentation for the function. The #include directive tells the program what files besides the source code need to be accessed to run the code.

### 3) Explain how to declare and define a function in C. What is the purpose of the return statement in a function? Can a function have more than one return statement?
To declare and define a function we must follow this format: `Return Type` `space` `Function Name` (`function parameter *type* **name**`,`function parameter *type* **name**`,...); <- This should be written in the header.    
`Return Type` `space` `Function Name` (`function parameter *type* **name**`,`function parameter *type* **name**`,...) <- This should be written in the source code, followed by the function code inside {}    
The return statement in a function tells the function what it should set as its value and tells the function to stop running.    
A function can have more than one return, but due to the return statement telling the function to stop running only one return be active in each branching path.

### 4) What is type casting? Provide an example C function that demonstrates explicit type casting from double to int. The function should accept two arguments that are both double and return their sum as an integer.
Type casting is the conversion of one data type to another data type.    
```
int caster(d1,d2)
{
    dSum = d1 + d2;
    iSum = (int)dSum;
    return iSum;
}
```

### 5) Explain the difference between local and global variables. Provide an example of each.
A local variable is a variable that is declared within a function and only exists within the function, being removed when the function ends. A global variable is declared outside of the functions and exists throughout the entire file.    
> **Examples**
```
double double1 = 1.5; // <- Global variable
double double2 = 2.4; // <- Global variable
int casted = caster(double1, double2); // <- Function called with global variables

int caster(d1, d2)
{
    dSum = d1 + d2; // <- Local variable = local variable + local variable
    iSum = (int)dSum; // <- Local variables
    return iSum; // <- Local variable
}
```

### 6) How are strings declared and initialized in C? What is the role of the null terminator ‘\0’?
```
char string_name[] = "String text";
```
The null terminator is placed at the end of the string to terminate it.

### 7) What is a pointer in C? How do you pass a pointer to a function? What advantages are there to passing a pointer instead of a value?
A pointer is a variable that contains another address as its value. If we pass a pointer instead of a value we can modify variables that are outside of the function by modifying the value at the pointer address.

### 8) What does the * operator and the & operator do in the context of pointers?
The \* operator is used to retrieve the value at the address it is placed in front of: `"*address" gives "value at address"`    
The \& operator is used to retrieve the address of a variable: `"&variable" gives "address of variable"`

### 9) What is the difference between while and do…while loops?
A while loop will check if the condition is met before the loop is run, the do...while loop runs the loop and then checks the condition before running the loop again.

### 10) What does the break statement do? How is it different from the continue statement?
The break statement exits a loop, with the continue statement skips past the current loop and starts the next iteration.

### 11) Explain the use of bitwise operators (i.e. &, |, ^, ~, <<, >>) in C. Which bitwise operators can be used to set, clear, toggle, or check a specific bit in an integer variable?
Bitwise operators are used to modify individual bits, most commonly through bit masks.
`bits & mask` will clear all bits where the mask is 0    
`bits | mask` will set all bits where the mask is 1    
`bits ^ mask` will toggle all bits where the mask is 1    
`~bits` will toggle all bits    
`bits << n` will shift all bits to the left by n places    
`bits >> n` will shift all bits to the right by n places
To check a specific bit: `bit & mask` with mask being all 0 except for 1 bit will allow us to check if the result is 0. If it is not than the one bit in the mask that was set to 1 corresponds to a 1 in the bits.

### 12) What is the purpose of the PxSEL0 and PxSEL1 GPIO registers? Write two statements that select the GPIO function for the pins P1.0 and P1.7.
PxSEL0 and PxSEL1 allow us to chose between 4 settings for each port. The combination of their values serves as a binary number between 0 and 3 the selects between the pin being (i/o), UCA0STE , and DCSS.
```
P1->SEL0 &= ~0xFF;
P1->SEL1 &= ~0xFF;
```

> [!WARNING]
> The options for what the pin will be based on PxSEL0 and PxSEL1 are different for each pin and are found in a table that must be referenced on page 139 of the datasheet.

### 13) Write a void function named P1_1_and_P1_4_Init that configures P1.1 and P1.4 as GPIO inputs with pull-up resistors enabled.
```
void P1_1_and_P1_4_Init(void)
{
    P1->SEL0 &= ~0x1E;
    P1->SEL1 &= ~0x1E;
    P1->DIR &= ~0x1E;
    P1->REN |= 0x1E;
    P1->OUT |= 0x1E;
}
```

### 14) Write a void function named Buttons_Init that configures the following pins as GPIO inputs with pull-down resistors enabled:
#### P3.1, P3.6, P5.0, P5.4
```
void Buttons_Init(void)
{
    P3->SEL0 &= ~0x42;
    P3->SEL1 &= ~0x42;
    P3->DIR &= ~0x42;
    P3->REN |= 0x42;
    P3->OUT &= ~0x42;

    P5->SEL0 &= ~0x11;
    P5->SEL1 &= ~0x11;
    P5->DIR &= ~0x11;
    P5->REN |= 0x11;
    P5->OUT &= ~0x11;
}
```

### 15) Write a void function named LEDs_Init that configures the following pins as GPIO outputs. Initialize the pins to zero.
#### P7.0 to P7.7
```
void LEDs_Init(void)
{
    P7->SEL0 &= ~0xFF;
    P7->SEL1 &= ~0xFF;
    P7->DIR |= 0xFF;
    P7->OUT &= ~0xFF;
}
```

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

