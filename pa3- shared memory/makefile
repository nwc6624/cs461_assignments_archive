#Makefile
# Makefile for compiling shared memory sorting program with multiple source files

#Author: Noah Caulfield
# Date: 10/20/2024
# Class: CS 461 - Operating Systems
# Institution: Eastern New Mexico University
# Assignment: PA3-shared memory


CC = g++
CFLAGS = -Wall -Iinclude
TARGET = shared_sort

SRC_DIR = src
INCLUDE_DIR = include
SRCS = $(SRC_DIR)/shared.cc $(SRC_DIR)/sort.cc $(SRC_DIR)/shared_memory.cc
OBJS = shared.o sort.o shared_memory.o

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
