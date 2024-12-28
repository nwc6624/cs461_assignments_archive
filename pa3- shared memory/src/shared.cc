//shared.cc

/*Author: Noah Caulfield
 Date: 10/20/2024
 Class: CS 461 - Operating Systems
 Institution: Eastern New Mexico University
 Assignment: PA3-shared memory
*/

#include <iostream>
#include <limits>  // Add this to use std::numeric_limits
#include <sys/types.h>
#include <sys/wait.h>
#include "shared_memory.h"
#include "sort.h"

#define NUM_PROCESSES 8

int main() {
    int share_key_in;
    pid_t children[NUM_PROCESSES];
    
    // Print instructions to the user
    std::cout << " " << std::endl; // Spacing 
    std::cout << "Please enter a sequence of integers, one after another." << std::endl;
    std::cout << "End your input by entering a '0' to signify the end, then press ENTER." << std::endl;
    std::cout << "Leave spaces between each number until finished, or press ENTER after every input." << std::endl;
    std::cout << " " << std::endl; // Spacing 

    // Get and attach shared memory
    share_key_in = create_shared_memory();
    if (share_key_in == -1) return 1;
    int* in = attach_shared_memory(share_key_in);
    if (in == nullptr) return 1;

    int i = -1, j;
    bool done = false;

    // Read input data with validation
    while (!done) {
        std::cout << "Enter a number: ";
        if (!(std::cin >> j)) { // Check if input is not an integer
            std::cin.clear(); // Clear the error flag on cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        } else {
            if (j == 0) {
                done = true;
            } else {
                in[++i] = j;
            }
        }
    }

    // Print the unsorted data
    std::cout << "\nYou entered the following numbers (unsorted):\n";
    print_array(in, i);

    int num_elements = i + 1;
    int segment_size = num_elements / NUM_PROCESSES;

    // Inform the user about the sorting process
    std::cout << "\nSorting in progress...\n";
    std::cout << "The data is being divided into " << NUM_PROCESSES 
              << " parts, with each process sorting its assigned portion.\n";

    // Spawn 8 processes for sorting
    for (int k = 0; k < NUM_PROCESSES; ++k) {
        if ((children[k] = fork()) == 0) {
            int start = k * segment_size;
            int end = (k == NUM_PROCESSES - 1) ? num_elements - 1 : start + segment_size - 1;

            in = attach_shared_memory(share_key_in);
            sort(in, start, end);
            return 0;
        }
    }

    // Wait for all child processes
    for (int k = 0; k < NUM_PROCESSES; ++k) {
        int status;
        waitpid(children[k], &status, 0);
    }

    // Merge sorted parts
    merge_segments(in, segment_size, NUM_PROCESSES);

    // Print the sorted data
    std::cout << "\nSorting complete. The sorted numbers are:\n";
    print_array(in, i);

    // Cleanup shared memory
    cleanup_shared_memory(share_key_in);

    return 0;
}
