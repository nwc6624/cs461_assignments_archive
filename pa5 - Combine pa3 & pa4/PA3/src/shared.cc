/*
 * Assignment: PA5
 * Author: Noah Caulfield
 * Date: 11/25/2024
 * Course: CS 461 - Operating Systems
 * University: Eastern New Mexico University
 *
 * Description:
 * This program measures the performance of sorting workloads of various sizes using
 * shared memory and multiple processes. It generates random data, sorts it using
 * child processes, merges sorted segments, and measures execution time (user, system,
 * and total). The results are output to the console and saved to a CSV file.
 */

#include "shared_memory.h"
#include "sort.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Function to generate random data
void generate_random_data(int* data, int size) {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 1000 + 1; // Random integers between 1 and 1000
    }
}

// Function to measure execution time for a specific workload
void measure_time(int workload_size, std::ofstream& csv_file) {
    struct rusage usage_start, usage_end;
    struct timeval start_time, end_time;

    // Step 1: Generate random data
    int* shared_data = attach_shared_memory(create_shared_memory());
    generate_random_data(shared_data, workload_size);

    // Step 2: Record start time
    gettimeofday(&start_time, nullptr);
    getrusage(RUSAGE_CHILDREN, &usage_start);

    // Step 3: Perform sorting using processes
    const int segment_size = workload_size / 8;
    for (int i = 0; i < 8; ++i) {
        pid_t pid = fork();
        if (pid == 0) { // Child process
            int start = i * segment_size;
            int end = (i == 7) ? workload_size : (i + 1) * segment_size; // Handle remainder
            segment_sort(shared_data, start, end);
            exit(0); // Ensure child exits after sorting
        } else if (pid < 0) {
            std::cerr << "Error: Fork failed\n";
            cleanup_shared_memory(0);
            exit(1);
        }
    }

    // Wait for all child processes to complete
    for (int i = 0; i < 8; ++i) {
        wait(nullptr);
    }

    // Step 4: Merge sorted segments
    merge_segments(shared_data, segment_size, 8);

    // Step 5: Record end time
    gettimeofday(&end_time, nullptr);
    getrusage(RUSAGE_CHILDREN, &usage_end);

    // Step 6: Calculate time differences
    double user_time = (usage_end.ru_utime.tv_sec - usage_start.ru_utime.tv_sec) +
                       (usage_end.ru_utime.tv_usec - usage_start.ru_utime.tv_usec) / 1e6;
    double system_time = (usage_end.ru_stime.tv_sec - usage_start.ru_stime.tv_sec) +
                         (usage_end.ru_stime.tv_usec - usage_start.ru_stime.tv_usec) / 1e6;
    double total_time = (end_time.tv_sec - start_time.tv_sec) +
                        (end_time.tv_usec - start_time.tv_usec) / 1e6;

    // Output timing results to the console
    std::cout << "Workload Size: " << workload_size << "\n";
    std::cout << "User Time: " << user_time << " s\n";
    std::cout << "System Time: " << system_time << " s\n";
    std::cout << "Total Time: " << total_time << " s\n";
    std::cout << "----------------------------------\n";

    // Write results to the CSV file
    csv_file << workload_size << "," << user_time << "," << system_time << "," << total_time << "\n";

    // Clean up shared memory
    cleanup_shared_memory(0);
}

int main() {
    // Array of workload sizes for testing
    const int workloads[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};

    // Open the CSV file for writing
    std::ofstream csv_file("timing_results.csv");
    if (!csv_file) {
        std::cerr << "Error: Could not open results file.\n";
        return 1;
    }
    csv_file << "Workload Size,User Time,System Time,Total Time\n";

    // Loop through each workload size and measure performance
    for (int workload_size : workloads) {
        std::cout << "Running workload size: " << workload_size << std::endl;
        measure_time(workload_size, csv_file);
    }

    csv_file.close();
    return 0;
}
