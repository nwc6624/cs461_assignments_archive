// shared_thread.cc

/*
    Author: Noah Caulfield
    Date: 10/20/2024
    Class: CS 461 - Operating Systems
    Institution: Eastern New Mexico University
    Assignment: PA4 - threads
*/


#include <iostream>
#include <vector>
#include <pthread.h>
#include "sort.h"

#define MAX_THREADS 8  // Maximum number of threads

struct ThreadArgs {
    int* array;
    int left;
    int right;
};

// Thread function for merge sort
void* merge_sort_thread(void* arg) {
    ThreadArgs* args = static_cast<ThreadArgs*>(arg);
    merge_sort(args->array, args->left, args->right);
    pthread_exit(nullptr);
}

int main() {
    std::vector<int> input_array;
    int num;

    // Read input from user, end input when 0 is entered
    std::cout << "Enter integers (0 to finish):" << std::endl;
    while (true) {
        std::cin >> num;
        if (num == 0) break;  // Terminate input when 0 is entered
        input_array.push_back(num);  // Store valid input in vector
    }

    int array_size = input_array.size();
    if (array_size == 0) {
        std::cerr << "No numbers entered!" << std::endl;
        return 1;
    }

    // Dynamically allocate the array
    int* array = new int[array_size];
    for (int i = 0; i < array_size; ++i) {
        array[i] = input_array[i];
    }

    // Calculate the number of threads to use
    int num_threads = (array_size < MAX_THREADS) ? array_size : MAX_THREADS;
    pthread_t threads[num_threads];
    ThreadArgs thread_args[num_threads];
    int part_size = array_size / num_threads;

    // Create threads for sorting
    for (int i = 0; i < num_threads; i++) {
        int left = i * part_size;
        int right = (i == num_threads - 1) ? (array_size - 1) : (left + part_size - 1);
        thread_args[i] = {array, left, right};
        pthread_create(&threads[i], nullptr, merge_sort_thread, &thread_args[i]);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], nullptr);
    }

    // Merge sorted sections one by one
    for (int i = 1; i < num_threads; i++) {
        int left = 0;
        int right = (i == num_threads - 1) ? (array_size - 1) : ((i + 1) * part_size - 1);
        int mid = (i * part_size) - 1;
        merge(array, left, mid, mid + 1, right);
    }

    // Print sorted array
    std::cout << "Sorted array: ";
    for (int i = 0; i < array_size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete[] array;
    return 0;
}
