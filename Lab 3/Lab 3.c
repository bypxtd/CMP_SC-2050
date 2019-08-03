// name: Bruce Y Phommaly
// date: 02/11/16
// assignment: lab 3
// purpose: structs and binary files

#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
        int id;
        char name[20];
        float gpa;
} Student;

Student findStudent(FILE* fp, int studentId);
Student* getClass(const char* classFile, const char* studentFile, int* len);
void bubbleSort(Student* students, int len);
void storeClass(const char* filename, Student* students, int len);
void printClass(Student* students, int len);

/*
* Main will load all the students in the
* given class, sort them by gpa, print them
* to the screen and write them to another
* binary file.
*/
int main(int argc, char* argv[])
{
        FILE *fp;
	const char *classFile, *studentFile, *filename;
        int studentId, len;
	int *len2;
	Student* students;
        if((fp = fopen("students.dat", "rb")) == NULL)
        {
                printf("\nFile could not be opened\n");
        }
        else
        {
                findStudent(fp, studentId);
		getClass(classFile, studentFile, len2);
		bubbleSort(students, len);
		printClass(students, len);
		storeClass(filename, students, len);
        }
        fclose(fp);
        return 0;
}

/*
* Parameters:
* fp - A file pointer to a file opened for reading binary
* studentId - The studentId to search for
*
* Return:
* A student struct with the information
* pertaining to the specified student.
*
* The given file contains 5000 students with id's from
* 1 to 5000 inclusive. Given a studentId you should read
* the specified student using fseek and fread. This
* function should not contain any loops.
*/
Student findStudent(FILE* fp, int studentId)
{
        Student* student = malloc(sizeof(Student));
        printf("\nEnter a studentId, or 0 to quit: ");
        scanf("%d", &studentId);

        while(studentId !=0)
        {
                fseek(fp, (studentId - 1) * sizeof(struct student), SEEK_SET);

                fread(student, sizeof(Student), 1, fp);
                printf("%s %.2f\n", student->name, student->gpa);

                printf("\nEnter a studentId, or 0 to quit: ");
                scanf("%d", &studentId);
        }
        return *student;
}

/*
* Parameters:
* classFile - The name of an input file text
* file containing student id's
* studentFile - The name of a binary file
* containing students
* lenPtr - A pointer to a stack allocated int
* that will store the length of the array
*
* Return:
* An array of students with the id's specified in the classFile
*/
Student* getClass(const char* classFile, const char* studentFile, int* len)
{
	int i;
	Student* students = malloc(sizeof(Student)*(*len));
	FILE *file = fopen("class.txt", "r");
	if(file == NULL)
	{
		printf("\nFile could not be opened\n");
	}
	else
	{
		//fscanf(file, "%d", len);
		for(i = 0; i < *len; i++)
		{	
			int temp;
			fscanf(file, "%d", &temp);
			//students[i].id = (char*)malloc((*len) * sizeof(char));
			//fscanf(file, "%d", &temp);

		//	students[i].id = malloc(sizeof(char) * (temp + 1));
			fscanf(file, "%s %f", students[i].name, &students[i].gpa); 
		}
	}
	fclose(file);
	free(students);
	return students;
}

/*
* Parameters:
* students - An array of student structs
* len - The length of the array
*
* Return: None
* 
* Sorts the students based on their gpa
*/
void bubbleSort(Student* students, int len)
{
	int temp;
	int x, y;
	for(x = 0; x < len; x++)
	{
		for(y = 0; y < len - 1; y++)
		{
			if(students[y].gpa > students[y + 1].gpa)
			{
				temp = students[y].gpa;
				students[y].gpa = students[y + 1].gpa;
				students[y + 1].gpa = temp;
			}
		}
	}
}

/*
* Parameters:
* filename - The name of the output binary file
* students - An array of student structs
* len - The length of the array
* 
* Return: None
*
* The functions will write the array of students to
* a specified binary file. NOTE: This function may
* not use any loops!
*
*/
void storeClass(const char* filename, Student* students, int len)
{
	FILE* file = fopen(filename, "wb");
	//while(!feof)
	//{
		fwrite(students, sizeof(Student), len, file);
	//}
	fclose(file);
}

/*
* Parameters:
* students - An array of student structs
* len- The length of the array
* 
* Return: None
*
* Prints the students out to the screen
*/
void printClass(Student* students, int len)
{
	int i;
	for(i = 0; i < len; i++)
	{
		printf("%d %s %f", students[i].id, students[i].name, students[i].gpa);
	}
}

