# Noah Caulfield
# 10/10/2024
# Class: CS 461, Operating systems at Eastern New Mexico University 
# Assignment PA2 Signal Handler Routine

# Makefile for handler.cc

CXX = g++
CXXFLAGS = -Wall -std=c++11
TARGET = handler

all: $(TARGET)

$(TARGET): handler.cc
	$(CXX) $(CXXFLAGS) -o $(TARGET) handler.cc

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
