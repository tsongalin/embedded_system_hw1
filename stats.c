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
 * @brief print the statistics of array 
 *
 *
 * @author Sung Hao Lin
 * @date 07/03/2023 
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  printf("Array statistics: \n");
  print_statistics(test);
  printf("Origial array = \n[");
  print_array(5, test);
  printf("]\n");
  printf("Sorted Array = \n[");
  print_array(5, sort_array(test));
  printf("]\n");

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  return 0;

}

unsigned char *sort_array(unsigned char *test){
	unsigned char *new_array = malloc(SIZE);
	for(int i=0; i<SIZE; i++)
		new_array[i] = test[i];
	int temp;
	for(int i=0; i<SIZE-1; i++)
		for(int j=i+1;j<SIZE; j++){
			if(new_array[i]<new_array[j]){
				temp = new_array[i];
				new_array[i] = new_array[j];
				new_array[j] = temp;
			}
		}
	return new_array;
}

void print_statistics(unsigned char* test){
	printf("The array size is %d\n", SIZE);
	printf("Max is %d\n", find_max(test, SIZE));
	printf("Min is %d\n", find_min(test, SIZE));
	printf("Mean is %d\n", find_mean(test, SIZE));
	printf("Median is %d\n", find_median(test));
}

unsigned char find_median(unsigned char* test){
	if(SIZE%2 !=1){
		return ((float)sort_array(test)[SIZE/2 - 1] + (float)sort_array(test)[SIZE/2])
			/ 2;
	}
	else
		return sort_array(test)[(int)(SIZE/2)];
}

unsigned char find_max(unsigned char* test, int length){
	int max = test[0];
	if(length > SIZE){
		printf("Entered length is greater than max length %d\n", SIZE);
		return 0;
	}
	for(int i=0; i<length; i++)
		if(test[i] > max)
			max = test[i];
	return max;
}

unsigned char find_min(unsigned char* test, int length){
	int min = test[0];
	for(int i=0; i<SIZE; i++)
		if(test[i] < min)
			min = test[i];
	return min;
}

unsigned char find_mean(unsigned char* test, int length){
	int mean = 0;
	for(int i=0; i<SIZE; i++)
		mean = mean + test[i];
	mean = mean / SIZE;
	return mean;
}

void print_array(int length, unsigned char* test){
	if(SIZE%length!=0){
	       	printf("Error!\n");
		return;
	}
	for(int i=0; i<SIZE/length; i++){
		for(int j=0; j<length; j++)
			printf("%d ", test[i*(length)+j]);
		printf("\n");
	}
}

/* Add other Implementation File Code Here */
