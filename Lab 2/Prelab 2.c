// Prelab 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
	char* name;
	int rating;
	int numTimesPlayed;
} Song;

// The largest valid size of a song name
#define MAXNAMESIZE 20

Song* readAlbum(const char* filename, int* lenPtr);
void printAlbum(Song* album, int len);

/*
* Main will read in the input file as a command line
* argument, call readAlbum and then call printAlbum.
*/
int main(int argc, char* argv[])
{
	int lenPtr;
	
	if(argc != 2)
	{
		return 0;
	}

	readAlbum(argv[1], &lenPtr);
	Song* readAlbum;
	printAlbum(readAlbum, 3);
	return 0;
}

/*
* Parameters:
* filename - The name of the input file
* lenPtr - A pointer to a stack allocated
* int that will store the length of the array
*
* Return:
* Null if the line failed to open,
* otherwise a pointer to the beginning of
* malloced array of Song structs
*
* readAlbum will attempt to read a list of songs from 
* a file. The first line of the file will be the number
* of songs it contains.
*/
Song* readAlbum(const char* filename, int* lenPtr)
{
	int i;
	Song* album = malloc(sizeof(Song)*(*lenPtr));
	char* temp;
	FILE *file = fopen(filename, "r");
	if(file == NULL)
	{	
		printf("\nFailed to open\n");
		return NULL;
	}

	fscanf(file, "%d", lenPtr);
	for(i = 0; i < *lenPtr; i++)
	{
		temp = (char*)malloc((*lenPtr) * sizeof(char));
		fscanf(file, "%s %d %d", album[i].name, &album[i].rating, &album[i].numTimesPlayed);
	}
	fclose(file);

	return album;
}

/*
* Parameters:
* album - A pointer to an array of Song structs
* len - The length of the array
*
* Return:
* None
*
* Prints each song in the array
*/
void printAlbum(Song* album, int len)
{
	int i = 0;
	for(i = 0; i < len; i++)
	{
		printf("%s %d %d\n", album[i].name, album[i].rating, album[i].numTimesPlayed);
	}
}
