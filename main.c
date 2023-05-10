/*
 *	Name:		David Albasini
 *	ID:			ncg816
 *	Class:		CS 3733.002
 *	Project:	2
 *	File:		main.c
 */

//	Imports
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/*	FUNCTION: main()
 *	PURPOSE:
 *		Main function
 *	RETURNS:
 *		0:		Exit success
 */
int main() {

	List_PID* llPID = NULL;
	
	do { Prompt(); } while (MainTask(&llPID));

	return 0;
}

/*	FUNCTION: AddPID()
 *	PURPOSE:
 *		Prints a colored shell prompt that displays the current working directory
 */
void Prompt() {

	char sCwd[80];
	
	printf("\033[1;34m%s/$ \033[0m", getcwd(sCwd, 80));
}

/*	FUNCTION: MainTask(1)
 *		1:		Address of linked list
 *	PURPOSE:
 *		Tokenize arguments;
 *		Execute tokens as shell commands
 *	RETURNS:
 *		0:		Exit (child process / user quit)
 *		!0:		Continue accepting input
 */
int MainTask(List_PID** llPID) {

	int iArgc=0;
	char** sCommand = NULL;

	iArgc = TokenizeArgs(&sCommand, GetInput());
	
	return ExecuteArgs(iArgc, &sCommand, llPID);
}

/*	FUNCTION: ExecuteArgs(1,2,3)
 *		1:		Number of arguments in command
 *		2:		Address of (str) array
 *		3:		Address of linked list
 *	PURPOSE:
 *		Execute tokens as shell commands;
 *		Free tokens after execution
 *	RETURNS:
 *		0:		Exit (child process / user quit)
 *		!0:		Continue accepting input
 */
int ExecuteArgs(int iArgc, char*** sCommand, List_PID** llPID) {

	pid_t iERR;

	if (!strcmp((*sCommand)[0], "exit"))
		iERR = ShellExit(llPID);

	else if (!strcmp((*sCommand)[0], "cd"))
		iERR = ShellCD(sCommand);

	else if (!strcmp((*sCommand)[0], "showpid"))
		iERR = ShellShowPID(*llPID);
	
	else {
		iERR = ExecuteShell(sCommand, llPID);
		waitpid(iERR, NULL, 0);
	}
	
	Clean(iArgc, sCommand);
	
	return iERR;
}

/*	FUNCTION: Clean(1,2,3)
 *		1:		Number of arguments in command
 *		2:		Address of (str) array
 *	PURPOSE:
 *		Free tokenized (str) array
 */
void Clean(int iArgc, char*** sCommand) {
	
	int i=0;

	for (i=0; i<iArgc; i++)
		free((*sCommand)[i]);
	free(*sCommand);
}