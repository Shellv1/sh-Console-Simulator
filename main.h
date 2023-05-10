/*
 *	Name:		David Albasini
 *	ID:			ncg816
 *	Class:		CS 3733.002
 *	Project:	2
 *	File:		main.h
 */

//	Common Imports
#include <stdio.h>
#include <stdlib.h>

//	Structs
typedef struct node {
	unsigned int iPID;
	struct node *next;
}List_PID;

//	Prototypes
int ShellExit(List_PID**);
int ShellCD(char***);
int ShellShowPID(List_PID*);

void AddPID(List_PID**, unsigned int);
void FreePIDList(List_PID**);

char* GetInput();
int TokenizeArgs(char***, char*);

void Prompt();
int MainTask(List_PID**);
int ExecuteArgs(int, char***, List_PID**);
int ExecuteShell(char***, List_PID**);
void Clean(int, char***);

//	Error Definitions
#define ERR1_1 "Input Error: Token size greater than 80 characters"
#define ERR1_2 "Input Error: Token count greater than 10"
#define ERR2_1 "Token Error: Failed to process input"
#define ERR3_1 "Shell Error: Failed to create child process"
#define ERR3_2 "Shell Error: Failed to execute command"
#define ERR3_3 "Shell Error: Failed to terminate successfully"
#define ERR3_4 "Shell Error: Failed to change directory"
#define ERR3_5 "Shell Error: Failed to display PIDs"
#define ERR4_1 "Memory Error: Memory allocation failed"
#define ERR4_2 "Memory Error: Memory reallocation failed"
#define ERR4_3 "Memory Error: Memory freedom failed"