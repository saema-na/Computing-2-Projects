/***********************************************************
Author: Saema Nazar
Date: 9/16/19
Effort: 45 mins
Purpose: in addition to what was in daily 3, daily 4 has a function that displays the bits, and also a function
		that takes an integer and makes sure the nth bit is a 0
***********************************************************/

#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int* flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[])
{
	unsigned int flag_holder = 0;

	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);

	display_32_flags(flag_holder);


	unset_flag(&flag_holder, 31);
	unset_flag(&flag_holder, 3);
	set_flag(&flag_holder, 9);

	display_32_flags(flag_holder);


	return 0;
}

void set_flag(unsigned int* flag_holder, int flag_position)
{
	*flag_holder = *flag_holder | 1 << flag_position;		//setting flag_position-th bit of *flag_holder as 1
}

int check_flag(unsigned int flag_holder, int flag_position)			//return 1 if bit at flag_position is 1, and 0 if it is 0
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
void display_32_flags(unsigned int flag_holder){	int i = 0;	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");}
void unset_flag(unsigned int* flag_holder, int flag_position)
{
	*flag_holder &= ~(1 << flag_position);			//invert string using ~ then clear
}
