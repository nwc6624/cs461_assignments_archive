/*
 * Assignment: PA5
 * Author: Noah Caulfield
 * Date: 11/25/2024
 * Course: CS 461 - Operating Systems
 * University: Eastern New Mexico University
 *
 * Description:
 * This header file declares functions for performing the merge step and the
 * merge sort algorithm on an array of integers. These functions are intended
 * for use in sorting operations as part of the PA5 assignment.
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

/**
 * Merges two sorted subarrays into a single sorted subarray.
 * 
 * @param array A pointer to the array containing the subarrays to merge.
 * @param left The starting index of the left subarray.
 * @param mid The ending index of the left subarray and the start of the right subarray.
 * @param right The ending index of the right subarray.
 */
void merge(int* array, int left, int mid, int right);

/**
 * Recursively performs the merge sort algorithm on a subarray.
 * 
 * @param array A pointer to the array to be sorted.
 * @param left The starting index of the subarray to sort.
 * @param right The ending index (inclusive) of the subarray to sort.
 */
void merge_sort(int* array, int left, int right);

#endif // MERGE_SORT_H
