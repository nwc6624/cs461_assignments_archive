/*
 * Assignment: PA4
 * Author: Noah Caulfield
 * Date: 10/20/2024
 * Course: CS 461 - Operating Systems
 * University: Eastern New Mexico University
 *
 * Description:
 * This header file defines constants and declares functions for managing shared memory.
 * It includes functionality for creating, attaching, and cleaning up shared memory segments,
 * specifically designed for the PA4 assignment.
 */

#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

// Maximum number of elements in the shared memory array
#define MAXNUM 10000

/**
 * Creates a shared memory segment and returns the shared memory ID (shm_id).
 * 
 * @return The shared memory ID (shm_id) on success, or -1 on failure.
 */
int create_shared_memory();

/**
 * Attaches to the shared memory segment identified by the given shm_id.
 * 
 * @param shm_id The shared memory ID of the segment to attach to.
 * @return A pointer to the shared memory segment on success, or NULL on failure.
 */
int* attach_shared_memory(int shm_id);

/**
 * Cleans up the shared memory segment by marking it for deletion.
 * 
 * @param shm_id The shared memory ID of the segment to be deleted.
 */
void cleanup_shared_memory(int shm_id);

#endif // SHARED_MEMORY_H
