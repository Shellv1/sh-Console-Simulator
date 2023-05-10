/*
 *	Name:		David Albasini
 *	ID:			ncg816
 *	Class:		CS 3733.002
 *	Project:	2
 *	File:		listPID.c
 */

//	Imports
#include "main.h"

/*	FUNCTION: AddPID(1,2)
 *		1:		Address of linked list
 *		2:		Process ID
 *	PURPOSE:
 *		Adds the PID of a child process to a linked list
 */
void AddPID(List_PID** llHead, unsigned int iPID) {

	List_PID* newNode = (List_PID*)malloc(sizeof(List_PID));
	
	newNode->iPID = iPID;
	
	if (*llHead == NULL) {
		newNode->next = NULL;
		*llHead = newNode;
	}
	else {
		newNode->next = *llHead;
		(*llHead) = newNode;
	}
}

/*	FUNCTION: FreePIDList(1)
 *		1:		Address of linked list
 *	PURPOSE:
 *		Frees the contents of linked list
 */
void FreePIDList(List_PID** llHead) {

	List_PID* llNext = NULL;
	
	while (*llHead != NULL) {
	
		llNext = (*llHead)->next;
		
		free(*llHead);
		
		*llHead = llNext;
	}
}