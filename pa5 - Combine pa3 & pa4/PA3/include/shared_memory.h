// shared_memory.h

/* 
 * Assignment: PA5
 * Author: Noah Caulfield
 * Date: 11/25/2024
 * Course: CS 461 - Operating Systems
 * University: Eastern New Mexico University
 *
 *
 * Description:
 * This header file defines constants and functions for managing shared memory
 * in the context of the PA3-shared memory assignment. It provides the interface
 * for creating, attaching, and cleaning up shared memory segments.
 */

#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

// The size of the shared memory segment in bytes, calculated as the size of
// 4096 integers. This value determines the capacity of the shared memory segment.
#define SHARED_MEMORY_SIZE 4096 * sizeof(int)

// Function prototypes:

/**
 * Creates a shared memory segment and returns the shared memory ID (shmid).
 * 
 * @return The shared memory ID (shmid) on success, or -1 on failure.
 */
int create_shared_memory();

/**
 * Attaches to the shared memory segment identified by the given shmid.
 * 
 * @param shmid The shared memory ID of the segment to attach to.
 * @return A pointer to the shared memory segment on success, or NULL on failure.
 */
int* attach_shared_memory(int shmid);

/**
 * Cleans up the shared memory segment by marking it for deletion.
 * 
 * @param shmid The shared memory ID of the segment to be deleted.
 */
void cleanup_shared_memory(int shmid);

#endif // SHARED_MEMORY_H
