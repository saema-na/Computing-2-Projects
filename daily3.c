/***********************************************************
Author: Saema Nazar
Date: 9/14/19
Effort: 1-2 hours
Purpose: write definitions for set_flag and check_flag so that the output matches the one on the assignment sheet. Some bits were set to 1 using
		bitwise & shifting operators and then all bits were printed
***********************************************************/


#include <stdio.h>

void set_flag(int* flag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

int main(int argc, char* argv[])
{
	int flag_holder = 0;
	int i;

	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);

	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");

	return 0;
}

void set_flag(int* flag_holder, int flag_position)
{
	*flag_holder = *flag_holder | 1 << flag_position;		//setting flag_position-th bit of *flag_holder as 1
}

int check_flag(int flag_holder, int flag_position)			//return 1 if bit at flag_position is 1, and 0 if it is 0
{
	if (flag_holder & 1 << flag_position)
	{
		return 1;
	}

	else if (flag_holder & 0 << flag_position)
	{
		return 0;
	}

}
