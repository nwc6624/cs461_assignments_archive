// merge_sort.cc

/*Author: Noah Caulfield
 Date: 10/20/2024
 Class: CS 461 - Operating Systems
 Institution: Eastern New Mexico University
 Assignment: PA4-threads
 */

#include "merge_sort.h"
#include <iostream>
#include <vector>

void merge(int* array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = array[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            ++i;
        } else {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        array[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        array[k] = R[j];
        ++j;
        ++k;
    }
}

void merge_sort(int* array, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);
    merge(array, left, mid, right);
}
