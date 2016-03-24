#include <stdio.h>
#include <stdlib.h>
#include "PA7_functions.h"

void choose_nums (int i, int n1, int n2, int n3, int n4, int*num1_ptr, int*num2_ptr, int*num3_ptr, int*num4_ptr)
{
	switch(i) //The first time the loop iterates in main, i = 0, so the numbers should be low. As i increases, more iterations have passed, so the numbers should be getting larger but remaining random. I'm basically using i to determine how far along in the level the player is
	{
			case 0: //Iteration 1
				n1 = 0;
				n2 = 0;
				n3 = 0;
				n4 = 0;
				break;
			case 1:
				n1 = rand() % 2; //n1 will be 0 or 1 for iteration 2
				n2 = rand() % 2; //n2 will be 0 or 1 for iteration 2
				n3 = rand() % 2; //n3 will be 0 or 1 for iteration 2
				n4 = rand() % 2; //n4 will be 0 or 1 for iteration 2
				break;
			case 2:
				n1 = rand() % 3 + 1; // % 3 + 1 so that the number will be 1, 2, or 3, not 0, 1, or 2
				n2 = rand() % 3 + 1;
				n3 = rand() % 3 + 1;
				n4 = rand() % 3 + 1;
				break;
			case 3:
				n1 = rand() % 4 + 1;
				n2 = rand() % 4 + 1;
				n3 = rand() % 4 + 1;
				n4 = rand() % 4 + 1;
				break;
			case 4:
				n1 = rand() % 5 + 1;
				n2 = rand() % 5 + 1;
				n3 = rand() % 5 + 1;
				n4 = rand() % 5 + 1;
				break;
			case 5:
				n1 = rand() % 6 + 1;
				n2 = rand() % 6 + 1;
				n3 = rand() % 6 + 1;
				n4 = rand() % 6 + 1;
				break;
			case 6:
				n1 = rand() % 7 + 1;
				n2 = rand() % 7 + 1;
				n3 = rand() % 7 + 1;
				n4 = rand() % 7 + 1;
				break;
			case 7:
				n1 = rand() % 8 + 1;
				n2 = rand() % 8 + 1;
				n3 = rand() % 8 + 1;
				n4 = rand() % 8 + 1;
				break;
			case 8:
				n1 = rand() % 9 + 1;
				n2 = rand() % 9 + 1;
				n3 = rand() % 9 + 1;
				n4 = rand() % 9 + 1;
				break;
			case 9:
				n1 = rand() % 9 + 1;
				n2 = rand() % 9 + 1;
				n3 = rand() % 9 + 1;
				n4 = rand() % 9 + 1;
				break;
	}
	*num1_ptr = n1; //Important! If the pointers aren't dereferenced and thier values set equal to what they're pointing at, then you just get 0's with various operators in between them
	*num2_ptr = n2;
	*num3_ptr = n3;
	*num4_ptr = n4;
}

void choose_nums_for_imposs_level (int i, int n1, int n2, int n3, int n4, int*num1_ptr, int*num2_ptr, int*num3_ptr, int*num4_ptr)
{
	switch(i) //The first time the loop iterates in main, i = 0, so the numbers should be low. As i increases, more iterations have passed, so the numbers should be getting larger but remaining random. I'm basically using i to determine how far along in the level the player is
	{
			case 0: //Iteration 1
				n1 = 0;
				n2 = 0;
				n3 = 0;
				n4 = 0;
				break;
			case 1:
				n1 = rand() % 2; //n1 will be 0 or 1 for iteration 2
				n2 = rand() % 2; //n2 will be 0 or 1 for iteration 2
				n3 = rand() % 2; //n3 will be 0 or 1 for iteration 2
				n4 = rand() % 2; //n4 will be 0 or 1 for iteration 2
				break;
			case 2:
				n1 = rand() % 10;
				n2 = rand() % 10;
				n3 = rand() % 10;
				n4 = rand() % 10;
				break;
			case 3:
				n1 = rand() % 30;
				n2 = rand() % 30;
				n3 = rand() % 30;
				n4 = rand() % 30;
				break;
			case 4:
				n1 = rand() % 60;
				n2 = rand() % 60;
				n3 = rand() % 60;
				n4 = rand() % 60;
				break;
			case 5:
				n1 = rand() % 120;
				n2 = rand() % 120;
				n3 = rand() % 120;
				n4 = rand() % 120;
				break;
			case 6:
				n1 = rand() % 240;
				n2 = rand() % 240;
				n3 = rand() % 240;
				n4 = rand() % 240;
				break;
			case 7:
				n1 = rand() % 480;
				n2 = rand() % 480;
				n3 = rand() % 480;
				n4 = rand() % 480;
				break;
			case 8:
				n1 = rand() % 960;
				n2 = rand() % 960;
				n3 = rand() % 960;
				n4 = rand() % 960;
				break;
			case 9:
				n1 = rand() % 1920;
				n2 = rand() % 1920;
				n3 = rand() % 1920;
				n4 = rand() % 1920;
				break;
	}
	*num1_ptr = n1; //Important! If the pointers aren't dereferenced and thier values set equal to what they're pointing at, then you just get 0's with various operators in between them
	*num2_ptr = n2;
	*num3_ptr = n3;
	*num4_ptr = n4;
}

void random_negative_numbers (int n1, int n2, int n3, int n4, int*num1_ptr, int*num2_ptr, int*num3_ptr, int*num4_ptr)
{
	int negative_or_not = 0, which_num_is_neg = 0, which_num_is_pos = 0;
	negative_or_not = rand () % 5;
	switch (negative_or_not)
	{
	case 0:
		//No negative numbers, all n variables are the same as they were when they were randomly generated in choose_nums
		*num1_ptr = n1;
		*num2_ptr = n2;
		*num3_ptr = n3;
		*num4_ptr = n4;
		break;
	case 1:
		//One negative number, one number is randomly chosen to be negative
		which_num_is_neg = rand() % 4 + 1; // +1 so the random numbers can be 1, 2, 3, or 4
		switch(which_num_is_neg)
		{
		case 1:
			//n1 is negative, so in main num1 will be negative
			*num1_ptr = -n1;
			*num2_ptr = n2;
			*num3_ptr = n3;
			*num4_ptr = n4;
		break;
		case 2:
			//n2 is negative, so in main num2 will be negative
			*num1_ptr = n1;
			*num2_ptr = -n2;
			*num3_ptr = n3;
			*num4_ptr = n4;
		break;
		case 3:
			//n3 is negative, so in main num3 will be negative
			*num1_ptr = n1;
			*num2_ptr = n2;
			*num3_ptr = -n3;
			*num4_ptr = n4;
		break;
		case 4:
			//n4 is negative, so in main num4 will be negative
			*num1_ptr = n1;
			*num2_ptr = n2;
			*num3_ptr = n3;
			*num4_ptr = -n4;
		break;
		}
		break;
	case 2:
		//Two negative numbers
		break;
	case 3:
		//Three negative numbers / One positive number (same ting as case 1 but with a different variable and instead of 3 positive numbers and 1 negative, there are 3 negative numbers and 1 positive
		which_num_is_pos = rand() % 4 + 1; // +1 so the random numbers can be 1, 2, 3, or 4
		switch(which_num_is_pos)
		{
		case 1:
			//all the numbers but n1 are negative, so in main num1 will be positive
			*num1_ptr = n1;
			*num2_ptr = -n2;
			*num3_ptr = -n3;
			*num4_ptr = -n4;
		break;
		case 2:
			//all the numbers but n2 are negative, so in main num2 will be positive
			*num1_ptr = -n1;
			*num2_ptr = n2;
			*num3_ptr = -n3;
			*num4_ptr = -n4;
		break;
		case 3:
			//all the numbers but n3 are negative, so in main num3 will be positive
			*num1_ptr = -n1;
			*num2_ptr = -n2;
			*num3_ptr = n3;
			*num4_ptr = -n4;
		break;
		case 4:
			//all the numbers but n4 are negative, so in main num4 will be positive
			*num1_ptr = -n1;
			*num2_ptr = -n2;
			*num3_ptr = -n3;
			*num4_ptr = n4;
		break;
		}
		break;
	case 4:
		//All negative numbers
		*num1_ptr = -n1;
		*num2_ptr = -n2;
		*num3_ptr = -n3;
		*num4_ptr = -n4;
		break;
	}
}

int reduce_level (int i)
{
if (i == 0) //If the user gets the first problem wrong, they stay on that level until they get it right
	{
		i = 0;
	}
else //If the user is on any other level 1-9 and they get that problem wrong, the next question is easier (eg get a question on level 7 wrong, next question will be from level 6)
	{
		i--;
	}
}