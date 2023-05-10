/*
 *	Name:		David Albasini
 *	ID:			ncg816
 *	Class:		CS 3733.002
 *	Project:	2
 *	File:		input.c
 */

//	Imports
#include <string.h>
#include "main.h"

/*	FUNCTION: GetInput()
 *	PURPOSE:
 *		Converts an unknown amount of user input from stdin and converts to string.
 *	RETURN:
 *		str:	Input as (char*)
 */
char* GetInput() {
	
	int iSize = 0;
	char* sInput = NULL;
	char* sTemp = NULL;
	
	if ((sInput = (char*)malloc(80)) == NULL) return NULL;
	memset(sInput, '\0', 80);
	if ((sTemp = (char*)malloc(80)) == NULL) return NULL;
	memset(sTemp, '\0', 80);
	
	 do {
		sTemp = fgets(sTemp, 80, stdin);
		iSize += strlen(sTemp);
		
		if ((sInput = (char*)realloc(sInput, iSize)) == NULL) return NULL;
		
		strcat(sInput, sTemp);
		
		memset(sTemp, '\0', 80);
	} while ((strlen(sInput) % 10) == 9 && sInput[iSize-1] != '\n');
	
	sInput[iSize-1] = '\0';
	
	free(sTemp);
	
	return sInput;
}

/*	FUNCTION: TokenizeArgs(1,2)
 *		1:		Address of (str) array
 *		2:		(str)
 *	PURPOSE:
 *		Breaks a string into individual tokens by word
 *	RETURN:
 *		0+:		Number of arguments
 */
int TokenizeArgs(char*** sCommand, char* sInput) {

	int iArgc=0;
	char* sToken;
	
	sToken = strtok(sInput, " ");
	
	while(sToken != NULL) {
	
		iArgc++;
		
		*sCommand = (char**)realloc((*sCommand), (iArgc+1) * sizeof(char*));
		
		(*sCommand)[iArgc-1] = (char*)malloc(strlen(sToken));
		(*sCommand)[iArgc] = NULL;
		
		strcpy((*sCommand)[iArgc-1], sToken);
		
		sToken = strtok(NULL, " ");
	}

	free(sInput);

	return iArgc;
}