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
#include "cda.h"
#include "integer.h"
#include "real.h"

static void showItems(CDA *items) {
	printf("The items are ");
	displayCDA(stdout, items);			// Calls displayCDA
	printf(".\n");

	return;
}

static void visualizeCall(CDA *items) {
	printf("visualizeDA method call: ");
	visualizeCDA(stdout, items);			// Calls visualizeCDA
	printf("\n");

	return;	
}

static void sizeCall(CDA *items) {
	printf("sizeCDA method call: ");
	int size = sizeCDA(items);			// Calls sizeCDA
	printf("%d\n", size);

	return;
}

int main(int argc, char **argv) {
	int i;

	if (argc != 1) {
		fprintf(stderr, "usage: %s\n", argv[0]);// Error if argc != 1
		exit(1);
	}

	CDA *items = newCDA(displayINTEGER);		// Creates 2 CDA items
	CDA *secondItems = newCDA(displayINTEGER);
	showItems(items);				// Shows CDA info 
	visualizeCall(items);
	sizeCall(items);

	printf("Inserting values-insertCDAfront method (7), insertCDAback ");
	printf("(2), insertCDAfront (3), and insertCDAfront (5)\n");

	insertCDAfront(items, newINTEGER(7));		// Insert values & print
	insertCDAback(items, newINTEGER(2));
	insertCDAfront(items, newINTEGER(3));
	insertCDAfront(items, newINTEGER(5));

	showItems(items);
	sizeCall(items);
	visualizeCall(items);

	printf("Calling removeCDAfront, removeCDAback, removeCDAback, ");
	printf(" and removeCDAfront...\n");

    	displayINTEGER(stdout, removeCDAfront(items));	// Remove values & print
    	printf(" was removed.\n");

	displayINTEGER(stdout, removeCDAback(items));
    	printf(" was removed.\n");

	displayINTEGER(stdout, removeCDAback(items));
    	printf(" was removed.\n");

	displayINTEGER(stdout, removeCDAfront(items));
    	printf(" was removed.\n");

	showItems(items);
	sizeCall(items);
	visualizeCall(items);

	printf("Checking for empty list and setCDA method (insertCDAfront)\n");
	if ((sizeCDA(items)) == 0) {			// Test set-empty item 
		if (setCDA(items, 0, newINTEGER(7)) == NULL) {
			printf("Returned NULL from setDA call.\n");
		}
		
		showItems(items);			// Prints results
		sizeCall(items);
		visualizeCall(items);

		printf("Removing set value from front to empty list...\n");

		removeCDAfront(items);

		showItems(items);
		sizeCall(items);
		visualizeCall(items);
	}

	printf("That's how the cookie crumbles...\n");
	
	for (i = 0; i < 1000000; ++i) {			// Several inserts
	
		int parity = i % 2;

		switch(parity) {
			case 0:				// InsertCDAfront-even
				insertCDAfront(items, newINTEGER(i));
				break;

			case 1:				// InsertCDAback-odd
				insertCDAback(items, newINTEGER(i));
				break;

			default:			// Default case
				insertCDAback(items, newINTEGER(i));
		}

	}

	showItems(items);				// Print array
	visualizeCall(items);
	sizeCall(items);
	
	printf("getCDA method call (INTEGER): ");	// Tests get and set

	int x = getINTEGER((INTEGER *) getCDA(items, 5000));

	printf("\nThe 5001st item is %d.\n", x);
	printf("setCDA method call (INTEGER = 42): ");

	INTEGER *y = (INTEGER *) setCDA(items, 5000, newINTEGER(42));

	printf("\nThe 5001st item was %d. Calling getCDA method for new first item: \n", getINTEGER(y));

	x = getINTEGER((INTEGER *) getCDA(items, 5000));

	printf("The 5001st item is now %d.\n", x);
	printf("Calling removeCDAfront or removeCDAback...\n");


	for (i = 1000000; i > 0; --i) {			// Removes values
	
		int parity = i % 2;

		switch(parity) {
			case 0:				// RemoveCDAfront-even
				removeCDAfront(items);
				break;

			case 1:				// RemoveCDAback-odd
				removeCDAback(items);
				break;

			default:			// Default case
				removeCDAback(items);
		}
	}
	
	printf("extractDA method call:\n");		// Extract-empty item

	extractCDA(items);

	if (extractCDA(items) == NULL) {
                printf("Extracted on an empty array. Returned pointer to 0.\n");
        }

        printf("Recipient after extracting:\n");

	showItems(items);				// Prints empty CDA
	visualizeCall(items);
	sizeCall(items);

        printf("Second items are:\n");			// Prints empty CDA

        showItems(secondItems);
        visualizeCall(secondItems);
        sizeCall(secondItems);

        printf("Union on two empty arrays:\n");		// Union-empty arrays

        unionCDA(secondItems, items);

        printf("First items are now:\n");

        showItems(items);
        visualizeCall(items);
        sizeCall(items);

        printf("Second items are now:\n");

        showItems(secondItems);
        visualizeCall(secondItems);
        sizeCall(secondItems);

	printf("making a new array, inserting numbers 0 through 4,\n inclusive\n");

	for (i = 0; i < 5; ++i) {
		insertCDAback(items, newINTEGER(i));
	}

	printf("\ndisplaying the array...\n");
	displayCDA(stdout, items);

	printf("\nremoving the head item in the array...\n");
	removeCDAfront(items);
	printf("displaying the array...\n");
	displayCDA(stdout, items);
	printf("\nmaking a new array, inserting numbers 0 through 4,\ninclusive\n");

	insertCDAfront(secondItems, newINTEGER(5));
	insertCDAfront(secondItems, newINTEGER(6));
	insertCDAfront(secondItems, newINTEGER(7));
	insertCDAfront(secondItems, newINTEGER(8));
	insertCDAfront(secondItems, newINTEGER(9));
	printf("displaying the array...\n");
	displayCDA(stdout, items);


	printf("merging the two arrays...");
	unionCDA(items, secondItems);
	printf("\ndisplaying the array...\n");
	displayCDA(stdout, items);
	printf("\n");

	


	return 0;
}

