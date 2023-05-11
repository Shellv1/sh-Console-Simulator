# sh-Console-Simulator
A C program that mimics a shell console

## Overview of Functionality
-Prints a prompt that displays the current working directory\

-When a command is entered:\

&emsp;-Memory is dynamically allocated and input is tokenized\

&emsp;-Tokenized command is executed using execvp() or a series of built-in functions\

-The program is kept going by integer return values.\

&emsp;-If the return value is 0, then 'exit' has been entered or a child process is running and needs to quit.\

&emsp;-If the return value is -1, then there was an error or invalid input. This will prompt the user again without exiting.\

&emsp;-If the return value is greater than 0, then the parent process is running and needs to continue.
  
# Function Descriptions by File
## main.c
int main(): Prompt the user for commands while 'exit' is not entered and it is not part of a child process.\

void Prompt(): Print the shell prompt using the current working directory and make it blue.\

int MainTask(Struct**): Organizes the tasks of tokenizing the input and executing it.\

int ExecuteArgs(int, char***, Struct**): Determines whether the input needs to be executed using execvp() or a built-in function and stores its process ID.\

int Clean(int, char***): Frees memory used for tokenized input.

## input.c
char* GetInput(): Converts an unknown amount of user input into a string.\

int TokenizeArgs(char***, char*): Converts string created in GetInput() to a null-terminated tokenized string array.

## shellFunc.c
int ExecuteShell(char***, Struct**): Executes user command using execvp().\

int ShellExit(Struct**): Calls FreePIDList() to free the PID history and exit the program.\

int ShellCD(char***): Changes the current working directory.

int ShellShowPID(Struct**): Displays the last 5 process IDs.

## listPID.c
void AddPID(Struct**, unsigned int): Adds current PID to linked list of PIDs.\

void FreePIDList(Struct**): Frees memory used for list of PIDs.
