/**********************************************************************
Program: Daily 7
Author: Saema Nazar
Date: 10/7/19
Time spent: 4 days
Purpose: The purpose of this program is to take n number of string inputs from 
		the keyboard (made up of parenthesis characters) and determine 
		whether the string is correct or incorrect. This is done using stack 
		interface.
***********************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"


int main(int argc, char* argv[]) 
{

	int i = 0;
	int numStr = 0;
	char str[2500];
	char tempChar[2];
	int correctVal = 0;

	printf("Enter # of strings: \n");
	scanf("%d", &numStr);
	fgets(tempChar, 2, stdin);	//reads \n character after numStr is entered
	printf("Enter strings:\n");


	for (i = 0; i < numStr; i++)
	{
		fgets(str, 2500, stdin);

		correctVal = isCorrect(str);

		if (correctVal == 1) 
		{
			printf("Yes\n");
		}
	
		else {

			printf("No\n");
		}		

	}

	return 0;
} 