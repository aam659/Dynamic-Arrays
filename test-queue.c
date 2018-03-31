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
#include "integer.h"
#include "cda.h"
#include "queue.h"
#include "real.h"

static void showItems(QUEUE *items) {
	printf("The items are ");
	displayQUEUE(stdout, items);				// Calls displayQUEUE method
	printf(".\n");

	return;
}

static void visualizeCall(QUEUE *items) {
	printf("visualizeDA method call: ");
	visualizeQUEUE(stdout, items);				// Calls visualizeQUEUE method
	printf("\n");

	return;	
}

static void sizeCall(QUEUE *items) {
	printf("sizeSTACK method call: ");
	int size = sizeQUEUE(items);				// Calls sizeQUEUE method
	printf("%d\n", size);

	return;
}

int main(int argc, char **argv) {
	int i;
	if (argc != 1) {
		fprintf(stderr, "usage: %s\n", argv[0]);	// Error if argc != 1
		exit(1);
	}

	QUEUE *items = newQUEUE(displayINTEGER);		// Creates a new queue object
	showItems(items);					// Prints details of an empty stack
	visualizeCall(items);
	sizeCall(items);
	printf("enqueue call(5): ");				// Enqueues 5 onto queue
	enqueue(items, newINTEGER(5));
	printf("\n");						// Prints details of queue
	sizeCall(items);
	showItems(items);
	visualizeCall(items);

	printf("peekQUEUE method call (INTEGER): ");
	int x = getINTEGER((INTEGER *) peekQUEUE(items));	// Tests peekQUEUE method for queue-top is 5
	printf("\nThe item at the top of the queue is %d.\n", x);
	printf("enqueue method call for 6, 2, 9, and 1: ");
	enqueue(items, newINTEGER(6));				// Enqueues 6, 2, 9, and 1 onto queue
	enqueue(items, newINTEGER(2));
	enqueue(items, newINTEGER(9));
	enqueue(items, newINTEGER(1));
	printf("\n");
	sizeCall(items);					// Prints details of queue
	showItems(items);
	visualizeCall(items);
	printf("peekQUEUE method call (INTEGER): ");
	x = getINTEGER((INTEGER *) peekQUEUE(items));		// Shows top of queue (5)
	printf("\nThe item at the top of the queue is %d.\n", x);
	printf("dequeue method call: ");
 	printf("The value ");
    	displayINTEGER(stdout, dequeue(items));			// Dequeues 5 from queue
    	printf(" was removed.\n");
    	showItems(items);					// Prints resulting details of queue
	sizeCall(items);
	visualizeCall(items);
	printf("peekQUEUE method call (INTEGER): ");
	x = getINTEGER((INTEGER *) peekQUEUE(items));		// Shows top of queue (6)
	printf("\nThe item at the top of the queue is %d.\n", x);
	printf("REMOVING ALL ITEMS FROM QUEUE:\n");

	int queueSize = sizeQUEUE(items);

	for (i = 0; i < queueSize; ++i) {			// Dequeues remaining items from queue
		printf("The value ");
		displayINTEGER(stdout, dequeue(items));
		printf(" was removed.\n");
	}

	showItems(items);					// Prints details of queue
	sizeCall(items);
	visualizeCall(items);

	printf("Now you've done it...\n");

	for (i = 0; i < 1000000; ++i) {				// Enqueues 1000000 values onto queue
		enqueue(items, newINTEGER(2 * i));
	}

	showItems(items);					// Prints details of queue
	sizeCall(items);
	visualizeCall(items);
	
	printf("peekQUEUE method call (INTEGER):\n");
	x = getINTEGER((INTEGER *) peekQUEUE(items));		// Shows top of queue
	printf("\nThe item at the top of the queue is %d.\n", x);

	printf("DEQUEUING:\n");
	
	for (i = 1000000; i > 0; --i) {				// Removes remaining values from queue
		dequeue(items);
	}
	
	showItems(items);					// Prints details of resulting queue
	sizeCall(items);
	visualizeCall(items);
	
	return 0;
}



