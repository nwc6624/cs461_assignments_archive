# Directories for PA3 and PA4
PA3_DIR := pa3
PA4_DIR := pa4

# PA3 Targets
PA3_OBJ := $(PA3_DIR)/obj/shared.o $(PA3_DIR)/obj/sort.o $(PA3_DIR)/obj/shared_memory.o
PA3_BIN := $(PA3_DIR)/bin/shared_sort

# PA4 Targets
PA4_OBJ := $(PA4_DIR)/obj/shared_thread.o $(PA4_DIR)/obj/merge_sort.o
PA4_BIN := $(PA4_DIR)/bin/shared_sort

# Compiler and Flags
CXX := g++
CXXFLAGS := -Wall -g -std=c++17 -pthread -Iinclude -Ipa3/include -Ipa4/include

# Default target: build both PA3 and PA4
all: pa3 pa4

# Build PA3
pa3: $(PA3_BIN)

$(PA3_BIN): $(PA3_OBJ)
	mkdir -p $(PA3_DIR)/bin
	$(CXX) $(CXXFLAGS) $^ -o $@

$(PA3_DIR)/obj/%.o: $(PA3_DIR)/src/%.cc
	mkdir -p $(PA3_DIR)/obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build PA4
pa4: $(PA4_BIN)

$(PA4_BIN): $(PA4_OBJ)
	mkdir -p $(PA4_DIR)/bin
	$(CXX) $(CXXFLAGS) $^ -o $@

$(PA4_DIR)/obj/%.o: $(PA4_DIR)/src/%.cc
	mkdir -p $(PA4_DIR)/obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean both PA3 and PA4
clean:
	rm -rf $(PA3_DIR)/obj $(PA3_DIR)/bin $(PA4_DIR)/obj $(PA4_DIR)/bin

# Run PA3 and PA4 workloads
run: all
	@echo "Running PA3..."
	$(PA3_BIN)
	@echo "Running PA4..."
	$(PA4_BIN)

# Validation for required files
check:
	@echo "Validating required files..."
	@if [ ! -f $(PA3_DIR)/src/shared.cc ] || [ ! -f $(PA3_DIR)/src/sort.cc ] || [ ! -f $(PA3_DIR)/src/shared_memory.cc ] || \
	    [ ! -f $(PA4_DIR)/src/shared_thread.cc ] || [ ! -f $(PA4_DIR)/src/merge_sort.cc ]; then \
	    echo "Error: Required source files are missing."; \
	    exit 1; \
	fi
	@echo "All required files found!"
