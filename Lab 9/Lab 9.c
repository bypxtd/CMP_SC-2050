// name: bruce y phommaly
// pawprint: bypxtd
// date: 04/14/2016
// assignment: lab 9
// purpose: binary search tree's

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define size 10

typedef struct node_ {
        int data;
        struct node_* left;
        struct node_* right;
} Node;

void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);
Node* buildBalancedTree(int array[], int low, int high);
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);
void freeTree(Node* root);
int height(Node* root);
void printEveryPath(Node* root, int* path, int depth);

/*
 * Main will:
 *
 * 1) fill an array with 10 random values
 * 2) sort the array using quicksort
 * 3) build a balanced tree
 * 4) print the height of the tree
 * 5) print out the tree using each of the traversals
 * 6) free the tree
 */
int main(int argc, char* argv[]) 
{
	int i = 0, array[size];
	int* path;
	
	srand(time(NULL));
	for(i = 0; i < size; i++)
	{
		array[i] = rand()%100;
	}

	quicksort(array, 0, 9);

        Node* root = buildBalancedTree(array, 0, 9);	
	
        printf("The height of the tree: %d", height(root));
        printf("\n");

        printf("Pre-Order: ");
        preorder(root);
        printf("\n");

        printf("In-Order: ");
        inorder(root);
        printf("\n");

        printf("Post-Order: ");
        postorder(root);
        printf("\n");

	printf("Bonus\n");
	printEveryPath(root, path, 0);

	freeTree(root);

        return 0;
}

/*
 * Parameters:
 * array - An array of ints
 * low - The lowest valid index in the array
 * high - The highest valid index in the array
 *
 * Return:
 * None
 *
 * Standard quicksort
 */
void quicksort(int array[], int low, int high)
{
   int j;

   if( low < high ) 
   {
       j = partition( array, low, high);
       quicksort( array, low, j-1);
       quicksort( array, j+1, high);
   }
}

int partition(int array[], int low, int high)
{
   int pivot, i, j, t;
   pivot = array[low];
   i = low; 
   j = high + 1;
		
   while(1)
   {
   	do ++i; 
		while( array[i] <= pivot && i <= high );
   	do --j; 
		while( array[j] > pivot );
   	if( i >= j ) 
		break;

   	t = array[i]; 
	array[i] = array[j]; 
	array[j] = t;
   }
   
   t = array[low]; 
   array[low] = array[j]; 
   array[j] = t;

   return j;
}
/*
 * Parameters:
 * array - A sorted array
 * low   - The lowest valid index in the array
 * high  - The highest valid index in the array
 *
 * Return:
 * A perfectly balanced BST
 *
 * This function will build a balanced
 * binary search tree from the sorted
 * array. The tree will be build in
 * binary search order. I recommend you
 * look at binary search for inspiration.
 */
Node* buildBalancedTree(int array[], int low, int high)
{
        int mid;
	Node* temp = (Node*)malloc(sizeof(Node));

        if(low > high)
                return NULL;

        mid = (low + high) / 2;

        temp->data = (array[mid]);
        temp->left = buildBalancedTree(array, low, mid - 1);
        temp->right = buildBalancedTree(array, mid + 1, high);

        return temp;
}

/*
 * Parameters:
 * root - The root of a BST
 *
 * Return:
 * None
 *
 * Prints the nodes of the
 * tree out using a preorder
 * traversal
 */
void preorder(Node* root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

/*
 * Parameters:
 * root - The root of a BST
 *
 * Return:
 * None
 *
 * Prints the nodes of the
 * tree out using a inorder
 * traversal
 */
void inorder(Node* root)
{
	if(root != NULL) 
	{	
		inorder(root->left);
        	printf("%d ", root->data);
      		inorder(root->right);
	}
}

/*
 * Parameters:
 * root - The root of a BST
 *
 * Return:
 * None
 *
 * Prints the nodes of the
 * tree out using a postorder
 * traversal
 */
void postorder(Node* root)
{
	if(root != NULL) 
	{
        	postorder(root->left);
        	postorder(root->right);
       	 	printf("%d ", root->data);
    	}
}

/*
 * Parameters:
 * root - The root of a BST
 *
 * Return:
 * None
 *
 * Free's every node in the
 * tree
 */
void freeTree(Node* root)
{
        if(root == NULL)
        return;

        freeTree(root->left);
        freeTree(root->right);
        free(root);
}

/*
 * Parameters:
 * root - The root of a BST
 *
 * Return:
 * The height of the tree
 *
 * Calculates the height of 
 * the tree. The height is
 * the longest path through
 * the tree.
 */
int height(Node* root)
{
    int left = 0;
    int right = 0;
     
    if(root == NULL)
    {
        return 0;
    }

    else
    {
        left = height(root->left);
        right = height(root->right);
        if( left > right || left == right)
        {
            return (left + 1);
        }
        else
        {
            return (right + 1);
        }
    }
}

/*
 * Parameters:
 * root - The root of a BST
 * path - The values along the current path
 * dpeth - The current depth of the tree
 *
 * Return:
 * None
 *
 * This function will print the path
 * from the root to leaf in the tree
 */
void printEveryPath(Node* root, int* path, int depth)
{
	if(root == NULL)
		return;
	
	path[depth] = root->data;
	depth++;
		
	if(root->left == NULL && root->right ==NULL)
	{
		int i;
		for(i = 0; i < depth; i++)
		{
			printf("%d ", path[i]);
		}
	printf("\n");
	}
	else
	{
		printEveryPath(root->left, path, depth);
		printEveryPath(root->right, path, depth);
	}
	
}

