/*
 *	Name:		David Albasini
 *	ID:			ncg816
 *	Class:		CS 3733.002
 *	Project:	2
 *	File:		shellFunc.c
 */

//	Imports
#include <unistd.h>
#include "main.h"

/*	FUNCTION: ExecuteShell(1,2)
 *		1:		Address of (str) array
 *		2:		Address of linked list
 *	PURPOSE:
 *		Create child process;
 *		Execute tokens as shell commands
 *	RETURNS:
 *		0:		Exit (child process)
 *		!0:		Continue accepting input (parent process)
 */
int ExecuteShell(char*** sCommand, List_PID** llPID) {

	unsigned int pPID = fork();
	
	if (!pPID) {
		if ((execvp((*sCommand)[0], *sCommand)) == -1)
			printf("%s\n", ERR3_2);
	}
	else
		AddPID(llPID, pPID);
	
	return pPID;
}

/*	FUNCTION: ShellExit(1)
 *		1:		Address of linked list
 *	PURPOSE:
 *		Free list of child PIDs;
 *		print "exit"
 *	RETURNS:
 *		0:		Exit (user quit)
 */
int ShellExit(List_PID** llPID) {

	FreePIDList(llPID);

	printf("exit\n");

	return 0;
}

/*	FUNCTION: ShellCD(1)
 *		1:		Address of (str) array
 *	PURPOSE:
 *		Change environment variable for current working directory
 *	RETURNS:
 *		1:		Continue accepting input
 */
int ShellCD(char*** sCommand) {

	char cCwd[80];

	chdir((*sCommand)[1]);
	
	setenv("PWD", getcwd(cCwd, 80), 1);

	return 1;
}

/*	FUNCTION: ExecuteArgs(1)
 *		1:		Address of linked list
 *	PURPOSE:
 *		Print the last five child PIDs
 *	RETURNS:
 *		1:		Continue accepting input
 */
int ShellShowPID(List_PID* llPID) {

	List_PID* llCurr = llPID;
	
	int i;
	
	for (i=0; (i < 5) && (llCurr != NULL); i++) {
		printf("%u\n", llCurr->iPID);
		llCurr = llCurr->next;
	}

	return 1;
}