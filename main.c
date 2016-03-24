/*
Name: Courtney Snyder
Last Updated: 12/3/2015
Computer Science 121, PA 7
Description: A simple math game for kids. The levels are easy, fair, intermediate, hard, and impossible. Each individual level starts easy 
and progressively gets harder. User gets 1 point for every correct answer in Easy, 2 points for every correct answer in Fair, 3 points for
every correct answer in Intermediate, 4 points for every correct answer in Hard, and 5 points for every correct answer in Impossible. I
added an "unlimited problems" feature because I thought that some people would like to do more than ten problems at a time. I also added
an accuracy "thing" so the user knows how many they're getting right out of how many they've answered.
*/
#include "PA7_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

int main (void)
{
	char impossible_level = '\0', exit = '\0';
	int option = 0, difficulty_level = 0, operator1 = 0, operator2 = 0, operator3 = 0, operator4 = 0, i = 0, score = 0, correct_attempts = 0, total_attempts = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0, user_answer = 0, user_remainder = 0, user_numerator = 0, user_denominator = 0, actual_answer = 0, actual_remainder = 0, actual_numerator = 0, actual_denominator = 0;
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0, *num1_ptr = &n1, *num2_ptr = &n2, *num3_ptr = &n3, *num4_ptr = &n4;
	double accuracy = (double)correct_attempts/total_attempts;
	Initials player = {'\0', '\0', '\0'};
	FILE* write = NULL;
	write = fopen("score.txt", "a");
	srand((unsigned int)time(NULL));

	do
	{
		printf("1. Learn about how to use the program\n2. Enter your initials (3 individual characters)\n3. Start a round of 10 problems\n4. Start a new sequence of unlimited problems\n5. Save and Quit\n");
		scanf("%d", &option);
		switch(option)
		{
		case 1: printf("This game has five levels.\nEasy Level: Includes addition and subtraction problems, with positive single digit operands and up to three terms.\nFair Level: Includes multiplication problems, with positive single digit operands and up to two terms \nIntermediate Level: Includes division problems, with positive single digit operands and up to two terms\nHard Level: Includes a mix of addition, subtraction, multiplication, and division problems, with positive and negative single digit operands and up to three terms\nImpossible Level: Includes a mix of addition, subtraction, multiplication, and division problems, with positive and negative two and three digit operands and up to four terms\n");
			system("pause");
			system("cls");
			break;
		case 2: printf("Enter your initials: ");
			scanf(" %c %c %c", &player.first, &player.middle, &player.last);
			break;
		case 3: printf("Select level of difficulty: ");
			scanf("%d", &difficulty_level);
			system("pause");
			system("cls");
			switch(difficulty_level)
			{
			case 1: printf("Easy Level\n");
				for (i = 0; i < 10; i++)
				{
					choose_nums(i, n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
					num1 = *num1_ptr;
					num2 = *num2_ptr;
					num3 = *num3_ptr;
					operator1 = rand() % 2; //operator1 can be 0 or 1; 0 means addition and 1 means subtraction
					operator2 = rand() % 2; //operator2 can be 0 or 1; 0 means addition and 1 means subtraction
					if (operator1 == 0 && operator2 == 0) //2 addition operators
					{
						actual_answer = num1 + num2 + num3;
						printf("%d + %d + %d = ", num1, num2, num3);
						scanf("%d", &user_answer);
						if (user_answer == actual_answer)
						{
							printf("Congratulations! You got the right answer!\n");
							correct_attempts++;
							score++;
							printf("Current score: %d\n", score);
						}
						else
						{
							printf("The answer was %d\n", actual_answer);
						}
					}
					if (operator1 == 1 && operator2 == 1) //2 subtraction operators
					{
						actual_answer = num1 - num2 - num3;
						printf("%d - %d - %d = ", num1, num2, num3);
						scanf("%d", &user_answer);
						if (user_answer == actual_answer)
						{
							printf("Congratulations! You got the right answer!\n");
							correct_attempts++;
							score++;
							printf("Current score: %d\n", score);
						}
						else
						{ 
							printf("The answer was %d\n", actual_answer);
						}
					}
					if (operator1 == 1 && operator2 == 0) //Subtraction then addition
					{
						actual_answer = num1 - num2 + num3;
						printf("%d - %d + %d = ", num1, num2, num3);
						scanf("%d", &user_answer);
						if (user_answer == actual_answer)
						{
							printf("Congratulations! You got the right answer!\n");
							correct_attempts++;
							score++;
							printf("Current score: %d\n", score);
						}
						else
						{
							printf("The answer was %d\n", actual_answer);
						}
					}
					if (operator1 == 0 && operator2 == 1) //Addition then subtraction
					{
						actual_answer = num1 + num2 - num3;
						printf("%d + %d - %d = ", num1, num2, num3);
						scanf("%d", &user_answer);
						if (user_answer == actual_answer)
						{
							printf("Congratulations! You got the right answer!\n");
							correct_attempts++;
							score++;
							printf("Current score: %d\n", score);
						}
						else
						{
							printf("The answer was %d\n", actual_answer);
						}
					}
				total_attempts++;
				system("pause"); //Clears the screen after every problem
				system("cls");
				}
				break;
			case 2: printf("Fair Level\n");
				for (i = 0; i < 10; i++)
				{
					choose_nums(i, n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
					num1 = *num1_ptr;
					num2 = *num2_ptr;
					actual_answer = num1 * num2;
					printf("%d * %d = ", num1, num2);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=2;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				total_attempts++;
				system("pause");
				system("cls");
				}
				break;
			case 3: printf("Intermediate Level\n");
				for (i = 0; i < 10; i++)
				{
					choose_nums(i, n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
					num1 = *num1_ptr;
					num2 = *num2_ptr;
					//actual_answer = num1 / num2; //When I uncomment these, the level doesn't work
					//actual_remainder = n1 % n2;
					printf("Enter answer in the form integer SPACE remainder. Do not use a decimal point or any letters.\n%d / %d = ", num1, num2);
					scanf("%d%d", &user_answer, &user_remainder);
					if (user_answer == actual_answer && user_remainder == actual_remainder)
					{ 
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=3;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d R %d\n", actual_answer, actual_remainder);
					}
				total_attempts++;
				system("pause");
				system("cls");
				}
				break;
			case 4: printf("Hard Level\n");
				for (i = 0; i < 10; i++)
				{
				choose_nums(i, n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
				random_negative_numbers(n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
				num1 = *num1_ptr;
				num2 = *num2_ptr;
				num3 = *num3_ptr;
				operator1 = rand() % 4; // %4 because addition, subtraction, multiplication, and division are all possible operators
				operator2 = rand() % 4;
				if (operator1 == 3)
				{
					if (operator2 == 3)
					{
						operator2 = rand() % 3; //If operator 1 is 3 (division) and operator 2 is 3 (division), I will reassign operator 2 to 0 (addition) 1 (subtraction) or 2 (multiplication)
					}
				}
				if (operator1 == 0 && operator2 == 0) //Both addition operators
				{
					actual_answer = num1 + num2 + num3;
					printf("%d + %d + %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 1) //Addition then subtraction
				{
					actual_answer = num1 + num2 - num3;
					printf("%d + %d - %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 2) //Addition then multiplication
				{
					actual_answer = num1 + (num2 * num3);
					printf("%d + %d * %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 3) //Addition then division
				{
					actual_numerator = num1 + num2;
					actual_denominator = num3;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d / %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
					}

				}
				else if (operator1 == 1 && operator2 == 0) //Subtraction then addition
				{
					actual_answer = num1 - num2 + num3;
					printf("%d - %d + %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 1) //Both subtraction operators
				{
					actual_answer = num1 - num2 - num3;
					printf("%d - %d - %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 2) //Subtraction then multiplication
				{
					actual_answer = num1 - (num2 * num3);
					printf("%d - %d * %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 3) //Subtraction then division
				{
					actual_numerator = num1 - num2;
					actual_denominator = num3;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d / %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 2 && operator2 == 0) //Multiplication then addition
				{
					actual_answer = (num1 * num2) + num3;
					printf("%d * %d + %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 1) //Multiplication then subtraction
				{
					actual_answer = (num1 * num2) - num3;
					printf("%d * %d - %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 2) //Both multiplication operators
				{
					actual_answer = num1 * num2 * num3;
					printf("%d * %d * %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 3) //Multiplication then division
				{
					actual_numerator = num1 * num2;
					actual_denominator = num3;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n(%d * %d) / %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 0) //Division, then addition
				{
					actual_numerator = num1;
					actual_denominator = num2 + num3;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d + %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 1) //Division then subtraction
				{
					actual_numerator = num1;
					actual_denominator = num2 - num3; //Common denominator
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d - %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 2) //Division then multiplication
				{
					actual_numerator = num1 * num3;
					actual_denominator = num2;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d * %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
					}
				}
				total_attempts++;
				system("pause");
				system("cls");
				}
				break;
			case 5: printf("Impossible Level\n");
				printf("Are you sure you want to play this level? Enter y or n.\n");
				scanf(" %c", &impossible_level);
				if (impossible_level != 'y' && impossible_level != 'Y') //If the user enters anything besides y or Y, they won't play this level
				{
					printf("Wise decision, friend. Choose another option.\n");
					break;
				}
				for (i = 0; i < 10; i++)
				{
				choose_nums_for_imposs_level(i, n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
				random_negative_numbers(n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
				num1 = *num1_ptr;
				num2 = *num2_ptr;
				num3 = *num3_ptr;
				num4 = *num4_ptr;
				operator1 = rand() % 4; // %4 because addition, subtraction, multiplication, and division are all possible operators
				operator2 = rand() % 4;
				operator3 = rand() % 4;
				if (operator1 == 3)
				{
					if (operator2 == 3)
					{
						operator2 = rand() % 3; // % 3 so if operator 1 is division and operator 2 is division, operator 2 will be reassigned to 0 (addition) 1 (subtraction) or 2 (multiplication)
					}
				}
				else if (operator2 == 3)
				{
					if (operator1 == 3)
					{
						operator1 = rand() % 3; // % 3 so if operator 1 is division and operator 2 is division, operator 1 will be reassigned to 0 (addition) 1 (subtraction) or 2 (multiplication)
					}
					if (operator3 == 3)
					{
						operator3 = rand() % 3; // % 3 so if operator 3 is division and operator 2 is division, operator 3 will be reassigned to 0 (addition) 1 (subtraction) or 2 (multiplication)
					}
				}
				else if (operator3 == 3)
				{
					if (operator2 == 3)
					{
						operator2 = rand() % 3;
					}
				}
				if (operator1 == 0 && operator2 == 0 && operator3 == 0) //All addition operators
				{
					actual_answer = num1 + num2 + num3 + num4;
					printf("%d + %d + %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 0 && operator3 == 1) //Addition, addition, subtraction
				{
					actual_answer = num1 + num2 + num3 - num4;
					printf("%d + %d + %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 0 && operator3 == 2) //Addition, addition, multiplication
				{
					actual_answer = num1 + num2 + (num3 * num4);
					printf("%d + %d + %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 0 && operator3 == 3) //Addition, addition, division
				{
					actual_numerator = num1 + num2 + num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d + %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 0 && operator2 == 1 && operator3 == 0) //Addition, subtraction, addition
				{
					actual_answer = num1 + num2 - num3 + num4;
					printf("%d + %d - %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 1 && operator3 == 1) //Addition, subtraction, subtraction
				{
					actual_answer = num1 + num2 - num3 - num4;
					printf("%d + %d - %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 1 && operator3 == 2) //Addition, subtraction, multiplication
				{
					actual_answer = num1 + num2 - (num3 * num4);
					printf("%d + %d - %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 1 && operator3 == 3) //Addition, subtraction, division
				{
					actual_numerator = num1 + num2 - num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d - %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 0 && operator2 == 2 && operator3 == 0) //Addition, multiplication, addition
				{
					actual_answer = num1 + (num2 * num3) + num4;
					printf("%d + %d * %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 2 && operator3 == 1) //Addition, multiplication, subtraction
				{
					actual_answer = num1 + (num2 * num3) - num4;
					printf("%d + %d * %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 2 && operator3 == 2) //Addition, multiplication, multiplication
				{
					actual_answer = num1 + (num2 * num3 * num4);
					printf("%d + %d * %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 0 && operator2 == 2 && operator3 == 3) //Addition, multiplication, division
				{
					actual_numerator = num1 + (num2 * num3);
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d * %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 0 && operator2 == 3 && operator3 == 0) //Two fractions added together
				{
					actual_numerator = num1 + num2;
					actual_denominator = num3 + num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d / %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}

				}
				else if (operator1 == 0 && operator2 == 3 && operator3 == 1) //Addition, division, subtraction
				{
					actual_numerator = num1 + num2;
					actual_denominator = num3 - num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d / %d - %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 0 && operator2 == 3 && operator3 == 2) //Addition, division, multiplication
				{
					actual_numerator = num1 + num2;
					actual_denominator = num3 * num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d / %d * %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 1 && operator2 == 1 && operator3 == 1) //All subtraction operators
				{
					actual_answer = num1 - num2 - num3 - num4;
					printf("%d - %d - %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 1 && operator3 == 0) //Subtraction, subtraction, addition
				{
					actual_answer = num1 - num2 - num3 + num4;
					printf("%d - %d - %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 1 && operator3 == 2) //Subtraction, subtraction, multiplication
				{
					actual_answer = num1 - num2 - (num3 * num4);
					printf("%d - %d - %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 1 && operator3 == 3) //Subtraction, subtraction, division
				{
					actual_numerator = num1 - num2 - num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d - %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 1 && operator2 == 0 && operator3 == 0) //Subtraction, addition, addition
				{
					actual_answer = num1 - num2 + num3 + num4;
					printf("%d - %d + %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 0 && operator3 == 1) //Subtraction, addition, subtraction
				{
					actual_answer = num1 - num2 + num3 - num4;
					printf("%d - %d + %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 0 && operator3 == 2) //Subtraction, addition, multiplication
				{
					actual_answer = num1 - num2 + (num3 * num4);
					printf("%d - %d + %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 0 && operator3 == 3) //Subtraction, addition, division
				{
					actual_numerator = num1 - num2 + num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d + %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 1 && operator2 == 2 && operator3 == 0) //Subtraction, mulitplication, addition
				{
					actual_answer = num1 - (num2 * num3) + num4;
					printf("%d - %d * %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 2 && operator3 == 1) //Subtraction, mulitplication, subtraction
				{
					actual_answer = num1 - (num2 * num3) - num4;
					printf("%d - %d * %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 2 && operator3 == 2) //Subtraction, mulitplication, multiplication
				{
					actual_answer = num1 - (num2 * num3 * num4);
					printf("%d - %d * %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 1 && operator2 == 2 && operator3 == 3) //Subtraction, mulitplication, division
				{
					actual_numerator = num1 - (num2 * num3);
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d * %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 1 && operator2 == 3 && operator3 == 1) //Subtraction, division, subtraction
				{
					actual_numerator = num1 - num2;
					actual_denominator = num3 - num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d / %d - %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 1 && operator2 == 3 && operator3 == 2) //Subtraction, division, multiplication
				{
					actual_numerator = num1 - num2;
					actual_denominator = num3 * num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d / %d * %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 1 && operator2 == 3 && operator3 == 0) //Subtraction, division, addition
				{
					actual_numerator = num1 - num2;
					actual_denominator = num3 + num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d / %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 2 && operator2 == 0 && operator3 == 0) //Multiplication, addition, addition
				{
					actual_answer = (num1 * num2) + num3 + num4;
					printf("%d * %d + %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 0 && operator3 == 1) //Multiplication, addition, subtraction
				{
					actual_answer = (num1 * num2) + num3 - num4;
					printf("%d * %d + %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 0 && operator3 == 2) //Multiplication, addition, multiplication
				{
					actual_answer = (num1 * num2) + (num3 * num4);
					printf("%d * %d + %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 0 && operator3 == 3) //Multiplication, addition, division
				{
					actual_numerator = (num1 * num2) + num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d + %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 2 && operator2 == 1 && operator3 == 0) //Multiplication, subtraction, addition
				{
					actual_answer = (num1 * num2) - num3 + num4;
					printf("%d * %d - %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 1 && operator3 == 1) //Multiplication, subtraction, subtraction
				{
					actual_answer = (num1 * num2) - num3 - num4;
					printf("%d * %d - %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 1 && operator3 == 2) //Multiplication, subtraction, multiplication
				{
					actual_answer = (num1 * num2) - (num3 * num4);
					printf("%d * %d - %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 1 && operator3 == 3) //Multiplication, subtraction, division
				{
					actual_numerator = (num1 * num2) - num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d - %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 2 && operator2 == 2 && operator3 == 0) //Multiplication, multiplication, addition
				{
					actual_answer = (num1 * num2 * num3) + num4;
					printf("%d * %d * %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 2 && operator3 == 1) //Multiplication, multiplication, subtraction
				{
					actual_answer = (num1 * num2 * num3) - num4;
					printf("%d * %d * %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 2 && operator3 == 2) //All multiplication operators
				{
					actual_answer = num1 * num2 * num3 * num4;
					printf("%d * %d * %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
					}
				}
				else if (operator1 == 2 && operator2 == 2 && operator3 == 3) //Multiplication, multiplication, division
				{
					actual_numerator = num1 * num2 * num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d * %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 2 && operator2 == 3 && operator3 == 0) //Multiplication, division, addition
				{
					actual_numerator = num1 * num2;
					actual_denominator = num3 + num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d / %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 2 && operator2 == 3 && operator3 == 1) //Multiplication, division, subtraction
				{
					actual_numerator = num1 * num2;
					actual_denominator = num3 - num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d / %d - %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 2 && operator2 == 3 && operator3 == 2) //Multiplication, division, multiplication
				{
					actual_numerator = num1 * num2;
					actual_denominator = num3 * num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d / %d * %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 0 && operator3 == 0) //Division, addition, addition
				{
					actual_numerator = num1;
					actual_denominator = num2 + num3 + num4; //Common denominator
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d + %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 0 && operator3 == 3) //Two fractions added
				{
					num1*= num4; //Multiplying the numerator by the other fraction's denominator to get a common denominator
					num3*= num2; //Multiplying the numerator by the other fraction's denominator to get a common denominator
					actual_numerator = num1+num3;
					actual_denominator = num2 * num4; //Common denominator
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d + %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 1 && operator3 == 0) //Division, subtraction, addition
				{
					actual_numerator = num1;
					actual_denominator = num2 - num3 + num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d - %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 1 && operator3 == 1) //Division, subtraction, subtraction
				{
					actual_numerator = num1;
					actual_denominator = num2 - num3 - num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d - %d - %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 1 && operator3 == 2) //Division, subtraction, multiplication
				{
					actual_numerator = num1;
					actual_denominator = num2 - (num3 * num4);
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d - %d * %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 1 && operator3 == 3) //Two fractions subtracted
				{
					actual_numerator = (num1*num4)-(num3*num2); //Multiplying the numerator by the other fraction's denominator to get a common denominator
					actual_denominator = num2 * num4; //Common denominator
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d - %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 2 && operator3 == 0) //Division, multiplication, addition
				{
					actual_numerator = num1;
					actual_denominator = (num3 * num2) + num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d * %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 2 && operator3 == 1) //Division, multiplication, subtraction
				{
					actual_numerator = num1;
					actual_denominator = (num3 * num2) - num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d * %d - %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 2 && operator3 == 2) //Division, multiplication, multiplication
				{
					actual_numerator = num1;
					actual_denominator = num3 * num2 * num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d * %d * %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				else if (operator1 == 3 && operator2 == 2 && operator3 == 3) //Two fractions multiplied
				{
					actual_numerator = num1 * num3;
					actual_denominator = num2 * num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d * %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						score+=5;
						printf("Current score: %d\n", score);
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
					}
				}
				total_attempts++;
				system("pause");
				system("cls");				
				}
				break;
			default: printf("Please choose option 1, 2, 3, 4, or 5.\n");
				scanf("%d", &difficulty_level);
				break;
			}
			break;
		case 4: printf("Select level of difficulty: ");
			scanf("%d", &difficulty_level);
			system("pause");
			system("cls");
			switch(difficulty_level)
			{
			case 1: 
				printf("Easy Level\n");
				while (i < 10)
				{
					choose_nums(i, n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
					num1 = *num1_ptr;
					num2 = *num2_ptr;
					num3 = *num3_ptr;
					operator1 = rand() % 2; //operator1 can be 0 or 1; 0 means addition and 1 means subtraction
					operator2 = rand() % 2; //operator2 can be 0 or 1; 0 means addition and 1 means subtraction
					if (operator1 == 0 && operator2 == 0) //2 addition operators
					{
						actual_answer = num1 + num2 + num3;
						printf("%d + %d + %d = ", num1, num2, num3);
						scanf("%d", &user_answer);
						if (user_answer == actual_answer)
						{
							printf("Congratulations! You got the right answer!\n");
							correct_attempts++;
							score++;
							printf("Current score: %d\n", score);
							i++;
						}
						else
						{
							printf("The answer was %d\n", actual_answer);
							i = reduce_level(i); //If the user gets the problem wrong, the next question is from the previous level
						}
					}
					if (operator1 == 1 && operator2 == 1) //2 subtraction operators
					{
						actual_answer = num1 - num2 - num3;
						printf("%d - %d - %d = ", num1, num2, num3);
						scanf("%d", &user_answer);
						if (user_answer == actual_answer)
						{
							printf("Congratulations! You got the right answer!\n");
							correct_attempts++;
							score++;
							printf("Current score: %d\n", score);
							i++;
						}
						else
						{ 
							printf("The answer was %d\n", actual_answer);
							i = reduce_level(i); //If the user gets the problem wrong, the next question is from the previous level
						}
					}
					if (operator1 == 1 && operator2 == 0) //Subtraction then addition
					{
						actual_answer = num1 - num2 + num3;
						printf("%d - %d + %d = ", num1, num2, num3);
						scanf("%d", &user_answer);
						if (user_answer == actual_answer)
						{
							printf("Congratulations! You got the right answer!\n");
							correct_attempts++;
							score++;
							printf("Current score: %d\n", score);
							i++;
						}
						else
						{
							printf("The answer was %d\n", actual_answer);
							i = reduce_level(i);//If the user gets the problem wrong, the next question is from the previous level
						}
					}
					if (operator1 == 0 && operator2 == 1) //Addition then subtraction
					{
						actual_answer = num1 + num2 - num3;
						printf("%d + %d - %d = ", num1, num2, num3);
						scanf("%d", &user_answer);
						if (user_answer == actual_answer)
						{
							printf("Congratulations! You got the right answer!\n");
							correct_attempts++;
							score++;
							printf("Current score: %d\n", score);
							i++;
						}
						else
						{
							printf("The answer was %d\n", actual_answer);
							i = reduce_level(i);
						}
					}
				printf("Enter x to exit.\n");
				scanf(" %c", &exit);
				if (exit == 'x' || exit == 'X')
				{
					break;
				}
				total_attempts++;
				system("pause");
				system("cls");
				}
				break;
			case 2: printf("Fair Level\n");
				while (i < 10)
				{
					choose_nums(i, n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
					num1 = *num1_ptr;
					num2 = *num2_ptr;
					actual_answer = num1 * num2;
					printf("%d * %d = ", num1, num2);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=2;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i); //If the user gets the problem wrong, the next question is from the previous level
					}
				total_attempts++;
				printf("Enter x to exit.\n");
				scanf(" %c", &exit);
				if (exit == 'x' || exit == 'X')
				{
					break;
				}
				system("pause");
				system("cls");
				}
				break;
			case 3: printf("Intermediate Level\n");
				while (i < 10)
				{
					choose_nums(i, n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
					num1 = *num1_ptr;
					num2 = *num2_ptr;
					//actual_answer = num1 / num2; //When I uncomment these, the level doesn't run
					//actual_remainder = num1 % num2;
					printf("Enter answer in the form integer SPACE remainder. Do not use a decimal point or any letters.\n%d / %d =  R  ", num1, num2);
					scanf("%d%d", &user_answer, &user_remainder);
					if (user_answer == actual_answer && user_remainder == actual_remainder)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=3;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d R %d\n", actual_answer, actual_remainder);
						i = reduce_level(i);
					}
				total_attempts++;
				printf("Enter x to exit.\n");
				scanf(" %c", &exit);
				if (exit == 'x' || exit == 'X')
				{
					break;
				}
				system("pause");
				system("cls");
				}
				break;
			case 4: printf("Hard Level\n");
				while (i < 10)
				{
				choose_nums(i, n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
				random_negative_numbers(n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
				num1 = *num1_ptr;
				num2 = *num2_ptr;
				num3 = *num3_ptr;
				operator1 = rand() % 4; // %4 because addition, subtraction, multiplication, and division are all possible operators
				operator2 = rand() % 4;
				if (operator1 == 3)
				{
					if (operator2 == 3)
					{
						operator2 = rand() % 3;
					}
				}
				if (operator1 == 0 && operator2 == 0) //Both addition operators
				{
					actual_answer = num1 + num2 + num3;
					printf("%d + %d + %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 1) //Addition then subtraction
				{
					actual_answer = num1 + num2 - num3;
					printf("%d + %d - %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 2) //Addition then multiplication
				{
					actual_answer = num1 + (num2 * num3);
					printf("%d + %d * %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 3) //Addition then division
				{
					actual_numerator = num1 + num2;
					actual_denominator = num3;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d / %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}

				}
				else if (operator1 == 1 && operator2 == 0) //Subtraction then addition
				{
					actual_answer = num1 - num2 + num3;
					printf("%d - %d + %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 1) //Both subtraction operators
				{
					actual_answer = num1 - num2 - num3;
					printf("%d - %d - %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 2) //Subtraction then multiplication
				{
					actual_answer = num1 - (num2 * num3);
					printf("%d - %d * %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 3) //Subtraction then division
				{
					actual_numerator = num1 - num2;
					actual_denominator = num3;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d / %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 0) //Multiplication then addition
				{
					actual_answer = (num1 * num2) + num3;
					printf("%d * %d + %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 1) //Multiplication then subtraction
				{
					actual_answer = (num1 * num2) - num3;
					printf("%d * %d - %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 2) //Both multiplication operators
				{
					actual_answer = num1 * num2 * num3;
					printf("%d * %d * %d = ", num1, num2, num3);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 3) //Multiplication then division
				{
					actual_numerator = num1 * num2;
					actual_denominator = num3;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n(%d * %d) / %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 0) //Division, then addition
				{
					num3*=num2; //I'm multiplying the whole number by the denominator to change num3 into num3*num2/num2, so it can be added to num1/num2
					actual_numerator = num1+num3;
					actual_denominator = num2;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d + %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 1) //Division then subtraction
				{
					num3*= num2; //I'm multiplying the whole number by the denominator to change num3 into num3*num2/num2, so it can be added to num1/num2
					actual_numerator = num1-num3;
					actual_denominator = num2; //Common denominator
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d - %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 2) //Division then multiplication
				{
					actual_numerator = num1 * num3;
					actual_denominator = num2;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d * %d = ", num1, num2, num3);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=4;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				total_attempts++;
				printf("Enter x to exit.\n");
				scanf(" %c", &exit);
				if (exit == 'x' || exit == 'X')
				{
					break;
				}
				system("pause");
				system("cls");				
				break;
			case 5: printf("Impossible Level\n");
				printf("Are you sure you want to play this level? Enter y or n.\n");
				scanf(" %c", &impossible_level);
				if (impossible_level != 'y' && impossible_level != 'Y') //If the user enters anything besides y or Y, they won't play this level
				{
					printf("Wise decision, friend. Choose another option.\n");
					break;
				}
				while (i < 10)
				{
				choose_nums_for_imposs_level(i, n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
				random_negative_numbers(n1, n2, n3, n4, num1_ptr, num2_ptr, num3_ptr, num4_ptr);
				num1 = *num1_ptr;
				num2 = *num2_ptr;
				num3 = *num3_ptr;
				num4 = *num4_ptr;
				operator1 = rand() % 4; // %4 because addition, subtraction, multiplication, and division are all possible operators
				operator2 = rand() % 4;
				operator3 = rand() % 4;
				if (operator1 == 3)
				{
					if (operator2 == 3)
					{
						operator2 = rand() % 3; // % 3 so if operator 1 is division and operator 2 is division, operator 2 will be reassigned to 0 (addition) 1 (subtraction) or 2 (multiplication)
					}
				}
				else if (operator2 == 3)
				{
					if (operator1 == 3)
					{
						operator1 = rand() % 3; // % 3 so if operator 1 is division and operator 2 is division, operator 1 will be reassigned to 0 (addition) 1 (subtraction) or 2 (multiplication)
					}
					if (operator3 == 3)
					{
						operator3 = rand() % 3; // % 3 so if operator 3 is division and operator 2 is division, operator 3 will be reassigned to 0 (addition) 1 (subtraction) or 2 (multiplication)
					}
				}
				else if (operator3 == 3)
				{
					if (operator2 == 3)
					{
						operator2 = rand() % 3;
					}
				}
				if (operator1 == 0 && operator2 == 0 && operator3 == 0) //All addition operators
				{
					actual_answer = num1 + num2 + num3 + num4;
					printf("%d + %d + %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 0 && operator3 == 1) //Addition, addition, subtraction
				{
					actual_answer = num1 + num2 + num3 - num4;
					printf("%d + %d + %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 0 && operator3 == 2) //Addition, addition, multiplication
				{
					actual_answer = num1 + num2 + (num3 * num4);
					printf("%d + %d + %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 0 && operator3 == 3) //Addition, addition, division
				{
					actual_numerator = num1 + num2 + num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d + %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 1 && operator3 == 0) //Addition, subtraction, addition
				{
					actual_answer = num1 + num2 - num3 + num4;
					printf("%d + %d - %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 1 && operator3 == 1) //Addition, subtraction, subtraction
				{
					actual_answer = num1 + num2 - num3 - num4;
					printf("%d + %d - %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 1 && operator3 == 2) //Addition, subtraction, multiplication
				{
					actual_answer = num1 + num2 - (num3 * num4);
					printf("%d + %d - %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 1 && operator3 == 3) //Addition, subtraction, division
				{
					actual_numerator = num1 + num2 - num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d - %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 2 && operator3 == 0) //Addition, multiplication, addition
				{
					actual_answer = num1 + (num2 * num3) + num4;
					printf("%d + %d * %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 2 && operator3 == 1) //Addition, multiplication, subtraction
				{
					actual_answer = num1 + (num2 * num3) - num4;
					printf("%d + %d * %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 2 && operator3 == 2) //Addition, multiplication, multiplication
				{
					actual_answer = num1 + (num2 * num3 * num4);
					printf("%d + %d * %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 2 && operator3 == 3) //Addition, multiplication, division
				{
					actual_numerator = num1 + (num2 * num3);
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d * %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 3 && operator3 == 0) //Two fractions added together
				{
					actual_numerator = num1 + num2;
					actual_denominator = num3 + num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d / %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}

				}
				else if (operator1 == 0 && operator2 == 3 && operator3 == 1) //Addition, division, subtraction
				{
					actual_numerator = num1 + num2;
					actual_denominator = num3 - num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d / %d - %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 0 && operator2 == 3 && operator3 == 2) //Addition, division, multiplication
				{
					actual_numerator = num1 + num2;
					actual_denominator = num3 * num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d + %d / %d * %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 1 && operator3 == 1) //All subtraction operators
				{
					actual_answer = num1 - num2 - num3 - num4;
					printf("%d - %d - %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 1 && operator3 == 0) //Subtraction, subtraction, addition
				{
					actual_answer = num1 - num2 - num3 + num4;
					printf("%d - %d - %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 1 && operator3 == 2) //Subtraction, subtraction, multiplication
				{
					actual_answer = num1 - num2 - (num3 * num4);
					printf("%d - %d - %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 1 && operator3 == 3) //Subtraction, subtraction, division
				{
					actual_numerator = num1 - num2 - num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d - %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 0 && operator3 == 0) //Subtraction, addition, addition
				{
					actual_answer = num1 - num2 + num3 + num4;
					printf("%d - %d + %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 0 && operator3 == 1) //Subtraction, addition, subtraction
				{
					actual_answer = num1 - num2 + num3 - num4;
					printf("%d - %d + %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 0 && operator3 == 2) //Subtraction, addition, multiplication
				{
					actual_answer = num1 - num2 + (num3 * num4);
					printf("%d - %d + %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 0 && operator3 == 3) //Subtraction, addition, division
				{
					actual_numerator = num1 - num2 + num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d + %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 2 && operator3 == 0) //Subtraction, mulitplication, addition
				{
					actual_answer = num1 - (num2 * num3) + num4;
					printf("%d - %d * %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 2 && operator3 == 1) //Subtraction, mulitplication, subtraction
				{
					actual_answer = num1 - (num2 * num3) - num4;
					printf("%d - %d * %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 2 && operator3 == 2) //Subtraction, mulitplication, multiplication
				{
					actual_answer = num1 - (num2 * num3 * num4);
					printf("%d - %d * %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 2 && operator3 == 3) //Subtraction, mulitplication, division
				{
					actual_numerator = num1 - (num2 * num3);
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d * %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 3 && operator3 == 1) //Subtraction, division, subtraction
				{
					actual_numerator = num1 - num2;
					actual_denominator = num3 - num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d / %d - %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 3 && operator3 == 2) //Subtraction, division, multiplication
				{
					actual_numerator = num1 - num2;
					actual_denominator = num3 * num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d / %d * %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 1 && operator2 == 3 && operator3 == 0) //Subtraction, division, addition
				{
					actual_numerator = num1 - num2;
					actual_denominator = num3 + num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d - %d / %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 0 && operator3 == 0) //Multiplication, addition, addition
				{
					actual_answer = (num1 * num2) + num3 + num4;
					printf("%d * %d + %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 0 && operator3 == 1) //Multiplication, addition, subtraction
				{
					actual_answer = (num1 * num2) + num3 - num4;
					printf("%d * %d + %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 0 && operator3 == 2) //Multiplication, addition, multiplication
				{
					actual_answer = (num1 * num2) + (num3 * num4);
					printf("%d * %d + %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 0 && operator3 == 3) //Multiplication, addition, division
				{
					actual_numerator = (num1 * num2) + num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d + %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 1 && operator3 == 0) //Multiplication, subtraction, addition
				{
					actual_answer = (num1 * num2) - num3 + num4;
					printf("%d * %d - %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 1 && operator3 == 1) //Multiplication, subtraction, subtraction
				{
					actual_answer = (num1 * num2) - num3 - num4;
					printf("%d * %d - %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 1 && operator3 == 2) //Multiplication, subtraction, multiplication
				{
					actual_answer = (num1 * num2) - (num3 * num4);
					printf("%d * %d - %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 1 && operator3 == 3) //Multiplication, subtraction, division
				{
					actual_numerator = (num1 * num2) - num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d - %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 2 && operator3 == 0) //Multiplication, multiplication, addition
				{
					actual_answer = (num1 * num2 * num3) + num4;
					printf("%d * %d * %d + %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 2 && operator3 == 1) //Multiplication, multiplication, subtraction
				{
					actual_answer = (num1 * num2 * num3) - num4;
					printf("%d * %d * %d - %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 2 && operator3 == 2) //All multiplication operators
				{
					actual_answer = num1 * num2 * num3 * num4;
					printf("%d * %d * %d * %d = ", num1, num2, num3, num4);
					scanf("%d", &user_answer);
					if (user_answer == actual_answer)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d\n", actual_answer);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 2 && operator3 == 3) //Multiplication, multiplication, division
				{
					actual_numerator = num1 * num2 * num3;
					actual_denominator = num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d * %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 3 && operator3 == 0) //Multiplication, division, addition
				{
					actual_numerator = num1 * num2;
					actual_denominator = num3 + num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d / %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 3 && operator3 == 1) //Multiplication, division, subtraction
				{
					actual_numerator = num1 * num2;
					actual_denominator = num3 - num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d / %d - %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 2 && operator2 == 3 && operator3 == 2) //Multiplication, division, multiplication
				{
					actual_numerator = num1 * num2;
					actual_denominator = num3 * num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d * %d / %d * %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 0 && operator3 == 0) //Division, addition, addition
				{
					actual_numerator = num1;
					actual_denominator = num2 + num3 + num4; //Common denominator
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d + %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 0 && operator3 == 3) //Two fractions added
				{
					num1*= num4; //Multiplying the numerator by the other fraction's denominator to get a common denominator
					num3*= num2; //Multiplying the numerator by the other fraction's denominator to get a common denominator
					actual_numerator = num1+num3;
					actual_denominator = num2 * num4; //Common denominator
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d + %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 1 && operator3 == 0) //Division, subtraction, addition
				{
					actual_numerator = num1;
					actual_denominator = num2 - num3 + num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d - %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 1 && operator3 == 1) //Division, subtraction, subtraction
				{
					actual_numerator = num1;
					actual_denominator = num2 - num3 - num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d - %d - %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 1 && operator3 == 2) //Division, subtraction, multiplication
				{
					actual_numerator = num1;
					actual_denominator = num2 - (num3 * num4);
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d - %d * %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 1 && operator3 == 3) //Two fractions subtracted
				{
					actual_numerator = (num1*num4)-(num3*num2); //Multiplying the numerator by the other fraction's denominator to get a common denominator
					actual_denominator = num2 * num4; //Common denominator
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d - %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 2 && operator3 == 0) //Division, multiplication, addition
				{
					actual_numerator = num1;
					actual_denominator = (num3 * num2) + num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d * %d + %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 2 && operator3 == 1) //Division, multiplication, subtraction
				{
					actual_numerator = num1;
					actual_denominator = (num3 * num2) - num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d * %d - %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 2 && operator3 == 2) //Division, multiplication, multiplication
				{
					actual_numerator = num1;
					actual_denominator = num3 * num2 * num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d * %d * %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				else if (operator1 == 3 && operator2 == 2 && operator3 == 3) //Two fractions multiplied
				{
					actual_numerator = num1 * num3;
					actual_denominator = num2 * num4;
					printf("Enter answer as a fraction in the form numerator SPACE denominator. Do not use a backslash.\n%d / %d * %d / %d = ", num1, num2, num3, num4);
					scanf("%d%d", &user_numerator, &user_denominator);
					if (user_numerator == actual_numerator && user_denominator == actual_denominator)
					{
						printf("Congratulations! You got the right answer!\n");
						correct_attempts++;
						score+=5;
						printf("Current score: %d\n", score);
						i++;
					}
					else
					{
						printf("The answer was %d / %d\n", actual_numerator, actual_denominator);
						i = reduce_level(i);
					}
				}
				total_attempts++;
				printf("Enter x to exit.\n");
				scanf(" %c", &exit);
				if (exit == 'x' || exit == 'X')
				{
					break;
				}
				system("pause");
				system("cls");				
				}
				break;
			default: printf("Please choose option 1, 2, 3, 4, or 5.\n");
				scanf("%d", &difficulty_level);
				break;
			}
			}
			break;
		case 5: printf("Save and Quit.\n");
			accuracy = (double)correct_attempts/total_attempts; //This gives me a decimal
			accuracy*= 100; //This will give me a percentage
			if (total_attempts == 0) //If the player didn't answer any questions
			{
				accuracy = 0; //It was giving me #-INDO and that might confuse some users
			}
			printf("Thanks for playing %c%c%c! Your final score was %d and your accuracy was %.2lf %%\n", player.first, player.middle, player.last, score, accuracy);
			fprintf(write, "Player: %c%c%c Score: %d Accuracy: %.2lf %%\n", player.first, player.middle, player.last, score, accuracy);
			fclose(write);
			return 0;
			break;
		default: printf("Please choose option 1, 2, 3, 4, or 5.\n");
		}
	}
	while (option != 5); //If the user selects option 5, then they will exit the loop and the program
	return 0;
}