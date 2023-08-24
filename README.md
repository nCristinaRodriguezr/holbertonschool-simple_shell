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

**Command Execution:** Commands entered by the user are executed by using the execvp() function. This allows the execution of external programs and system commands.

## main.c
The main.c file contains the simple shell source code, the file handles the main logic of the shell, including:

Input and Output: The code reads user input from the command line and displays a flag (($)) to indicate that it is waiting for a command.

Main Loop: Implements a main loop that constantly waits for commands entered by the user.

Process Creation: Use fork() to create a new child process that will execute the commands entered.

Command Execution: The child process executes the commands using the exec_token() function.

Waiting for Child Processes: The parent process waits for the child process to finish executing the command using waitpid().

## main.h

El archivo `main.h` contiene declaraciones de funciones que se utilizan en el programa principal.

**function prototypes:**

int main(void);
void exec_token(char **args, char *full_path);
void strtrim(char *input);
void tokenizeInput(char *input, char **args, char *delimiter);
void get_full_path(const char *command, char *full_path);

## functions.c

The `functions.c` file contains implementations of the functions declared in `main.h`, which are used in the main program. Here's a brief summary of the file's contents:

1.  **`exec_token`**: This function takes an array of arguments and a full path to a file, and it uses the `execve` function to execute the command represented by those arguments. If the command is not found, it displays an error message.
    
2.  **`strtrim`**: This function removes leading and trailing white spaces, newline characters, and null (`\0`) characters from an input string.
    
3.  **`tokenizeInput`**: Divides an input string into tokens using a specified delimiter and stores the tokens in an array of pointers to characters.

## AUTHORS

**Jesenia Bernal Mogollom** <6935@holbertonstudents.com>
**Nataly Cristina Rodriguez Rojas** <6925@holbertonstudents.com>
