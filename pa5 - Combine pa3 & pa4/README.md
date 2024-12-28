<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PA5 README</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 20px;
        }
        code {
            background-color: #f4f4f4;
            padding: 2px 4px;
            border-radius: 4px;
        }
        pre {
            background-color: #f4f4f4;
            padding: 10px;
            border-radius: 4px;
            overflow-x: auto;
        }
        h1, h2, h3 {
            color: #333;
        }
        ul {
            margin: 10px 0;
        }
    </style>
</head>
<body>
 <h1>PA5: Combined PA3 and PA4 Workflows</h1>
    <h2>Overview</h2>
    <p><strong>Author:</strong> Noah Caulfield</p>
    <p><strong>Date:</strong> 11/25/2024</p>
    <p><strong>Assignment:</strong> PA5</p>
    <p><strong>Course:</strong> CS 461 - Operating Systems</p>
<hr>
<p>PA5 integrates two projects:</p>
    <ul>
        <li><strong>PA3:</strong> Implements sorting using shared memory for interprocess communication.</li>
        <li><strong>PA4:</strong> Extends PA3 to use threads instead of shared memory for sorting.</li>
    </ul>
    <p>Both projects generate timing statistics saved in <code>.csv</code> files, which can be used for graphing and analyzing performance.</p>
    <h2>Directory Structure</h2>
    <pre>
pa5/
├── pa3/
│   ├── src/            # Source code for PA3
│   ├── include/        # Header files for PA3
│   ├── obj/            # Compiled object files for PA3
│   ├── bin/            # Executable for PA3
│   ├── timing_results.csv # Timing statistics for PA3
├── pa4/
│   ├── src/            # Source code for PA4
│   ├── include/        # Header files for PA4
│   ├── obj/            # Compiled object files for PA4
│   ├── bin/            # Executable for PA4
│   ├── thread_timing_results.csv # Timing statistics for PA4
├── include/            # Common header files
├── makefile            # Master Makefile for PA5
    </pre>
    <h2>How PA3 Works</h2>
    <p>PA3 uses shared memory to divide workloads across processes. The following steps occur:</p>
    <ol>
        <li><strong>Shared Memory Allocation:</strong> A block of shared memory is allocated for the array to be sorted.</li>
        <li><strong>Sorting:</strong> Processes sort their respective portions of the array.</li>
        <li><strong>Merging:</strong> Sorted portions are merged into the shared memory.</li>
        <li><strong>Timing Statistics:</strong> The program outputs <code>Workload Size</code>, <code>User Time</code>, <code>System Time</code>, and <code>Total Time</code> into <code>pa3/timing_results.csv</code>.</li>
    </ol>
    <h2>How PA4 Works</h2>
    <p>PA4 modifies PA3 to use threads instead of shared memory:</p>
    <ol>
        <li><strong>Local Data Storage:</strong> The array is stored locally for each thread.</li>
        <li><strong>Sorting:</strong> Threads sort portions of the array in parallel.</li>
        <li><strong>Merging:</strong> Sorted portions are merged sequentially after all threads complete.</li>
        <li><strong>Timing Statistics:</strong> The program outputs <code>Workload Size</code>, <code>User Time</code>, <code>System Time</code>, and <code>Total Time</code> into <code>pa4/thread_timing_results.csv</code>.</li>
    </ol>
    <h2>Using the Master Makefile for PA5</h2>
    <h3>Clean Previous Builds</h3>
    <pre>
make clean
    </pre>
    <h3>Build Both PA3 and PA4</h3>
    <pre>
make
    </pre>
    <h3>Run Both PA3 and PA4</h3>
    <pre>
make run
    </pre>
    <p>The <code>.csv</code> files will be created in:</p>
    <ul>
        <li><code>pa3: timing_results.csv</code></li>
        <li><code>pa4: thread_timing_results.csv</code></li>
    </ul>
    <h2>Using Individual Makefiles for PA3 and PA4</h2>
    <h3>PA3</h3>
    <ol>
        <li>Navigate to the <code>pa3</code> directory:
            <pre>cd pa3</pre>
        </li>
        <li>Clean previous builds:
            <pre>make clean</pre>
        </li>
        <li>Build the PA3 executable:
            <pre>make</pre>
        </li>
        <li>Run PA3 to generate timing statistics:
            <pre>./bin/shared_sort</pre>
        </li>
        <li>Check the <code>.csv</code> file:
            <pre>cat timing_results.csv</pre>
        </li>
    </ol>
    <h3>PA4</h3>
    <ol>
        <li>Navigate to the <code>pa4</code> directory:
            <pre>cd pa4</pre>
        </li>
        <li>Clean previous builds:
            <pre>make clean</pre>
        </li>
        <li>Build the PA4 executable:
            <pre>make</pre>
        </li>
        <li>Run PA4 to generate timing statistics:
            <pre>./bin/shared_sort</pre>
        </li>
        <li>Check the <code>.csv</code> file:
            <pre>cat thread_timing_results.csv</pre>
        </li>
    </ol>
    <h2>Troubleshooting</h2>
    <p>If you encounter missing files or errors, ensure the directory structure matches the one described above. Check the <code>include/</code> folder for all required header files. Use <code>make clean</code> before rebuilding if there are compilation issues.</p>
    <h2>Graphing the Results</h2>
    <ol>
        <li>Open the <code>.csv</code> files in a spreadsheet or graphing tool.</li>
        <li>Plot <code>Workload Size</code> on the x-axis and the times (<code>User Time</code>, <code>System Time</code>, and <code>Total Time</code>) on the y-axis.</li>
        <li>Compare the performance of PA3 (shared memory) and PA4 (threads).</li>
    </ol>
</body>
</html>
