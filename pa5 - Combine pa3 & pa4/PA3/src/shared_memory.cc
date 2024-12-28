// shared_memory.cc

/* 
 * Assignment: PA5
 * Author: Noah Caulfield
 * Date: 11/25/2024
 * Course: CS 461 - Operating Systems
 * University: Eastern New Mexico University
 *
 * Description:
 * This implementation file contains the definitions for functions that manage
 * shared memory creation, attachment, and cleanup. It is part of the PA5 assignment.
 */

#include "shared_memory.h"
#include <iostream>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <cstring>
#include <cstdlib>

/**
 * Creates a shared memory segment and returns the shared memory ID (shmid).
 * 
 * @return The shared memory ID (shmid) on success, or exits the program on failure.
 */
int create_shared_memory() {
    int shmid = shmget(IPC_PRIVATE, SHARED_MEMORY_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        std::cerr << "Error: Unable to create shared memory.\n";
        exit(1);
    }
    return shmid;
}

/**
 * Attaches to the shared memory segment identified by the given shmid.
 * 
 * @param shmid The shared memory ID of the segment to attach to.
 * @return A pointer to the shared memory segment on success, or exits the program on failure.
 */
int* attach_shared_memory(int shmid) {
    int* shared_memory = (int*)shmat(shmid, nullptr, 0);
    if (shared_memory == (int*)-1) {
        std::cerr << "Error: Unable to attach shared memory.\n";
        exit(1);
    }
    return shared_memory;
}

/**
 * Cleans up the shared memory segment by marking it for deletion.
 * 
 * @param shmid The shared memory ID of the segment to be deleted.
 */
void cleanup_shared_memory(int shmid) {
    if (shmid > 0) {
        shmctl(shmid, IPC_RMID, nullptr);
    }
}
