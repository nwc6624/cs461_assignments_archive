/*
 * Assignment: PA5
 * Author: Noah Caulfield
 * Date: 11/25/2024
 * Course: CS 461 - Operating Systems
 * University: Eastern New Mexico University
 *
 * Description:
 * This file provides the implementation of sorting operations for data segments.
 * The functions include a segment-based sort using the STL `std::sort` and a 
 * merge operation for combining sorted segments into a single sorted sequence.
 */

#include "sort.h"
#include <iostream>
#include <algorithm>

/**
 * Sorts a segment of an integer array in place.
 * 
 * @param data A pointer to the array containing the data to sort.
 * @param start The starting index of the segment to sort.
 * @param end The ending index (exclusive) of the segment to sort.
 */
void segment_sort(int* data, int start, int end) {
    std::sort(data + start, data + end);
}

/**
 * Merges sorted segments of an integer array into a single sorted sequence.
 * 
 * @param data A pointer to the array containing the sorted segments.
 * @param segment_size The size of each individual segment.
 * @param num_segments The number of segments to merge.
 */
void merge_segments(int* data, int segment_size, int num_segments) {
    int start = 0;
    for (int i = 1; i < num_segments; ++i) {
        int mid = i * segment_size;
        int end = (i + 1) * segment_size;
        std::inplace_merge(data + start, data + mid, data + end);
    }
}
