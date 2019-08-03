#include "game.h"
 
//Knock yourself out boys and girls. 
/*
 * Input: none
 * Retun: a fully imported boss
 *
 * This will be the controller for all the boss loading.
 * The boss will have states as if it is a hero,
 * but it will have a decision tree for it AI.
 * This tree will have nodes that have a health floor and health ceiling.
 * Having the boss's current health lie between those two values will 
 * determine if that node will be selected.
 * Once the appropriate node is found, a pointer inside the node will lead
 * to a linked list of decisions that the boss will take in order.
 */
Boss* loadBoss()
{
	FILE* bossFile = fopen("Boss.txt", "r");
     
	int i;
	int bossCounter = 1;
        Boss* boss = malloc(sizeof(Boss));
    	DecisionTreeNode* root;
    	ActionNode* newAction;
	boss->root = NULL;
 
      	for(i = 0; i < bossCounter; i++)
      	{
        	fscanf(bossFile, "%s |", boss[i].name);
         	fscanf(bossFile, "%d | %d | %d | %d", 
                &(boss[i].health), &(boss[i].baseDefense), &(boss[i].baseAttack),
                &(boss[i].baseSpeed));
         
        	(boss[i].maxHealth) = (boss[i].health);
        
        	while(!feof(bossFile))
        	{
			int x;
			int y;
            		root = (DecisionTreeNode*)malloc(sizeof(DecisionTreeNode));
            		root->left = NULL;
            		root->right = NULL;
            		root->FirstAction = NULL;

                        fscanf(bossFile, "%d | %d |", &(root->healthFloor), &(root->healthCeiling));
            		fscanf(bossFile, "%d", &x);
 
            		for(y = x; y > 0; y--)
            		{
                		newAction = (ActionNode*)malloc(sizeof(ActionNode));
                		newAction->next = NULL;

                		fscanf(bossFile, " %d", (int*)&(newAction->decision));
      
                		root->FirstAction = addActionToList(root->FirstAction, newAction);
                 
            		}

            	(boss->root) = addNodeToTree((boss->root), root);
		
        	}
      	}
    
	fclose(bossFile);
    	return boss;
}
 
/*
 * Input: the head of the linked list and the node to be added to the linked list
 * Return: the head of the linked list
 * 
 * This function is for the linked list that is connected to its
 * corresponding tree node.
 * Starting from the head of the list, 
 * it will tack on the new node at the end of the list each time it is called.
 */
ActionNode* addActionToList(ActionNode* front, ActionNode* newAction)
{
	if(front == NULL)
        {
            front = newAction;
        }
    	else
        {
		ActionNode* temp = front;
		while(temp->next != NULL)
		{
            		temp = temp->next;
		}

		temp->next = newAction; 
   	}

    	return front;
}
 
/*
 * Input: the root of the BST, and the node to be added to this tree
 * Return: the root of the BST
 * 
 * This function is for dealing with each of the nodes once the linked list
 * is built for it and attached.
 * Add the node to the tree as the same way you have built BSTs before.
 * Keep in mind that each node covers a range of values:
 * if the node's range is lower than the range of the root,
 * put it on the left side of the tree.
 * if the range is above the range of the root,
 * put it on the right side of the tree.
 */
DecisionTreeNode* addNodeToTree(DecisionTreeNode* root, DecisionTreeNode* newNode)
{
	if(root == NULL)
        {
		return newNode;
        }
       	else
	{
		if(root->healthFloor > newNode->healthCeiling)
        	{
            		root->left = addNodeToTree(root->left, newNode);
        	}
        	else 
        	{
            		root->right = addNodeToTree(root->right, newNode);        
        	}
    	}

    	return root;
}
 
/*
 * Input: the boss and the root of its BST
 * Return: the linked list that is found inside the node
 * that has the health range that contains the current health
 *
 * As described, search for the node in the BST that has the health range 
 * that contains the boss's current health.
 * Once found, return the head of the linked list found inside the node.
 */
ActionNode* fetchNewList(Boss* boss, DecisionTreeNode* root)
{
	if(boss == NULL)
        {
        	return NULL;
        }
    	if(boss->health <= root->healthCeiling && boss->health >= root->healthFloor)
    	{
		return root->FirstAction;
	}
        else if(boss->health < root->healthFloor)
        {
                return fetchNewList(boss, root->left);
	}
	else
	{
		return fetchNewList(boss, root->right);
   	}
}

/*
 * Input: the root of the boss's BST
 * Return: none
 *
 * Free the entire tree.
 * Remember: freeing the nodes isn't good enough.
 * Each node leads to a linked list, so you have to free that first.
 */
void freeBossTree(DecisionTreeNode* root)
{
    	if(root != NULL)
    	{
        	if(root->FirstAction != NULL)
        	{
            		freeActionListInNode(root->FirstAction);
        	}
        	else if(root->FirstAction == NULL)
        	{
            		freeBossTree(root->left);
            		freeBossTree(root->right);
            		free(root);
        	}
    	}
}
 
/*
 * Input: the head of the linked list connected to the tree node
 * Return: none
 *
 * Call this function in freeBossTree().
 * This will be used in conjuction to free the linked list connected to the node 
 * before freeing the node itself.
 */
void freeActionListInNode(ActionNode* head)
{
    	ActionNode* temp;
     
    	while(head != NULL)
    	{
        	temp = head;
        	head = head->next;
        	free(temp);
    	}
}
