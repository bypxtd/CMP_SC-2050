#include "game.h"

//If you haven't knocked yourself out in boss.c, do it here.
//Otherwise, knock yourself out again. 

/*
 * Input: a (already malloced) shield/sword, and the open file pointer
 * Return: none
 *
 * The file pointer passed into the function is pointing at the next line 
 * in the file to be read.
 * You will have to get that line and fill the shield/sword with its information.
 * DO NOT USE FSCANF
 */
void ParseShieldInfo(Shield* s, FILE* fp)
{
/*

	fp = fopen("Items.txt", "r");

        if(fp == NULL)
        {
                printf("Error opening file.\n");
        }

	int lineCounter = 0;
        char buf[100];
        Shield *currentShield = NULL;
        Shield *headShield = NULL;
        
        while((fgets(buf, sizeof(buf), fp)) != NULL)
        {                           
		Shield* t = (Shield*)malloc(sizeof(Shield));
           
            	sscanf(buf,"%[^|] | %d | %d | %[^\n]", t->name, &t->cost, &t->defense, t->description);
            	lineCounter++;
                            
            	if(lineCounter < 9)
            	{
                	if (headShield == NULL)
                	{
                    		headShield = t;
                    		currentShield = t;
                	}
                	else
                	{
                    		currentShield->nextShield = t;
                    		currentShield = t;
                    		currentShield->nextShield = NULL;
                	}
            	}
        }
                        
        *s = *headShield;

        // Print test
        
	int counter = 1;
	while(headShield != NULL)
        {
        // *s = *headSword;
                
		printf("\n%d - Name: %s \nCost: %d \nDefense: %d \nDescription: %s\n", counter, headShield->name, headShield->cost, headShield->defense, headShield->description);
        	counter++;
        	headShield = headShield->nextShield;
    	}
        
        fclose(fp);
*/

	char name[50];
	char cost[10];
	char defense[10];
	char description[50];
	char buff[100];

	fgets(buff, sizeof(buff), fp);
	sscanf(buff, "%[^|] | %[^|] | %[^|] | %[^\n]", name, cost, defense, description);

	strcpy(s->name, name);
	s->cost = atoi(cost);
	s->defense = atoi(defense);
	strcpy(s->description, description);
}

/*
 * Identical to ParseShieldInfo(), except attack value instead.
 */
void ParseSwordInfo(Sword* s, FILE* fp)
{
/*
	fp = fopen("Items.txt", "r");
	
	if(fp == NULL)
	{
		printf("Error opening file.\n");
	}

	char buf[100];
	int lineCounter = 0;
        Sword *currentSword = NULL;
        Sword *headSword = NULL;

        //if(s != NULL)
        //{
		while((fgets(buf, sizeof(buf), fp)) != NULL)
		{
                        Sword* t = (Sword*)malloc(sizeof(Sword));

			sscanf(buf,"%[^|] | %d | %d | %[^\n]", t->name, &t->cost, &t->attack, t->description);  
			lineCounter++;

	            	if(lineCounter > 8)
		    	{
                    		if (headSword == NULL)
                    		{
                        		headSword = t;
                        		currentSword = t;
                    		}
                    		else
                    		{
                        		currentSword->nextSword = t;
                        		currentSword = t;
                        		currentSword->nextSword = NULL;
                    		}
		    	}
		}

	*s = *headSword;
	
	//print test 
        
        int counter = 1;
        while(headSword != NULL)
        {
        // *s = *headSword;
                
        	printf("\n%d - Name: %s \nCost: %d \nDefense: %d \nDescription: %s\n", counter, headSword->name, headSword->cost, headSword->attack, headSword->description);
                counter++;
                headSword = headSword->nextSword;
	}
        
        fclose(fp);
*/

	char name[50];
        char cost[10];
        char attack[10];
        char description[50];
        char buff[100];

        fgets(buff, sizeof(buff), fp);
        sscanf(buff, "%[^|] | %[^|] | %[^|] | %[^\n]", name, cost, attack, description);

        strcpy(s->name, name);
        s->cost = atoi(cost);
        s->attack = atoi(attack);
        strcpy(s->description, description);   
}
