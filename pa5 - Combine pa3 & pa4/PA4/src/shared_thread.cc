// shared_thread.cc

/*
    Author: Noah Caulfield
    Date: 10/30/2024
    Class: CS 461 - Operating Systems
    Institution: Eastern New Mexico University
    Assignment: PA4 - threads
*/
#include "merge_sort.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>
#include <sys/resource.h>
#include <sys/time.h>

void thread_sort(int* data, int start, int end) {
    merge_sort(data, start, end);
}

void measure_time(int workload_size, std::ofstream& csv_file) {
    struct rusage usage_start, usage_end;
    struct timeval start_time, end_time;

    // Allocate local array
    int* local_data = new int[workload_size];
    for (int i = 0; i < workload_size; ++i) {
        local_data[i] = rand() % 1000;  // Generate random data
    }

    gettimeofday(&start_time, nullptr);
    getrusage(RUSAGE_THREAD, &usage_start);

    const int num_threads = 8;
    int segment_size = workload_size / num_threads;
    std::vector<std::thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        int start = i * segment_size;
        int end = (i == num_threads - 1) ? workload_size - 1 : (start + segment_size - 1);
        threads.emplace_back(thread_sort, local_data, start, end);
    }

    for (auto& t : threads) {
        t.join();
    }

    for (int i = 1; i < num_threads; ++i) {
        merge(local_data, 0, (i * segment_size) - 1, std::min(((i + 1) * segment_size) - 1, workload_size - 1));
    }

    gettimeofday(&end_time, nullptr);
    getrusage(RUSAGE_THREAD, &usage_end);

    double user_time = (usage_end.ru_utime.tv_sec - usage_start.ru_utime.tv_sec) +
                       (usage_end.ru_utime.tv_usec - usage_start.ru_utime.tv_usec) / 1e6;
    double system_time = (usage_end.ru_stime.tv_sec - usage_start.ru_stime.tv_sec) +
                         (usage_end.ru_stime.tv_usec - usage_start.ru_stime.tv_usec) / 1e6;
    double total_time = (end_time.tv_sec - start_time.tv_sec) +
                        (end_time.tv_usec - start_time.tv_usec) / 1e6;

    csv_file << workload_size << "," << user_time << "," << system_time << "," << total_time << "\n";

    delete[] local_data;
}

int main() {
    const int workloads[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};
    std::ofstream csv_file("thread_timing_results.csv");
    csv_file << "Workload Size,User Time,System Time,Total Time\n";

    for (int size : workloads) {
        std::cout << "Running workload size: " << size << "\n";
        measure_time(size, csv_file);
    }

    csv_file.close();
    return 0;
}
