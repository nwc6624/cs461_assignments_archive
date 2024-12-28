# Shared Memory Sorting Program

**Author:** Noah Caulfield
**Date:** 10/20/2024
**Class:** CS 461 - Operating Systems
**Institution:** Eastern New Mexico University
**Assignment:** PA3-shared memory

## Overview
This C++ program demonstrates how to use **shared memory** and **processes** for sorting an array of integers. The program reads a series of integers from the user, stores them in shared memory, and spawns multiple processes (8 in total) to sort the array in parallel using merge sort. Each process sorts a portion of the array, and the results are merged into a single sorted array.

## Features
- **Shared Memory**: The program uses shared memory to store the array of integers.
- **Process Parallelism**: It spawns 8 child processes, each responsible for sorting a portion of the array.
- **Input Validation**: The program ensures that only valid integers are accepted as input.
- **Merge Sort**: After sorting, the portions are merged to produce the final sorted array.

## How to Use

### Compilation
To compile the program, navigate to the project directory and use the `make` command:


```make``` 

This will compile the C++ source files and create an executable named shared_sort.

### Running the Program
To run the program, use the following command:

```make run```

The program will prompt you to enter a sequence of integers. End the input by typing 0 and pressing ENTER. Invalid inputs (like characters or excessively large numbers) will be rejected, and you'll be prompted to enter valid integers.

Execution Example: :
```
Please enter a sequence of integers, one after another.
End your input by entering a '0' to signify the end, then press ENTER.
Leave spaces between each number until finished.

Enter a number: 5
Enter a number: 3
Enter a number: 99
Enter a number: 0

You entered the following numbers (unsorted):
5
3
99

Sorting in progress...
The data is being divided into 8 parts, with each process sorting its assigned portion.

Sorting complete. The sorted numbers are:
3
5
99
```


### Cleaning Up
To remove the compiled executable and clean up your directory, use the make clean command:


```make clean```

### Code Structure
The project is structured into multiple files for better organization:

***src/shared.cc***: Main program file that handles input, process management, and shared memory.
***src/sort.cc***: Contains the sorting and merging functions.
***src/shared_memory.cc***: Handles the setup and cleanup of shared memory.
***include/sort.h***: Header file for sorting function declarations.
***include/shared_memory.h***: Header file for shared memory function declarations.
***Makefile***: Used to compile and run the program efficiently.
Dependencies
This program requires a C++ compiler that supports the standard libraries used in the program, such as g++. It is tested and works in Linux environments, particularly with WSL (Windows Subsystem for Linux).