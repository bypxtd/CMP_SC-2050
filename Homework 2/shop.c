#include "game.h"

Shop* loadShop()
{
}

void destroyShop(Shop* shop)
{
}


void sortShields(Shield** shields)
{
}

void sortSwords(Sword** swords)
{
}

void printShields(Shield* shields)
{
}

void printSwords(Sword* swords)
{
}

Sword* removeSwordFromList(Sword** swords, int choice)
{
}

Shield* removeShieldFromList(Shield** shields, int choice)
{
}

/***************************START OF FUNCTIONS GIVEN TO YOU**********************************/

void freeHeroesAndItems(Hero* heroes)
{
	int i;
	for(i = 0; i < NUMCHOSENHEROES; i++)
	{
		if(heroes[i].heroSword != NULL)
		{
			free(heroes[i].heroSword);
		}
		if(heroes[i].heroShield != NULL)
		{
			free(heroes[i].heroShield);
		}
	}
	free(heroes);
}

void goShopping(Hero* heroes, Shop* shop)
{

	printf("\n\nNow, you will select a sword and shield for your heroes.\n");

	int firstPass = 1; 

	int bank = STARTINGBANKVALUE;

	while(1)
	{
		printf("Which would you like to look at?\n");
		printf("1: Swords\n2: Shields\n3: Continue to fight\n");
		printf("> ");
		int choice; 
		scanf("%d", &choice);
		while(choice < 1 || choice > 3)
		{
			printf("Invalid choice. Select again: \n");
			printf("> ");
			scanf("%d", &choice);
		}

		if(choice == 3)
		{
			if(firstPass == 1)
			{
				printf("Are you sure you don't want to buy anything?\n");
				printf("1: yes\n2: no\n");
				printf("> ");
				scanf("%d", &choice);
				while(choice < 1 || choice > 2)
				{
					printf("Invalid choice. Select again: \n");
					printf("> ");
					scanf("%d", &choice);
				}
			}
			else
			{
				choice = 1;
			}

			if(choice == 1)
			{
				destroyShop(shop);
				return;
			}
		}
		else if(choice == 2)
		{
			printf("Do you want it sorted (1) or unsorted? (2)\n");
			printf(">");
			int sortChoice;
			scanf("%d", &sortChoice);
			while(sortChoice != 1 && sortChoice != 2)
			{
				printf("Invalid choice, choose again: ");
				printf(">");
				scanf("%d", &sortChoice);
			}

			if(sortChoice == 1)
			{
				sortShields(&(shop->headShield));
			}
			

			while(1)
			{
				printShields(shop->headShield);
				
				while(1)
				{
					printf("\nBudget: %d\n", bank);
					printf("Select a shield (-1 to go back): \n");
					printf("> ");
					scanf("%d", &choice);
	
					while((choice < 1 || choice > NUMSHIELDS) && choice != -1)
					{
						printf("Invalid choice. Select again: \n");
						printf("> ");
						scanf("%d", &choice);
					}
				
					if(choice != -1)
					{
						if(findShieldPrice(shop->headShield, choice) > bank)
						{
							printf("You don't have enough money for that!\n");
						}
						else break;
					}
					else break;
				}

				if(choice == -1)
				{
					break;
				}
				else
				{
					int heroChoice; 

					while(1)
					{
						printHeroes(heroes, NUMCHOSENHEROES);
						printf("Which hero do you want to have the item? (-1 to go back): \n");
						printf("> ");
						scanf("%d", &heroChoice);

						while((heroChoice < 1 || heroChoice > NUMCHOSENHEROES) && heroChoice != -1)
						{
							printf("Invalid choice. Select again: \n");
							printf("> ");
							scanf("%d", &heroChoice);
						}

						if(heroChoice == -1)
						{
							break;
						}

						if(heroes[heroChoice - 1].heroShield != NULL)
						{
							printf("That hero already has a shield. Choose again.\n");
						}
						else
						{
							break;
						}

					}
					

					if(heroChoice == -1)
					{
						break;
					}
					else
					{
						Shield* item = removeShieldFromList(&(shop->headShield), choice);
						heroes[heroChoice - 1].heroShield = item;
						bank -= item->cost;
						firstPass = 0;
					}
				}
			}
		}
		else if(choice == 1)
		{
			printf("Do you want it sorted (1) or unsorted? (2)\n");
			printf(">");
			int sortChoice;
			scanf("%d", &sortChoice);
			while(sortChoice != 1 && sortChoice != 2)
			{
				printf("Invalid choice, choose again: ");
				printf(">");
				scanf("%d", &sortChoice);
			}

			if(sortChoice == 1)
			{
				sortSwords(&(shop->headSword));
			}
			
			while(1)
			{
				printSwords(shop->headSword);
				
				while(1)
				{
					printf("\nBudget: %d\n", bank);
					printf("Select a sword (-1 to go back): \n");
					printf("> ");
					scanf("%d", &choice);
	
					while((choice < 1 || choice > NUMSWORDS) && choice != -1)
					{
						printf("Invalid choice. Select again: \n");
						printf("> ");
						scanf("%d", &choice);
					}
				
					if(choice != -1)
					{
						if(findSwordPrice(shop->headSword, choice) > bank)
						{
							printf("You don't have enough money for that!\n");
						}
						else break;
					}
					else break;
				}

				if(choice == -1)
				{
					break;
				}
				else
				{
					int heroChoice; 

					while(1)
					{
						printHeroes(heroes, NUMCHOSENHEROES);
						printf("Which hero do you want to have the item? (-1 to go back): \n");
						printf("> ");
						scanf("%d", &heroChoice);

						while((heroChoice < 1 || heroChoice > NUMCHOSENHEROES) && heroChoice != -1)
						{
							printf("Invalid choice. Select again: \n");
							printf("> ");
							scanf("%d", &heroChoice);
						}

						if(heroChoice == -1)
						{
							break;
						}

						if(heroes[heroChoice - 1].heroSword != NULL)
						{
							printf("That hero already has a sword. Choose again.\n");
						}
						else
						{
							break;
						}
					}
					if(heroChoice == -1)
					{
						break;
					}
					else
					{
						Sword* item = removeSwordFromList(&(shop->headSword), choice);
						heroes[heroChoice - 1].heroSword = item;
						bank -= item->cost;
						firstPass = 0;
					}
				}
			}
		}
	}
}

int findSwordPrice(Sword* swords, int choice)
{
	int i = 1;
	while(i < choice)
	{
		swords = swords->nextSword;
		i++;
	}
	return swords->cost;
}

int findShieldPrice(Shield* shields, int choice)
{
	int i = 1;
	while(i < choice)
	{
		shields = shields->nextShield;
		i++;
	}
	return shields->cost;
}