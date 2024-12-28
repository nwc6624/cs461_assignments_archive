/* Noah Caulfield
 10/10/2024
 Class: CS 461, Operating systems at Eastern New Mexico University 
Assignment PA2 Signal Handler Routine


 handler.cc: A C++ program to demonstrate setting signal handlers for SIGUSR1 and SIGUSR2
*/

/*Assignment Requirements

Write a program named handler.cc,  that creates signal handlers for the SIGUSR1 and SIGUSR2 signals. The main routine may be an infinite "sleep" loop.
Upon receiving SIGUSR1, the output should be the current date and time.
Upon receiving SIGUSR2, the output should be the program author's name.
Reset the signal inside the signal handler to enable it again.
Implement error handling for SIG_ERR. If SIG_ERR is raised, the program should indicate an error and exit with a return code 1.
Create a Makefile that compiles and runs your program efficiently.
Write a README or a text file that clearly explains the structure of your code. */

#include <iostream>
#include <csignal>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

// Signal handler function
void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        // Output current date and time
        time_t now = time(0);
        char* dt = ctime(&now);
        std::cout << "Current Date and Time: " << dt << std::endl;
    } else if (sig == SIGUSR2) {
        // Output author's name
        std::cout << "Program Author: Noah Caulfield" << std::endl;
    }

    // Re-establish the signal handler
    if (signal(SIGUSR1, signal_handler) == SIG_ERR || signal(SIGUSR2, signal_handler) == SIG_ERR) {
        std::cerr << "Error re-establishing signal handler" << std::endl;
        exit(1);
    }
}

int main() {
    // Set signal handlers for SIGUSR1 and SIGUSR2
    if (signal(SIGUSR1, signal_handler) == SIG_ERR) {
        std::cerr << "Error setting handler for SIGUSR1" << std::endl;
        return 1;
    }
    if (signal(SIGUSR2, signal_handler) == SIG_ERR) {
        std::cerr << "Error setting handler for SIGUSR2" << std::endl;
        return 1;
    }

    // Infinite sleep loop to keep the program running
    while (true) {
        sleep(1);
    }

    return 0;
}
