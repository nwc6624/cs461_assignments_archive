#!/bin/bash

# Directory to store workloads
WORKLOAD_DIR="./workloads"

# Ensure the directory exists
mkdir -p "$WORKLOAD_DIR"

# Sizes for the workloads
sizes=(2 4 8 16 32 64 128 256 512 1024 2048 4096)

# Generate workloads with larger numbers
echo "Generating enhanced workloads with larger random integers..."
for size in "${sizes[@]}"; do
    workload_file="$WORKLOAD_DIR/workload_${size}.txt"
    seq $size | awk '{print int(rand() * 100000000 + 10000000)}' > "$workload_file"
    echo "Generated $workload_file with $size random numbers."
done

echo "Workload generation complete. Workloads saved in $WORKLOAD_DIR."
