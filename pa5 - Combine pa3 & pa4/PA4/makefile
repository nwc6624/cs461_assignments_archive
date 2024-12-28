## Makefile

# Author: Noah Caulfield
# Date: 10/20/2024
# Class: CS 461 - Operating Systems
# Institution: Eastern New Mexico University
# Assignment: PA4 - Thread-based Sorting

# Makefile for PA4

CXX := g++
CXXFLAGS := -Wall -g -std=c++17 -pthread -Iinclude -Ipa4/include
PA4_SRC := pa4/src
PA4_OBJ := pa4/obj
PA4_BIN := pa4/bin

all: $(PA4_BIN)/shared_sort

$(PA4_BIN)/shared_sort: $(PA4_OBJ)/shared_thread.o $(PA4_OBJ)/merge_sort.o
	mkdir -p $(PA4_BIN)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(PA4_OBJ)/%.o: $(PA4_SRC)/%.cc
	mkdir -p $(PA4_OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(PA4_OBJ) $(PA4_BIN)
