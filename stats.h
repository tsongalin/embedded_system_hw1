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
 * @file stats.h>
 * @brief header file of array statistics 
 *
 * Branch header file
 *
 * This is the header file in branch dev_c1m1
 *
 * @author Sung Hao Lin
 * @date 07/03/2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

// print the statistics of the array. Input is the unsigned char array and it will print out the max, min, median, and mean value.
void print_statistics(unsigned char *test );

// print out the array. user has to provide the elements per line and array input. it will print out the array
void print_array(int length, unsigned char *test);

// this method will find and return the max elements in the array. Note that you can find the max value in the first n elements. 
unsigned char find_max(unsigned char *test, int length);

// this method will find and return the min elements in the array. Note that you can find the min value in the first n elements.
unsigned char find_min(unsigned char *test, int length);

// this method will find and return the mean value of the array. Note that you can find the mean value of the first n elements.
unsigned char find_mean(unsigned char *test, int length);

// this method will find the median of the array. Input is the unsigned char array
unsigned char find_median(unsigned char *test);

// this method will sort and return the descending array. the input is unsigned char array and output is unsigned char array.
unsigned char *sort_array(unsigned char *test);





#endif /* __STATS_H__ */
