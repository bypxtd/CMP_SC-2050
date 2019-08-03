// prelab 3

#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	int id;
	char name[20];
	float gpa;
} Student;

Student findStudent(FILE* fp, int studentId);

/*
* Main will open the input file and should call 
* findStudent with several different studentId's
* and print out the resutls.
*/
int main(int argc, char* argv[])
{
	FILE *fp;
	int studentId;
	if((fp = fopen("students.dat", "rb")) == NULL)
	{
		printf("\nFile could not be opened\n");
	}
	else
	{
		findStudent(fp, studentId);
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
	printf("\nEnter a studentId: ");
	scanf("%d", &studentId);

    	while(studentId !=0)
    	{
    //      fread(student, sizeof(Student), 4, fp);
    //      printf("\n%s %f\n", student.name, &student.gpa);

    		fseek(fp, (studentId - 1) * sizeof(struct student), SEEK_SET);

    		fread(student, sizeof(Student), 1, fp);
    		printf("%s %f\n", student->name, student->gpa);

    		printf("\nEnter a studentId: ");
        	scanf("%d", &studentId);
        }
	return *student;
}
















