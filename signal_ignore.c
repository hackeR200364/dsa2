#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function to ignore SIGINT
void ignore_signal(int signum) {
    // Do nothing, just ignore the signal
    printf("Received SIGINT but ignoring it.\n");
}

int main() {
    // Register the signal handler to ignore SIGINT
    signal(SIGINT, ignore_signal);

    printf("Press Ctrl-C to see that the program ignores SIGINT.\n");

    // Infinite loop to keep the program running
    while (1) {
        // Perform any other necessary tasks in the loop
        sleep(1);
    }

    return 0;
}
