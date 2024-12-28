// sort.h

/*Author: Noah Caulfield
 Date: 10/20/2024
 Class: CS 461 - Operating Systems
 Institution: Eastern New Mexico University
 Assignment: PA3-shared memory
*/

#ifndef SORT_H
#define SORT_H

// Maximum number of elements in the array to be sorted
#define MAXNUM 10000

// Function to merge two sorted subarrays of an array
void merge(int* in, int loc1, int loc2, int loc3, int loc4);

// Function to sort a subarray of an array using merge sort
void sort(int* in, int loc1, int loc2);

// Function to merge sorted segments of an array
void merge_segments(int* in, int segment_size, int num_segments);

// Function to print an array of integers
void print_array(int* in, int size);

#endif