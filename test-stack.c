/* Author: Alan Manning */
/* Class: CS201 Data Structures and Algorithms */
/* Assignment 0 */
/* 7 September, 2017 */

/* This is the test file for the header files for assignment 0.
The data types that were used as tests consisted of doubles, ints, chars, etc,
where these types came from user-defined classes. */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "da.h"
#include "integer.h"
#include "stack.h"
#include "real.h"

static void showItems(STACK *items) {
	printf("The items are ");
	displaySTACK(stdout, items);				// Calls displaySTACK method
	printf(".\n");

	return;
}

static void visualizeCall(STACK *items) {
	printf("visualizeDA method call: ");
	visualizeSTACK(stdout, items);				// Calls visualizeSTACK method
	printf("\n");

	return;	
}

static void sizeCall(STACK *items) {
	printf("sizeSTACK method call: ");
	int size = sizeSTACK(items);				// Calls sizeSTACK method
	printf("%d\n", size);

	return;
}

int main(int argc, char **argv) {
	int i;
	if (argc != 1) {
		fprintf(stderr, "usage: %s\n", argv[0]);	// Error if argc != 1
		exit(1);
	}

	STACK *items = newSTACK(displayINTEGER);		// Creates stack object
	showItems(items);					// Prints empty stack details
	visualizeCall(items);
	sizeCall(items);
	printf("push call(5): ");
	push(items, newINTEGER(5));				// Pushes 5 onto stack
	printf("\n");						// Prints details
	sizeCall(items);
	showItems(items);
	visualizeCall(items);

	printf("peekSTACK method call (INTEGER): ");
	int x = getINTEGER((INTEGER *) peekSTACK(items));	// Tests peekSTACK method-top of stack is 5
	printf("\nThe item at the top of the stack is %d.\n", x);
	printf("push method call for 6, 2, 9, and 1: ");
	push(items, newINTEGER(6));				// Pushes 6, 2, 9, and 1 onto stack
	push(items, newINTEGER(2));
	push(items, newINTEGER(9));
	push(items, newINTEGER(1));
	printf("\n");						// Prints resulting information
	sizeCall(items);
	showItems(items);
	visualizeCall(items);
	printf("peekSTACK method call (INTEGER): ");		
	x = getINTEGER((INTEGER *) peekSTACK(items));		// Shows top of stack (1)
	printf("\nThe item at the top of the stack is %d.\n", x);
	printf("pop method call: ");
 	printf("The value ");
    	displayINTEGER(stdout, pop(items));			// Tests pop method and returns 1
    	printf(" was removed.\n");
    	showItems(items);
	sizeCall(items);
	visualizeCall(items);
	printf("peekSTACK method call (INTEGER): ");		// Shows new top of stack (9)
	x = getINTEGER((INTEGER *) peekSTACK(items));
	printf("\nThe item at the top of the stack is %d.\n", x);
	printf("REMOVING ALL ITEMS FROM STACK:\n");

	int stackSize = sizeSTACK(items);
	for (i = 0; i < stackSize; ++i) {			// Removes remaining items from stack
		printf("The value ");
		displayINTEGER(stdout, pop(items));
		printf(" was removed.\n");
	}
	showItems(items);					// Prints details for empty stack
	sizeCall(items);
	visualizeCall(items);


	printf("Inserting many values into stack!\n");

	for (i = 0; i < 1000000; ++i) {				// Inserts 1000000 items into stack
		push(items, newINTEGER(2 * i));
	}	

	showItems(items);					// Prints details of stack
	sizeCall(items);
	visualizeCall(items);

	printf("peekSTACK method call (INTEGER): ");		// Shows top of stack
	x = getINTEGER((INTEGER *) peekSTACK(items));
	printf("\n the item at the top of the stack is %d.\n", x);

	printf("Emptying stack!\n");
	
	for (i= 1000000; i > 0; --i) {				// Empties stack
		pop(items);
	}

	showItems(items);					// Prints details of an empty stack
	sizeCall(items);
	visualizeCall(items);

	return 0;
}



