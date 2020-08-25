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
 * @file stats.h
 * @brief Here the function declarations for retrieving and printing statistical information from an array of numbers.
 *
 * The present files consists of seven function declarations which are the functions used in stats.c for sorting and retieving the median, mean, maximum value and minimum value of an array of given numbers.
 *
 * @author Jesus Enrique Aleman Gallegos
 * @date 	June 27th 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

void print_array(unsigned char array[],int length);
/**
 * @brief Prints the number of an array
 *
 * This function iterates over an array and prints each element 
 * after another to the terminal so the user can visualize the 
 * information.
 *
 * @param array[] An array of unsigned char elements
 * @param length The size of the given array

 * @return Nothing
 */

double find_mean(unsigned char array[],int length);
/**
 * @brief Finds the mean value of a given array of numbers
 *
 * This function iterates over an array and adding the values 
 * array to a variable and then the total sum is divided over the 
 * number of elements in the array to get the mean.
 *
 * @param array[] An array of unsigned char elements
 * @param length The size of the given array

 * @return The mean value of the given array
 */

void sort_array(unsigned char A[], int size);
/**
 * @brief Sorts a given array
 *
 * This function uses the bubble sort algorithm for 
 * sorting an array, the largest element being at position [0]
 * and the smallest element being at the last position.
 *
 * @param array[] An array of unsigned char elements
 * @param length The size of the given array

 * @return Nothing
 */

double find_maximum(unsigned char array[],int length);
/**
 * @brief Finds the maximum value of an array
 *
 * This function return the maximum value of a sorted array
 * , being this value the first element of a sorted array. 
 *
 * @param array[] An array of unsigned char elements
 * @param length The size of the given array

 * @return the maximum value of an array
 */

double find_minimum(unsigned char array[],int length);
/**
 * @brief Finds the minimum value of an array
 *
 * This function return the minimum value of a sorted array
 * , being this value the last element of a sorted array. 
 *
 * @param array[] An array of unsigned char elements
 * @param length The size of the given array

 * @return the minimum value of an array
 */

double find_median(unsigned char array[],int length);
/**
 * @brief Finds the median of a given array
 *
 * This function returns the median of a given array
 * considering the number of elements in the array.
 *
 * @param array[] An array of unsigned char elements
 * @param length The size of the given array

 * @return The median of the given array
 */

void print_statistics(unsigned char A[], int size);
/**
 * @brief Prints the statistical information of a given array
 *
 * This function print statistical information of a given array
 * properly formated for easy visualization.
 *
 * @param array[] An array of unsigned char elements
 * @param length The size of the given array

 * @return Nothing
 */

#endif /* __STATS_H__ */

