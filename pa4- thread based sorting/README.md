
# PA4: Thread-based Sorting Program

## Author
**Noah Caulfield**

**Date:** 10/20/2024  
**Class:** CS 461 - Operating Systems  
**Institution:** Eastern New Mexico University  
**Assignment:** PA4 - Thread-based Sorting

---

## Overview
This program implements a multithreaded sorting algorithm using the merge sort technique. The program dynamically allocates memory for the input array, sorts it using multiple threads, and merges the sorted sections to produce a final sorted array. The user can input an array of integers, and the input terminates when `0` is entered. The sorted array is then printed to the console.

## Features
- Dynamically reads integer input from the user, with `0` as the sentinel value to end input.
- Utilizes multiple threads to perform sorting on sections of the array using merge sort.
- Efficiently merges sorted sections to produce the final sorted array.
- Handles any number of integers and automatically adjusts the number of threads (up to 8) based on the input size.

## Files
- **src/shared_thread.cc**: Main source file containing the logic for multithreaded sorting.
- **src/merge_sort.cc**: Contains the `merge_sort` and `merge` functions for sorting and merging array sections.
- **include/sort.h**: Header file that declares the `merge_sort` and `merge` functions.
- **Makefile**: Used to compile, run, and clean the project.

## How to Compile and Run

1. **Compiling the Program:**
   Open the terminal and navigate to the project directory, then run:
   ```bash
   make
   ```

2. **Running the Program:**
   After compiling, you can run the program with:
   ```bash
   make run
   ```
   The program will prompt you to enter integers. Enter numbers one by one, and type `0` to finish input and trigger the sorting process.

3. **Cleaning the Project:**
   To remove the compiled executable, run:
   ```bash
   make clean
   ```

## Example Usage

```bash
$ make run
./thread_sort
Enter integers (0 to finish):
12
34
56
23
89
45
0
Sorted array: 12 23 34 45 56 89
```

## Notes
- The program supports up to 8 threads for sorting. If the number of integers entered is less than 8, it will dynamically adjust the number of threads used.
- The input ends when the user enters `0`, which is not included in the sorted array.

