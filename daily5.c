/***********************************************************
				///////////////////DAILY 5 RESUBMISSION ////////////////////
Author: Saema Nazar
Date: 9/17/19
Effort: 4 hours
Purpose: this program should set, unset, check, and display flags in an array of integers. 
		There should be 8 columns and 10 rows of flags displayed.
************************************************************/
#include <stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[])
{
	unsigned int flag_holder[5] = { 0 };

	set_flag(flag_holder, 3);
	set_flag(flag_holder, 16);
	set_flag(flag_holder, 31);
	set_flag(flag_holder, 87);
	
	display_flags(flag_holder, 5);
	
	printf("\n\n");
	
	unset_flag(flag_holder, 31);
	unset_flag(flag_holder, 3);
	set_flag(flag_holder, 99);
	set_flag(flag_holder, 100);
	
	display_flags(flag_holder, 5);

	return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
{
	int i = flag_position / 32;	//index of flag being set
	int leftShift = 1 << (flag_position % 32);	//shift 1 to location of bit being set

	flag_holder[i] = flag_holder[i] | leftShift;

}

int check_flag(unsigned int flag_holder[], int flag_position)			//return 1 if bit at flag_position is 1, and 0 if it is 0
{
	int i = flag_position / 32;
	int leftShift = 1 << (flag_position % 32);

	if ((flag_holder[i] & leftShift) == 0) {
		return 0;
	}
	else 
	 return 1; 
}
void display_32_flags_as_array(unsigned int flag_holder)
{
	int i = 0;
	for (i = 0; i <32; i++)
	{
		if (i % 4 == 0)
		{
			printf(" ");
		}

		printf("%d", check_flag(&flag_holder, i));
	}
	printf("\n");

}

void unset_flag(unsigned int flag_holder[], int flag_position)		////invert string using ~
{
	int i = flag_position / 32;
	int leftShift = 1 << (flag_position % 32);

	leftShift = ~(leftShift);
	flag_holder[i] = flag_holder[i] & leftShift;

}

void display_flags(unsigned int flag_holder[], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		display_32_flags_as_array(flag_holder[i]);
	}
}
