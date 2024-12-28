## Makefile

# Author: Noah Caulfield
# Date: 10/20/2024
# Class: CS 461 - Operating Systems
# Institution: Eastern New Mexico University
# Assignment: PA4 - Thread-based Sorting

CC = g++
CFLAGS = -Wall -Iinclude
TARGET = thread

SRC_DIR = src
INCLUDE_DIR = include
SRCS = $(SRC_DIR)/shared_thread.cc $(SRC_DIR)/merge_sort.cc
OBJS = shared_thread.o merge_sort.o

all: $(TARGET)

# Explicitly following Essa's specified compilation command
$(TARGET): $(SRCS)
	$(CC) -o $(TARGET) $(SRCS) -I$(INCLUDE_DIR) -lpthread

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
