// name: bruce y phommaly
// pawprint: bypxtd
// date: 04/07/16
// assignment: lab 8
// purpose: binary search tree

#include <stdlib.h>
#include <stdio.h>

typedef struct node_
{
        int data;
        struct node_* left;
        struct node_* right;
} Node;


void printTree(Node* root, int depth);
void padding(int depth);
Node* insert(Node* root, int data);
Node* buildTree(char * filename);
int min(Node* root);
Node* delete(Node* root, int data);
void freeTree(Node* root);
Node* flipTree(Node* root);
/*
 * Main will take in one command line argument,
 * the name of an input file. It will build a bst,
 * print it, delete a number and print it again.
 * Finally, it should free the entire tree.
 */
int main(int argc, char* argv[])
{
	int data;
        Node* root = buildTree(argv[1]);

	printf("The initial tree\n");
        printTree(root, 0);
	
	printf("\n\nEnter a number to delete: ");
        scanf("%d", &data);
// Error check number deletion option
/*
	while(data != root->data)
	{
		printf("Invalid number. Try again: ");
		scanf("%d", &data);
	}
*/
        printf("The tree without %d", data);
	printf("\n");
	delete(root, data);	
	printTree(root, 0);

	printf("\n\nBonus\n");
	flipTree(root);
	printTree(root, 0);
	freeTree(root);

        return 0;
}

/*
 * Parameters:
 * root - The root of a binary search tree
 * data - The data to be inserted
 *
 * Return:
 * A bst with the new data inserted
 *
 * The function will take the root of a valid
 * bst and will insert the data into the tree
 * int binary search order.
 */
Node* insert(Node* root, int data)
{
        if (root == NULL)
        {
                root = (Node *)malloc(sizeof(Node));
                root->data = data;
                return root;
        }

        if(data < root->data)
        {
                root->left = insert(root->left, data);
        }
        else
        {
                root->right = insert(root->right, data);
        }

        return root;
}

void padding(int depth)
{
        int i;
        for (i = 0; i < depth; i++) {
                putchar('\t');
        }
}

void printTree(Node* root, int depth)
{
        if (root == NULL) {
                padding(depth);
                printf("~\n");
        } else {
                printTree(root->right, depth + 1);
                padding(depth);
                printf("%d\n", root->data);
                printTree(root->left, depth + 1);
        }
}

/*
 * Parameters: 
 * filename - The name of an input file
 * 
 * Return:
 * A BST
 *
 * This function will open a file
 * and insert each value into a bst
 */
Node* buildTree(char* filename)
{     
    Node* node = NULL;
    Node* root = NULL;
   
    FILE* fp = fopen(filename, "r");
   
    while(!feof(fp))
    {
        node = malloc(sizeof(Node));
        fscanf(fp, "%d", &(node->data));
         
        node->left = NULL;
        node->right = NULL;
        root = insert(root, node->data);
         
    }

    fclose(fp);
    return root;
}



/*
 * Parameters:
 * root - The root of a bst
 * 
 * Return:
 * The smallest value in 
 * the tree
 */
int min(Node* root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}

	return(root->data);
}


/*
 * Parameters:
 * root - The root of a bst
 * data - A value to be deleted
 * 
 * Return:
 * The new root of the bst
 * 
 * This function will
 * delete the value specified
 * from the bst
 */
Node* delete(Node* root, int data)
{
/*
        printf("\n\nEnter a number to delete: ");
        scanf("%d", &data);
        printf("\nThe tree without %d", data);

	free(root);

        if (root == NULL)
        {
                root = (Node *)malloc(sizeof(Node));
                root->data = data;
                return root;
        }

        if(data < root->data)
        {
                root->left = insert(root->left, data);
        }
        else
        {
                root->right = insert(root->right, data);
        }
*/

	if(root == NULL)
	return root;

	if(data > root->data)
	{
		root->right = delete(root->right, data);
		return root;
	}

	if(data < root->data)
	{
		root->left = delete(root->left, data);
		return root;
	}

	if(data == root->data)
	{
		if(root->left == NULL)
		{
			Node* right = root->right;
			free(root);
			root = right;
			return root;
		}

		if(root->right == NULL)
		{
			Node* left = root->left;
			free(root);
			root = left;
			return root;
		}

		Node* m = root->right;
		root->data = m->data;
		root->right = delete(root->right, root->data);
		return root;
	}	

return root;
}


/*
 * Parameters:
 * root - The root of a bst
 * 
 * Return:
 * None
 *
 * This function will free
 * every node in the bst
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
 * Bonus
 */
Node* flipTree(Node* root)
{
	Node* temp = root->left;

	root->left = root->right;
	root->right = temp;

	if(root->left != NULL)
	flipTree(root->left);

	if(root->right != NULL)
	flipTree(root->right);

return root;
}
