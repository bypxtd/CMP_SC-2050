// name: bruce y phommaly
// pawprint: bypxtd
// date: 03/17/16
// assignment: lab 7
// purpose: data structures and queues

#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct node_ {
        int data;
        struct node_* next;
} Node;


Node* enqueue(Node* front, int data);
int dequeue(Node** frontPtr);
void printQueue(Node* front);
void freeQueue(Node* front);

/* 
* Main does not take in
* any command line arguments.
* It will offer the user 3 options:
* Enqueue, Dequeue, or Quit.
*
* If they select enqueue they will
* be prompted for a number to enqueue
* into the list. On dequeue the program
* will dequeue the next element and
* display it to the user. When they
* choose quit the program will free
* the remaining nodes in the queue
* before exiting.
*
*/
int main(void)
{
       // Node* queue = NULL;
        int option, i, data;
	int* p;
	Node *front;
	Node **frontPtr = &front;

	printf("Enter 1 to Enqueue\n");
	printf("Enter 2 to Dequeue\n");
	printf("Enter 3 to Quit\n");
	printf("> ");
	scanf("%d", &option);
	
	while(option != 3)
	{
		switch(option)
		{
			case 1:
				printf("Enter a number to enqueue: ");
				scanf("%d", &i);
				enqueue(front, data);
				p = malloc(sizeof(int));	
				*p = data;
				data = i;		
				printQueue(front);
				break;
			case 2:
				printf("%d was dequeued", dequeue(frontPtr));
				printQueue(front);
				break;
			case 3:
				break;			
        
		}
	}

	return 0;
}

/*
 * Parameters:
 * head - The current head of the queue
 * data - The data to be enqueued
 *
 * Return:
 * The new head of the queue
 *
 * The function will take in the head of
 * a queue and a new piece of data
 * and enqueue (insert at the end)
 * that data into the queue
 */
Node* enqueue(Node* front, int data)
{

    Node *new, *temp;

    new = malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    if (!front)
    {
        return new;
    }
    else
    {
        temp = front;
        while (temp->next)
        //{
                temp = temp->next;
                temp->next = new;
        //}
    }
    return front;
}

/*
* Parameters:
* frontPtr - A DOUBLE pointer to
* the front of a queue
*
* Return:
* The data stored in the node
* that was dequeued 
*
* This function will dequeue
* the next value from the queue
* and return it.
*/
int dequeue(Node** frontPtr)
{
	Node *head = (*frontPtr);
	(*frontPtr) = ((*frontPtr)->next);
	int value = head->data;

	free(head);
	return value;
}

/*
* Parameters:
* front - The front of a queue
*
* Return: None
*
* This function will print out 
* all the values in the queue.
*/
void printQueue(Node* front)
{
        while(front != NULL)
        {
                printf("%d ", front->data);
                printf("-> ");
                front = front->next;
        }
        printf("NULL");
        printf("\n");

}

/*
* Parameters:
* front - The front of a queue
*
* Return: None
*
* This function will free
* all nodes in the queue.
*/
void freeQueue(Node* front)
{
	if(front != NULL)
	{
		freeQueue(front->next);
		free(front);
	}
}
