# Simple Shell

The Simple Shell is a basic implementation of a command line interface in the C programming language that replicates the core functionality of the sh shell.

# Files

 - **main.c** 
 - **main.h**
 -  **functions.c**
 -  **README**
 - **AUTHORS**

## Characteristics

**Command Line Interface:** The Simple Shell presents an intuitive user interface that allows users to enter commands and view execution results.

**Command Execution:** Commands entered by the user are executed by using the execve() function. This allows the execution of external programs and system commands.

## main.c
The main function executes a while loop that iterates as long as exit_flag is true. Inside the loop:

Check if the input is connected to a terminal (isatty(STDIN_FILENO)). If so, it displays a prompt in the format "($)".

Call function execute_func() to execute functions related to command interpretation.

The function execute_func() can modify the exit_flag to control whether the loop should continue or not.

## main.h

El archivo `main.h` contiene declaraciones de funciones que se utilizan en el programa principal.

**function prototypes:**

 
 - int main(void); 
 - int execute_func(void);
 - void strtrim(char *input);
 - void tokenizeInput(char *input, char **args, char *delimiter);
 - int get_full_path(const char *command, char *full_path);
 - extern char **environ;


## functions.c

The `functions.c` file contains implementations of the functions declared in `main.h`, which are used in the main program. Here's a brief summary of the file's contents:

-   **execute_func**: This function manages command execution. It reads user input using `getline`, processes it, and executes the specified command. It utilizes other functions like `strtrim`, `tokenizeInput`, and `get_full_path` to prepare and execute the command. It returns 1 if the execution is successful and `getline` doesn't fail, or 0 if `getline` fails.
    
-   **strtrim**: This function removes leading and trailing whitespace from an input string.
    
-   **tokenizeInput**: It divides an input string into tokens using a delimiter and stores them in an array of character pointers.
    
-   **get_full_path**: This function constructs the full path for a command entered by the user. It checks if the command is an absolute or relative path and searches system paths to find the executable path. It returns 1 if it finds the executable path and 0 if it doesn't.

## AUTHORS

 - **Nataly Cristina Rodriguez Rojas** <6925@holbertonstudents.com>
 - **Jesenia Bernal Mogollom** <6935@holbertonstudents.com>

# Flowchar
[flowchar simple shell](https://drive.google.com/file/d/1C3Qgq55CL5VPchin7JezLFs2MvH1TlOZ/view?usp=sharing)

