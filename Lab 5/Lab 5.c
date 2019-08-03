// name: bruce y phommaly
// pawprint: bypxtd
// date: 03/03/16
// assignment: lab 5
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
char* enumToString(Denomination denomination);
void printBankToScreen(PiggyBank bank, int length);
void sortByQuantity(PiggyBank bank, int length);
void writeToFile(const char* filename, PiggyBank bank, int length);

/*
* Main will read in two command line
* arguments: an input file and an
* output file. It will then load
* the bank, print it to the screen,
* sort it and then write it to a file.
*/
int main(int argc, char* argv[])
{
        int length;
        PiggyBank piggybank = loadBank(argv[1], &length);

	printBankToScreen(piggybank, length);

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
    PiggyBank piggyBank = malloc(sizeof(Coin) * (*lenPtr));

    int i;
    for (i = 0; i < *lenPtr; i++) {
        fscanf(fp,"%u %d", &piggyBank[i].denomination, &piggyBank[i].quantity);
    }
    return piggyBank;
    fclose(fp);
}

/*
* Parameter:
* denomination - A denomination
*
*Return: A string representation of the denomination
*
*/
char* enumToString(Denomination denomination)
{

        if ((denomination = PENNY))
        {
                return "Penny";
        }
        else if ((denomination = 5))
        {
                return "Nickel";
        }
        else if ((denomination = 10))
        {
                return "Dime";
        }
	else if ((denomination = 25))
	{
		return "Quarter";
	}
	else
	{
		return 0;
	}
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

        total = ((bank[0].denomination * bank[0].quantity) +
                (bank[1].denomination * bank[1].quantity) +
                (bank[2].denomination * bank[2].quantity) +
                (bank[3].denomination * bank[3].quantity));

        return (total);
}

/*
* Parameters:
* bank - An array of coins
* length - The length of the array
*
* Return: None
* This function will first print out the total amount of
* money the user has and then print out how many coins
* of each denomination.
*/

void printBankToScreen(PiggyBank bank, int length)
{
       // int i, denomination;
	int  total = totalMoney(bank, length);
	
	printf("You have %d cents in your piggy bank\n", total);

       // for(i = 0; i < length; i++)
       //{
       //	char *coin = (char*) malloc(length * sizeof(Coin));
       //        printf("%s %d\n", coin, bank[i].quantity);
       // }

	printf("penny %d\n", bank[0].quantity);
        printf("nickel %d\n", bank[1].quantity);
        printf("dime %d\n", bank[2].quantity);
        printf("quarter %d\n", bank[3].quantity);

}

/*
* Parameters:
* bank - An array of coins
* length - The length of the array
*
* Return: None
*
* Sorts the array using insertion sort based on 
* quantity
*/
void sortByQuantity(PiggyBank bank, int length)
{
	int i;

        for (i = 1; i < length; i++)
	{
                int j = i;
                while (j > 0 && bank[j].quantity < bank[j - 1].quantity); 
		{
                        Coin temp = bank[j];
                        bank[j] = bank[j - 1];
                        bank[j - 1] = temp;
                }
	}
}
/*        
* Parameters:
* filename - The name of the output file
* bank - An array of coins
* length - The length of the array
*
* Return: None
*
* Will print out the sorted bank to a file
*/
void writeToFile(const char* filename, PiggyBank bank, int length)
{
	sortByQuantity(bank, length);

        FILE* fp = fopen(filename, "w");
        if (fp == NULL) {
                return ;
        }

        fprintf(fp, "%d\n", length);

        int i;
        for (i = 0; i < length; i++) {
                fprintf(fp, "%d %d\n", bank[i].denomination, bank[i].quantity);
        }

        fclose(fp);
}

