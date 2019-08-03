//Name: Bruce Y Phommaly

//Description: Lab 1 - review of CS 1050 (variables, function calls, file I/O, and arrays)

//Date: 01/28/16

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

double* read_file(char* filename, int length);
double find_min(double* array, int length);
double find_max(double* array, int length);
double find_avg(double* array, int length);
void write_to_file(char* filename, double* array, int length);
/*void print_data(double* array, int length);*/

/*
* Main will read in three command line arguments:
* - The number of items in the input file
* - The name of the input file
* - The name of the output file
*
* Main will read in the command line arguments,
* call the other functions and print their
* results to the screen. Main should be the
* only function to call printf.
*/
int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("\nInsufficient arguments\n");
		return 0;
	}
	
	int n = atoi(argv[2]);

	int length;
	double *array;
	
	double size = read_file(argv[1], length);

	if(size == 0)
	{
		printf("\nUnable to open the input file\n");
		return 0;
	}
	
	int minimum = find_min(array, length);
	printf("\nThe smallest value in the array is %f\n", (array));
	
	int maximum = find_max(array, length);
	printf("\nThe largest value in the array is %f\n", (array));
	
	int average = find_avg(array, length);
	printf("\nThe average value in the array is %f\n", (array));
	
	write_to_file(argv[3], array, length);

	free(array);
	free(&length);	
}

/*
* Parameters:
* filename - The name of the input file
* length - The number of items in the input file
*
* Return:
* An array of doubles with 'length' number of elements,
* NULL if the file failed to open
*/
double* read_file(char* filename, int length)
{
	double *array;

	FILE *file = fopen("filename", "r");
	
	if(file == NULL)
	{
		return 0;
	}

	fscanf(file, "%d", &length);
	int i = 0;
	for(i = 0; i < length; i++)
	{
		fscanf(file, "%d", &array[i]); 
	}
	fclose(file);
	return (&array[length]);
}

/*
* Parameters:
* array - An array of doubles
* length - The size of the array
*
* Return: None
*
void print_data(double* array, int length)
{
	int i = 0;
	for(i = 0; i < length; i++)
	{
}
*/

/*
* Parameters:
* array - An array of doubles
* length - The size of the array
*
* Return:
* The smallest value in the array
*/
double find_min(double* array, int length)
{
	int i = 0, min = *array;
	
	for(i = 0; i < length; i++)
	{
		if((array[i]) < min)
		{
			min = (array[i]);
		}
	}
	return min;
}

/*
* Parameters:
* array - An array of doubles
* length - The length of the array
* 
* Return: 
* The largest value in the array
*/
double find_max(double* array, int length)
{
	int i = 0, max = 0;

	for(i = 0; i < length; i++)
	{
		if((array[i]) > max)
		{
			max = (array[i]);
		}
	}
	return max;
}

/*
* Parameters:
* array - An array of doubles
* length - The length of the array
*
* Return:
* The average of all the elements in the array
*/
double find_avg(double* array, int length)
{
	float average = 0;
	int i = 0;
	
	for(i = 0; i < length; i++)
	{
		average += (array[i]);
	}
	return average / length;
}

/*
* Parameters:
* filename - The name of the output file to write to
* array - An array of doubles
* length - The length of the array
*
* Return: None
*
* This function will write the values of the array to the file backwards. So the last item at
* array [length - 1] will be the first number written to the file, array [length - 2] the second, etc.
*/
void write_to_file(char* filename, double* array, int length)
{
	int i = 0;
	FILE* file = fopen(filename, "w");

	for(i = 0; i < length; i++)
	{
		fprintf(file, "%d\n", (array[length - i]));
	}
	fclose(file);
}

























