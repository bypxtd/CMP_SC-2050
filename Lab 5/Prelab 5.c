// name: bruce y phommaly
// pawprint: bypxtd
// date: 03/03/16
// assignment: prelab 5
// purpose: structs, enums, files, malloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	PENNY = 1,
	NICKEL = 5,
	DIME = 10,
	QUARTER = 25,
} Denomination;

typedef struct {
	Denomination denomination;
	int quantity;
} Coin;

typedef Coin* PiggyBank;

PiggyBank loadBank(const char* filename, int* lenPtr);
int totalMoney(PiggyBank bank, int length);

/*
* Main will open the input file and should call
* loadBank and then find the total amount of
* money.
*/
int main(int argc, char* argv[])
{
	int i, length;
	PiggyBank piggybank = loadBank(argv[1], &length);
	
	for(i = 0; i < length; i++)
	{
		printf("%d %d\n", piggybank[i].denomination, piggybank[i].quantity);
	}
	
	totalMoney(piggybank, length);
	//printf("You have %d cents\n", total);

	return 0;
}

/*
* Parameters:
* filename - The name of an input file
* lenPtr - A pointer to an int where the length of the array will be stored
*
* Return:
* A PiggyBank (an array of coins)
*
* This function will read a list of coins into a PiggyBank.
* The first line is the number of records in the array.
* The rest of the lines will contain two numbers, the number
* type of coin in cents and the second is the quantity.
* An example file is below.
*/
PiggyBank loadBank(const char* filename, int* lenPtr)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File could not be opened\n");
        *lenPtr = 0;
        return NULL;
    }

    fscanf(fp, "%d", lenPtr);
   // printf("%d\n", *lenPtr);
    PiggyBank piggyBank = malloc(sizeof(Coin) * (*lenPtr));

    int i;
    for (i = 0; i < *lenPtr; i++) {
        fscanf(fp,"%u %d", &piggyBank[i].denomination, &piggyBank[i].quantity);
    }
    return piggyBank;
    fclose(fp);
}

/*
* Parameters:
* bank - An array of coins
* length - The length of the array
*
* Return:
* The total number of cents in the bank
*/
int totalMoney(PiggyBank bank, int length)
{
	int total;
		
	total = (bank[0].denomination * bank[0].quantity) +
		(bank[1].denomination * bank[1].quantity) +
		(bank[2].denomination * bank[2].quantity) +
		(bank[3].denomination * bank[3].quantity);	
	
	
	printf("You have %d cents\n", total);
	return total;
}
