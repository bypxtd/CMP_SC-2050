// name: Bruce Y Phommaly
// pawprint: bypxtd
// date: 02/25/16
// assignment: lab 4
// purpose: GDB and debugging

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {
	PaperBack,
	HardBack,
} Type;

typedef struct book {
	char* name;
	char* author;
	int rating;
	Type type;
} Book;

typedef Book* Library;

Library loadLibrary(const char* filename, int* lenPtr);
void sortLibrary(Library library,  int length);
void printLibrary(Library library, int length);
void writeLibrary(Library library, int length, const char* filename);

/*
* Main will load all the students in the
* given class, sort them by gpa, print them
* to the screen and write them to another
* binary file.
* Above comments are comments on the handout (?)
*/
int main(int argc, char* argv[]) {
	if (argc < 3) {
		printf("Incorrect Usage\n");
		printf("%s <input file> <output file>\n", argv[0]);
		return 0;
	}

	int *length;
	Library library = loadLibrary(argv[1], length);
	
	sortLibrary(library, *length);
	printLibrary(library, *length);
	writeLibrary(library, *length, argv[0]);

	free(library);
	
	int i;
	for (i = 0; i < *length; i++)
	{ 
		free(library[i].name);
		free(library[i].author);
	}

	return 0;
}

/*
* Parameters:
* filename - A file containing books
* lenPtr - A pointer to a stack allocated int
*	that will store the length of the array
*
* Return: 
* An array of books
*/
Library loadLibrary(const char* filename, int* lenPtr) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Failed to open file %s\n", filename);
		*lenPtr = 0;
		return NULL;
	}

	fscanf(fp, "%d", lenPtr);
	Library library = malloc(sizeof(Book) * (*lenPtr));

	int i;
	for (i = 0; i < *lenPtr; i++) {
	//	library[i].name = malloc(sizeof(char));
		fscanf(fp, "%s %s %d %u", library[i].name, library[i].author, &library[i].rating, &library[i].type);
	}

	return library;
	fclose(fp);
}

/*
* Parameters:
* library - An array of books
* length - The length of the array
*
* Return: None
*
* Sorts the books based on their rating using insertion sort
*/
void sortLibrary(Library library,  int length) {
	int i;

	for (i = 1; i < length; i++) {
		int j = i;
		while (j > 0 && library[j].rating < library[j - 1].rating); {
			Book temp = library[j];
			library[j] = library[j - 1];
			library[j - 1] = temp;
		}
	}
}

/*
* Parameters: 
* library - An array of books
* length - The length of the array
*
* Return: None
*
* Prints the books to the screen.
* The enum will be converted to a string
*/
void printLibrary(Library library, int length) {
	int i;

	for (i = 0; i < length; i++) {
		printf("%s %s %d", library[i].name, library[i].author, library[i].rating);
		if ((library[i].type = PaperBack)) {
			printf(" PaperBack\n");
		} else {
			printf(" HardBack\n");
		}
	}
}

/*
* Parameters:
* library - An array of books
* length - The length of the array
* filenames - The name of the output file
*
* Return: None
*
* Prints the books to a file
*/
void writeLibrary(Library library, int length, const char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		return ;
	}

	fprintf(fp, "%d\n", length);

	int i;
	for (i = 0; i < length; i++) {
		fprintf(fp, "%s %s %d %d\n", library[i].name, library[i].author, library[i].rating, library[i].type);
	}

	fclose(fp);
}

