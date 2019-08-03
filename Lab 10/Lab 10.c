// name: bruce y phommaly
// pawprint: bypxtd
// date: 04/21/16
// assignment: lab 10
// purpose: parsing

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int isDate(char* token);
int isPhoneNumber(char* token);
int isEmail(char* token);

/*
 * Main will open the specified message
 * and parse it word by word.
 * You should use
 * the function strtok to tokenize your
 * input and the only valid delimiters are
 * spaces, tabs, and newlines. It is up to
 * you to manually handle punctuation at the end
 * of a sentence.
 */
int main(int argc, char* argv[])
{
        //This is a valid phone number
   //     assert(isPhoneNumber("(123)456-7890") == 1);

        //These are not valid phone numbers
       // assert(isPhoneNumber("123-456-7890")    == 0);
       // assert(isPhoneNumber("1234567890")      == 0);
       // assert(isPhoneNumber("(123) 456-7890") == 0);
       // assert(isPhoneNumber("Hello World")     == 0);
       // assert(isPhoneNumber("")                                == 0);

        //printf("Congratulations! You finsihed the prelab!\n");
	

	FILE *fp = fopen("message.txt", "r");
	
	if(fp == NULL)
	{
		printf("File could not be opened\n");
	}

	char string[250];
	int numTokens = 0;

	while(fgets(string, sizeof(string), fp) != NULL)
	{
		if(string[(strlen(string)-1)] == '\n')
		{
			string[strlen(string)-1] = '\0'; 
		}

	char *token = "";
	token = strtok(string, " \t\n");
 
		while(token != NULL)
		{		
			numTokens++;
		
			if(isPhoneNumber(token))
			{
				printf("Phone Number: %s\n", token);
			}
			else if(isDate(token))
			{	
				printf("Date: %s\n", token);
			}
			else if(isEmail(token))
			{
				printf("E-mail: %s\n", token);
			}

			token = strtok(NULL, " \t\n"); //call strtok w/ NULL to get next token  
		}
	}

	fclose(fp);
	return 0;
}

/*
 * Parameters:
 * token - A string
 *
 * Return 1 if the string is a valid
 * date, 0 otherwise
 *
 * A valid date is XX/XX/XXXX
 * where X is a number.
 * You must also validate that they are numbers
 * a sensible, i.e., the month must be in 
 * the range 1-12 and the day cannot be less
 * than 1 or greater than the last day of
 * the specified month.
 *
 * Years must be after 2000.
 */
int isDate(char* token)
{
	if(strlen(token) == 11)
	{	
		if(*(token + 2) == '/' && *(token + 5) == '/')
		{
			int i;
			for (i = 0; i < 2; i++)
			{
				if(!isdigit(*(token + i)))
				{
					return 0;
				}
			}
			for (i = 3; i < 5; i++)
			{
				if (!isdigit(*(token + i)))
				{
					return 0;
				}
			}
			for (i = 6; i < 10; i++)
			{
				if (!isdigit(*(token + i)))
				{
					return 0;
				}
				if(*(token + 6) != '2')
				{
					return 0;
				}
			}
			
			if(*(token + 10) == '.')
			{
				*(token + 10) = ' ';
			}
		
			return 1;
		}

		return 0;
	}
	else
	{
		return 0;
	}
}

/*
* Parameters:
* token - A string
*
* Return:
* 1 if the string is a valid phone number,
* 0 otherwise
*
* A valid phone number takes the form
* (XXX)XXX-XXXX where X is a digit 0-9.
*/
int isPhoneNumber(char* token)
{
        if(*token == '(' && *(token + 4) == ')')
        {
                if(*(token + 8) == '-')
                {
                        int i;

                        for(i = 1; i < 4; i++)
                        {
                                if(!isdigit(*(token + i)))
                                {
                                        return 0;
                                }
                        }

                        for(i = 5; i < 8; i++)
                        {
                                if(!isdigit(*(token+i)))
                                {
                                        return 0;
                                }
                        }

                        for(i = 9; i < 13; i++)
                        {
                                if(!isdigit(*(token+i)))
                                {
                                        return 0;
                                }
                        }

                        return 1;
                }

                return 0;
        }

        else
        {
                return 0;
        }
}

/*
 * Parameters:
 * token: A string
 *
 * Return:
 * 1 if the string is an email,
 * 0 otherwise.
 * 
 * A valid is one or more alphanumeric characters
 * an '@' followed by more alphanumeric characters
 * and then '.com'
 */
int isEmail(char* token)
{
	int len = strlen(token);
	int x = 0;
	int y = 0;
	int i;

	for(i = 0; i < len; i++)
	{
		if(*(token+i) == '@')
		{
			x = i;
		}
		if(*(token+i) == '.')
		{
			y = i;
		}
	}

	if(x && y)
	{
		for(i = 0; i < x; i++)
		{
			if(!isalnum(*(token + i)))
			{
				return 0;
			}
		}
		for(i = (x + 1); i < y; i++)
		{
			if(!isalnum(*(token + i)))
			{
				return 0;
			}
		}

		char *post = (token + (y + 1));

		if(!strcmp(post, "com") || !strcmp(post, "edu"))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

}
