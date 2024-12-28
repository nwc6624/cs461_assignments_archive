//shared_memory.h

/*Author: Noah Caulfield
 Date: 10/20/2024
 Class: CS 461 - Operating Systems
 Institution: Eastern New Mexico University
 Assignment: PA4
*/

#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

// Maximum number of elements in the shared memory array
#define MAXNUM 10000

// Function to create a shared memory segment
int create_shared_memory();

// Function to attach the shared memory segment to the current process
int* attach_shared_memory(int share_key_in);

// Function to detach the shared memory segment from the current process and remove it
void cleanup_shared_memory(int share_key_in);

#endif