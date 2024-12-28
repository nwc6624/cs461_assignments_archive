
# CS 461: Operating Systems Assignments Archive

An archive of various programming assignments (PAs) and semester project parts (PSs) from **CS 461: Operating Systems**, taken during the Fall 2024 semester at **Eastern New Mexico University**.  

This repository contains solutions and implementations showcasing key concepts in operating systems, including process management, file systems, memory management, and inter-process communication. Each folder corresponds to an individual assignment (PA) or project segment (PS).  

---

## Course Description  
> *"Theory of operating systems. Topics include processes, file systems, memory management and I/O."*  

**Prerequisites:** CS 357 (or concurrent enrollment) and EET 340.

---

## Repository Example Structure  

**Note, not all projects are listed below**

- **PA3 - Shared Memory Sorting:**  
  Program that uses shared memory to implement sorting algorithms. Demonstrates inter-process communication and memory sharing.

- **PA4 - Thread-Based Sorting:**  
  Extends the PA3 sorting program by replacing shared memory with threads to explore multi-threading and synchronization.

- **PA5 - Unified Memory Workload Testing:**  
  Combines results from PA3 and PA4 to analyze performance with varying workload sizes, generating statistical graphs for comparison.

- **PS4 - Shell with Piping:**  
  Enhances a basic shell program to support I/O redirection and piping, allowing chaining of commands (e.g., `cat file.txt | grep pattern`).

- **PA6 - Page Table Simulation:**  
  Implements a page table simulator using the LRU algorithm, simulating memory operations and reporting statistics like page hit ratio and fault ratio.

---

## How to Use  

Each folder contains:  

- **Source Code:** Implementations written in C++ or other relevant languages.  
- **Makefile:** For compiling the programs.  
- **README:** Folder-specific instructions and details about the assignment.  

To run a specific program:  

1. Navigate to the respective folder.  
2. Compile the program using `make`.  
3. Execute the program as per the instructions in the folder's README.  

---
