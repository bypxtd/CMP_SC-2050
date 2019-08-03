// name: Bruce Y Phommaly
// date: 02/04/12
// assignment: lab 2
// purpose: structs, strings, malloc

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
int changeRating(char* title, int rating, Song* album, int len);
int listenToSong(char* title, Song* album, int len);

/*
* Main will read in the input file as a command line
* argument, call readAlbum and then call printAlbum.
* It will then ask the user if they want to listen
* to a song or change a rating and then call the
* appropriate function. If a song is updated it should
* be printed out to the console. This will continue until
* the user decides to quit.
*/
int main(int argc, char* argv[])
{
        int lenPtr;
	int option;
	int rating;
	char title;

        if(argc != 2)
        {
                return 0;
        }

        readAlbum(argv[1], &lenPtr);
        Song* readAlbum;
        printAlbum(readAlbum, 3);

	printf("\nEnter 1 to listen to a song\n");
	printf("\nEnter 2 to change a rating\n");
	printf("\nEnter 0 to quit\n");
	scanf("%d", &option);
	
	while(option != -1)
	{
		switch(option)
		{
			case 0: 
				printf("\nYou have quit.\n");
				return -1;
		
			case 1:
				listenToSong(&title, readAlbum, 3);
				break;
		
			case 2:
				changeRating(&title, rating, readAlbum, 3);
				break;
		}
	}
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
                if(temp == NULL)
                {
                        exit(0);
                }
                else
                {
                        fscanf(file, "%s %d %d", album[i].name, &album[i].rating, &album[i].numTimesPlayed);
                }
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

/* 
* Paramters:
* title - The titles of a song
* rating - The new rating
* album - An array of song structs
* len - The length of the array
*
* Return:
* The index of the song thats rating
* was updated, -1 if not found
*
* Finds the specified song and
* updates its rating.
*/
int changeRating(char* title, int rating, Song* album, int len)
{
        printf("\nEnter a title: ");
        scanf("%c", title);
	printf("\nEnter a rating: ");
	scanf("%d", &rating);

        if(strcmp(title, album[0].name) ==  0)
        {
		album[0].rating = rating;
                printf("%s %d %d\n", album[0].name, album[0].rating, album[0].numTimesPlayed);
       		return 0;
        }
        else
	//{
       		if(strcmp(title, album[1].name) == 0)
                {
			album[1].rating = rating;
                        printf("%s %d %d\n", album[1].name, album[1].rating, album[1].numTimesPlayed);
                        return 1;
                }
        // }
	        else
         	//{
	                if(strcmp(title, album[2].name) == 0)
                        {
				album[2].rating = rating;
                                printf("%s %d %d\n", album[2].name, album[2].rating, album[2].numTimesPlayed);
                                return 2;
                        }
         	//}
	                else
                        {
                                printf("\nUnable to find %s", title);
                                return -1;
                        }
	
}

/*
* Parameters:
* title - The name of a song
* album - An array of Song structs
* len - The length of the array
* 
* Return:
* The index of the song thats rating
* was updated, -1 if not found
*
* Finds the specified song and 
* increments its numTimesPlayed field 
* by one.
*/
int listenToSong(char* title, Song* album, int len)
{
	printf("\nEnter a title: ");
	scanf("%c", title);
	
	if(strcmp(title, album[0].name) ==  0)
	{
		printf("%s %d %d\n", album[0].name, album[0].rating, album[0].numTimesPlayed + 1);
		return 0;
	}
	else
	//{
		if(strcmp(title, album[1].name) == 0)
		{
			printf("%s %d %d\n", album[1].name, album[1].rating, album[1].numTimesPlayed + 1);
			return 1;
		}
	//}
		else
		//{
			if(strcmp(title, album[2].name) == 0)
			{
				printf("%s %d %d\n", album[2].name, album[2].rating, album[2].numTimesPlayed + 1);
				return 2;
			}
		//}
			else
			{
				printf("\nUnable to find %s", title);
				return -1;
			}
}
     
