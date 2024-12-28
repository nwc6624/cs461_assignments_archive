CC = g++
CFLAGS = -Wall -g -std=c++17
INCLUDE = -Iinclude
OBJDIR = obj
SRCDIR = src

all: shared_sort

shared_sort: $(OBJDIR)/shared.o $(OBJDIR)/shared_memory.o $(OBJDIR)/sort.o
	$(CC) $(CFLAGS) $(INCLUDE) -o shared_sort $(OBJDIR)/shared.o $(OBJDIR)/shared_memory.o $(OBJDIR)/sort.o

$(OBJDIR)/shared.o: $(SRCDIR)/shared.cc
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCDIR)/shared.cc -o $(OBJDIR)/shared.o

$(OBJDIR)/shared_memory.o: $(SRCDIR)/shared_memory.cc
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCDIR)/shared_memory.cc -o $(OBJDIR)/shared_memory.o

$(OBJDIR)/sort.o: $(SRCDIR)/sort.cc
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCDIR)/sort.cc -o $(OBJDIR)/sort.o

clean:
	rm -f shared_sort $(OBJDIR)/*.o
	rm -f timing_results.csv
