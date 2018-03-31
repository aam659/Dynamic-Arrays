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
#include "real.h"

static void showItems(DA *items) {
	printf("The items are ");
	displayDA(stdout, items);				// Calls displayDA method to display array values on screen
	printf(".\n");

	return;
}

static void visualizeCall(DA *items) {
	printf("visualizeDA method call: ");
	visualizeDA(stdout, items);				// Calls visualize method to display array values on screen
	printf("\n");

	return;	
}

static void sizeCall(DA *items) {
	printf("sizeDA method call: ");
	int size = sizeDA(items);				// Calls sizeDA method to show array size
	printf("%d\n", size);

	return;
}

int main(int argc, char **argv) {
	int i;

	if (argc != 1) {
		fprintf(stderr, "usage: %s\n", argv[0]);	// Error message if argc != 1
		exit(1);
	}

	DA *items = newDA(displayINTEGER);			// Creates 2 INTEGER DA objects and 2 REAL DA objects
	DA *secondItems = newDA(displayINTEGER);
	DA *thirdItems = newDA(displayREAL);
	DA *fourthItems = newDA(displayREAL);
	printf("Details for first dynamic array:\n");		// Prints details for first and second objects
	showItems(items);
	visualizeCall(items);
	sizeCall(items);
	printf("Details for second dynamic array:\n");
	showItems(secondItems);
	visualizeCall(secondItems);
	sizeCall(secondItems);

	for (i = 0; i < 64; ++i) {				// Inserts into first and second DA objects and displays
		insertDA(secondItems, newINTEGER(i));
	}
	printf("First items are now:\n");
	showItems(secondItems);
	visualizeCall(secondItems);
	sizeCall(secondItems);
	
	for (i = 0; i < 1000; ++i) {
		insertDA(items, newINTEGER(i));
	}
	printf("Second items are now:\n");
	showItems(items);
	visualizeCall(items);
	sizeCall(items);

	printf("Removing everything from both arrays:\n");	// Removes from first and second DA objects
	
	for (i = 64; i > 0; --i) {
		removeDA(secondItems);
	}
	
	for (i = 1000; i > 0; --i) {
		removeDA(items);
	}
	
	printf("First items are now:\n");			// Shows that first and second DA objects are empty
	showItems(secondItems);
	visualizeCall(secondItems);
	sizeCall(secondItems);
	printf("Second items are now:\n");
	showItems(items);
	visualizeCall(items);
	sizeCall(items);
	printf("Going really crazy now...\n");

	for (i = 0; i < 1000000; ++i) {				// Inserts several numbers into each DA object
		insertDA(secondItems, newINTEGER(i));
	}
	
	for (i = 0; i < 1000000; ++i) {
		insertDA(items, newINTEGER(i));
	}
	for (i = 0; i < 1000000; ++i) {
		insertDA(thirdItems, newREAL(i * 3.14));
	}
	for (i = 0; i < 1000000; ++i) {
		insertDA(fourthItems, newREAL(i * 2.718281828));
	}
	printf("First items are now:\n");			// Displays objects and their sizes
	showItems(secondItems);
	visualizeCall(secondItems);
	sizeCall(secondItems);
	printf("Second items are now:\n");
	showItems(items);
	visualizeCall(items);
	sizeCall(items);
	printf("Third items are now:\n");
	showItems(thirdItems);
	visualizeCall(thirdItems);
	printf("Fourth items are now:\n");
	showItems(fourthItems);
	visualizeCall(fourthItems);
	
	printf("UNION!\n");					// Unions first and second DA items
	
	unionDA(secondItems, items);
	printf("First items are now:\n");
	showItems(secondItems);
	visualizeCall(secondItems);
	sizeCall(secondItems);
	printf("Second items are now:\n");
	showItems(items);
	visualizeCall(items);
	sizeCall(items);
								// Tests get and set methods for first and second DA objects
	int x = getINTEGER((INTEGER *) getDA(secondItems, 999));
	printf("The 1000 item is %d\n", x);
	setDA(secondItems, 999, newINTEGER(42));
  	printf("After set:\n");
	x = getINTEGER((INTEGER *) getDA(secondItems, 999));
	printf("%d\n", x);
	printf("extractDA method call:\n");
	extractDA(items);					// Tests extract method for first DA object
	if (extractDA(items) == NULL) {
		printf("Extracted on an empty array. Returned pointer to 0.\n");
	}
  	printf("Recipient after extracting:\n");
	showItems(items);					// Prints details of first DA object again
	visualizeCall(items);
	sizeCall(items);
	int size = sizeDA(secondItems);
	printf("Removing items from other array:\n");		// Removes from remaining  DA object
	for (i = 0; i < size; ++i) {
		removeDA(secondItems);
	}

	printf("First items are now:\n");
	showItems(secondItems);
	visualizeCall(secondItems);
	sizeCall(secondItems);

	printf("Union on two empty arrays:\n");			// Repeats above tests for third and fourth arrays
	unionDA(secondItems, items);
	printf("First items are now:\n");
	showItems(secondItems);
	visualizeCall(secondItems);
	sizeCall(secondItems);
	printf("Second items are now:\n");
	showItems(items);
	visualizeCall(items);
	sizeCall(items);
	
	printf("UNION!\n");
	
	unionDA(thirdItems, fourthItems);
	printf("Third items are now:\n");
	showItems(thirdItems);
	visualizeCall(thirdItems);
	sizeCall(thirdItems);
	printf("Fourth items are now:\n");
	showItems(fourthItems);
	visualizeCall(fourthItems);
	sizeCall(fourthItems);

	double z = getINTEGER((INTEGER *) getDA(thirdItems, 999));
	printf("The 1000 item is %lf\n", z);
	setDA(thirdItems, 999, newREAL(1.689));
  	printf("After set:\n");
	z = getREAL((REAL *) getDA(thirdItems, 999));
	printf("%lf\n", z);
	printf("extractDA method call:\n");
	extractDA(fourthItems);
	if (extractDA(fourthItems) == NULL) {
		printf("Extracted on an empty array. Returned pointer to 0.\n");
	}
  	printf("Recipient after extracting:\n");
	showItems(fourthItems);
	visualizeCall(fourthItems);
	sizeCall(fourthItems);
	int doubleSize = sizeDA(thirdItems);
	printf("Removing items from other array:\n");
	for (i = 0; i < doubleSize; ++i) {
		removeDA(thirdItems);
	}

	printf("First items are now:\n");
	showItems(thirdItems);
	visualizeCall(thirdItems);
	sizeCall(thirdItems);

	printf("Union on two empty arrays:\n");
	unionDA(thirdItems, fourthItems);
	printf("Third items are now:\n");
	showItems(thirdItems);
	visualizeCall(thirdItems);
	sizeCall(thirdItems);
	printf("Fourth items are now:\n");
	showItems(fourthItems);
	visualizeCall(fourthItems);
	sizeCall(fourthItems);

	return 0;
}





