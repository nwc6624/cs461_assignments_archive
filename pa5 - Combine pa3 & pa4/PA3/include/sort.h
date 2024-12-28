// sort.h

/* 
 * Assignment: PA5
 * Author: Noah Caulfield
 * Date: 11/25/2024
 * Course: CS 461 - Operating Systems
 * University: Eastern New Mexico University
 *
 * Description:
 * This header file declares functions for sorting and merging segments of data
 * in memory. These functions are designed to support multi-threaded or shared
 * memory-based sorting operations for the PA5 assignment.
 */

#ifndef SORT_H
#define SORT_H

// Function prototypes:

/**
 * Sorts a segment of an integer array in place using a sorting algorithm.
 * 
 * @param data A pointer to the array containing the data to sort.
 * @param start The starting index of the segment to sort.
 * @param end The ending index (exclusive) of the segment to sort.
 */
void segment_sort(int* data, int start, int end);

/**
 * Merges sorted segments of an integer array into a single sorted sequence.
 * 
 * @param data A pointer to the array containing the sorted segments.
 * @param segment_size The size of each individual segment.
 * @param num_segments The number of segments to merge.
 */
void merge_segments(int* data, int segment_size, int num_segments);

#endif // SORT_H
