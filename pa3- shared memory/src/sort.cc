// sort.cc

/*Author: Noah Caulfield
 Date: 10/20/2024
 Class: CS 461 - Operating Systems
 Institution: Eastern New Mexico University
 Assignment: PA3-shared memory
*/
#include "sort.h"
#include <iostream>
#include <vector>

// Global vector for merging
std::vector<int> out(MAXNUM);

// Function to merge two sorted subarrays of an array
void merge(int* in, int loc1, int loc2, int loc3, int loc4) {
    // Initialize pointers for the two subarrays and the output array
    int i = loc1, j = loc3, insert = loc1;

    // Merge the two subarrays into the output array
    while (i <= loc2 && j <= loc4) {
        if (in[i] > in[j]) {
            out[insert++] = in[j++];
        } else {
            out[insert++] = in[i++];
        }
    }

    // Copy any remaining elements from the first subarray
    while (i <= loc2) {
        out[insert++] = in[i++];
    }

    // Copy any remaining elements from the second subarray
    while (j <= loc4) {
        out[insert++] = in[j++];
    }

    // Copy the merged elements back to the original array
    for (i = loc1; i <= loc4; ++i) {
        in[i] = out[i];
    }
}

// Function to sort a subarray of an array using merge sort
void sort(int* in, int loc1, int loc2) {
    // Base case: If the subarray has only one element, it is already sorted
    if (loc1 >= loc2) return;

    // Divide the subarray into two halves
    int mid = (loc1 + loc2) / 2;

    // Recursively sort the two halves
    sort(in, loc1, mid);
    sort(in, mid + 1, loc2);

    // Merge the sorted halves
    merge(in, loc1, mid, mid + 1, loc2);
}

// Function to merge sorted segments of an array
void merge_segments(int* in, int segment_size, int num_segments) {
    // Start with segments of size segment_size
    int current_size = segment_size;

    // Merge segments until all elements are merged
    for (int step = 1; step < num_segments; ++step) {
        // Merge segments of size current_size
        merge(in, 0, current_size - 1, current_size, current_size + segment_size - 1);

        // Double the size of the segments for the next iteration
        current_size += segment_size;
    }
}

// Function to print an array of integers
void print_array(int* in, int size) {
    // Print each element of the array
    for (int i = 0; i <= size; ++i) {
        std::cout << in[i] << std::endl;
    }
    std::cout << std::endl;
}