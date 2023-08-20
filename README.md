 Simple Shell

The Simple Shell is a basic implementation of a command line interface in the C programming language that replicates the core functionality of the sh shell.
Files


    main.c
    main.h
    shell.c
    README
    AUTHORS


Characteristics

Command Line Interface: The Simple Shell presents an intuitive user interface that allows users to enter commands and view execution results.

Command Execution: Commands entered by the user are executed by using the execvp() function. This allows the execution of external programs and system commands.

main.c

The main.c file contains the simple shell source code, the file handles the main logic of the shell, including:

Input and Output: The code reads user input from the command line and displays a flag (($)) to indicate that it is waiting for a command.

Main Loop: Implements a main loop that constantly waits for commands entered by the user.

Process Creation: Use fork() to create a new child process that will execute the commands entered.

Command Execution: The child process executes the commands using the exec_token() function.

Waiting for Child Processes: The parent process waits for the child process to finish executing the command using waitpid().

