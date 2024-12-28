/*
 * Assignment: PA4-threads
 * Author: Noah Caulfield
 * Date: 10/20/2024
 * Course: CS 461 - Operating Systems
 * University: Eastern New Mexico University
 *
 * Description:
 * This header file declares functions for performing merge sort and merging
 * operations on an integer array. These functions are designed for use in
 * multi-threaded sorting operations as part of the PA4 assignment.
 */

#ifndef SORT_H
#define SORT_H

/**
 * Recursively performs the merge sort algorithm on a subarray.
 * 
 * @param in A pointer to the array to be sorted.
 * @param loc1 The starting index of the subarray to sort.
 * @param loc2 The ending index (inclusive) of the subarray to sort.
 */
void merge_sort(int* in, int loc1, int loc2);

/**
 * Merges two sorted subarrays into a single sorted subarray.
 * 
 * @param in A pointer to the array containing the subarrays to merge.
 * @param loc1 The starting index of the first subarray.
 * @param loc2 The ending index of the first subarray.
 * @param loc3 The starting index of the second subarray.
 * @param loc4 The ending index of the second subarray.
 */
void merge(int* in, int loc1, int loc2, int loc3, int loc4);

#endif // SORT_H
