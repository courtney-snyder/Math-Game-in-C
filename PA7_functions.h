#ifndef PA7_FUNCTIONS_H
#define PA7_FUNCTIONS_H

typedef struct initials
{
	char first;
	char middle;
	char last;
} Initials;

void choose_nums (int i, int n1, int n2, int n3, int n4, int*num1_ptr, int*num2_ptr, int*num3_ptr, int*num4_ptr);
void choose_nums_for_imposs_level (int i, int n1, int n2, int n3, int n4, int*num1_ptr, int*num2_ptr, int*num3_ptr, int*num4_ptr);
void random_negative_numbers (int n1, int n2, int n3, int n4, int*num1_ptr, int*num2_ptr, int*num3_ptr, int*num4_ptr);
int reduce_level (int i);

#endif