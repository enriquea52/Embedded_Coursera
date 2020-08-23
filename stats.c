/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief A program that retrieves statistical information from an array of numbers
 *
 * The present program retrieves statistical data incluiding the mean, meadian, maximum and minimum values of an unsorted array and then prints the information to the user in the terminal. The program consists on seven functions (explained in the stats.h file) that are in charge of sorting the data array and printing significant information.
 *
 * @author Jesus Enrique Aleman Gallegos
 * @date June 27th,2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  print_statistics(test,SIZE);
	
}

/* Add other Implementation File Code Here */

void print_array(unsigned char array[],int length)
{
for(int i = 0; i<length; i++)
	{
		printf("%d ",array[i]);
	}
}

double find_mean(unsigned char array[],int length)
{	double avg=0;
	for(int i = 0;i<length;i++)
	{
	avg = avg + (int)array[i];
	}

	return avg/length;
}
double find_maximum(unsigned char array[],int length)
{
	return array[0];
}
double find_minimum(unsigned char array[],int length)
{
	return array[length-1];
}
double find_median(unsigned char array[],int length)
{
	double median =0;
	if(length/2.0 == 0)
	{
		median = (array[(int)(length/2.0)]+array[(int)(length/2.0)+1])/2.0;
		return median;
	}
	else
	{
		median = array[(int)(length/2.0)+1];
		return median;
	}
}
void sort_array(unsigned char A[], int size)
{
	for(int i=0; i<size-1; i++)
	{
		int Imin = i;
		for(int j=i+1; j<size; j++)
		{
			if( A[j] > A[Imin] )
			{
				Imin = j;
			}
		}
		int temp = A[Imin];
		A[Imin] = A[i];
		A[i] = temp;
	}
}

void print_statistics(unsigned char A[], int size)
{
  	printf("The original array is: \n");
  	print_array(A,size);
  	printf("\n");
	sort_array(A,size);
	printf("The sorted array is: \n");
	print_array(A,size);
	printf("\n");
	printf("The mean of the array is: %lf \n",find_mean(A,size));
	printf("The median of the array is: %lf \n",find_median(A,size));
	printf("The minimum value is: %lf \n",find_minimum(A,size));
	printf("The maximum value is: %lf \n",find_maximum(A,size));
	
	
	

}

