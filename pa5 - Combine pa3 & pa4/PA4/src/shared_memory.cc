//shared_memory.cc

/*Author: Noah Caulfield
 Date: 10/20/2024
 Class: CS 461 - Operating Systems
 Institution: Eastern New Mexico University
 Assignment: PA4
*/

#include "shared_memory.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
// Function to create a shared memory segment
int create_shared_memory() {
    // Request a shared memory segment with size MAXNUM * sizeof(int)
    // IPC_CREAT: Create the segment if it doesn't exist
    // 0666: Read and write permissions for the segment
    int share_key_in = shmget(IPC_PRIVATE, MAXNUM * sizeof(int), IPC_CREAT | 0666);
    
    // Check if the shared memory segment was created successfully
    if (share_key_in < 0) {
        std::cerr << "Cannot get shared memory" << std::endl;
        return -1; // Return error code if creation fails
    }
    return share_key_in; // Return the shared memory ID
}

// Function to attach the shared memory to the process
int* attach_shared_memory(int share_key_in) {
    // Attach the shared memory segment identified by share_key_in
    int* in = (int *)shmat(share_key_in, nullptr, SHM_RND);
    
    // Check if the attachment was successful
    if (in == (void *)-1) {
        std::cerr << "Cannot attach to shared memory" << std::endl;
        return nullptr; // Return null if attachment fails
    }
    return in; // Return the pointer to the shared memory
}

// Function to clean up and remove the shared memory segment
void cleanup_shared_memory(int share_key_in) {
    struct shmid_ds item; // Data structure to hold shared memory info
    
    // Mark the shared memory segment for removal
    shmctl(share_key_in, IPC_RMID, &item);
}
