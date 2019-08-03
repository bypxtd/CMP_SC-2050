// name: 
// pawprint:
// date: 
// assignment: lab 6
// purpose: linked lists

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct node_ {
	int data;
	struct node_* next;
} Node;

Node* build_list(const char* filename);
void print_list(Node* head);
void multiply_by(Node* head, int val);
void free_list(Node* head);
Node* reverse_list(Node* head);

/*
* Main will take in an input file
* as a command line argument and
* build a linked list from it.
*
* It will then print it out,
* multiply it by some value,
* print it out again, possibly
* reverse it and then free the list.
*/
int main(int argc, char* argv[])
{
	const char* filename = "lab6input.txt";
	int val;

	Node* head = build_list(filename);
	print_list(head);
	multiply_by(head, val);
	print_list(head);
	free_list(head);

  	reverse_list(head);
	print_list(head);
}

/*
* Parameters:
* filename - The name of an input file
*
* Return: The head of a linked list
*
* This function will build a linked list
* from the numbers in the input file.
* Each number will be inserted into
* the head of the list.
*/
Node* build_list(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	Node *new = NULL;
	Node *head = NULL;
	Node *current = NULL;

	if(fp == NULL)
	{
		printf("Unable to open the file\n");
	}
	else
	{
		while(!feof(fp))
		{
			new = malloc(sizeof(Node));
			fscanf(fp, "%d", *new);
	
			if(head == NULL)
			{
				head = new;
				current = new;
			}
			else
			{
				new->next = head;
				head = new;
			}
		}
	}
	fclose(fp);
	return head;
}

/*
* Parameters:
* head - The head of a valid linked list
* 
* Return: None
*
* Prints the data in each element of the linked list
*/
void print_list(Node* head)
{
	while(head != NULL)
	{
		printf("%d ", head->data);
		printf("-> ");
		head = head->next;
	}
	printf("NULL");
	printf("\n");
}

/*
* Parameters:
* head - The head of a valid linked list
* val - A value to multiply by
*
* Return: None
*
* Takes each node and multiplys its value
* by val.
*/
void multiply_by(Node* head, int val)
{
	printf("Enter a number to multiply by: ");
	scanf("%d", &val);

	while(head != NULL)
	{
		head->data = head->data * val;	
		head = head->next;
	}
}
/*
* Parameters:
* head - The head of a valid linked list
*
* Return: None
*
* Free each node in the linked list
*/
void free_list(Node* head)
{
	Node* temp;
	while((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}	
}

/*
* Bonus!
* Parameters:
* head - The head of a valid linked lists
*
* Return: The new head of the linked list
*
*
* This function will reverse the node in
* the linked list.
*/
Node* reverse_list(Node* head)
{	
	Node* tail = NULL;
	Node* temp;

	printf("\nBonus\n");
	while(head != NULL)
	{
		temp = head->next;
		head->next = tail;
		tail = head;
		head = temp;		
	}
return tail;
}
