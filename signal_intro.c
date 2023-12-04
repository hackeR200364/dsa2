#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void handle_signal(int signum)
{
    if (signum == SIGINT)
    {
        printf("\nCtrl-C pressed. Exiting...\n");
        exit(0);
    }
}

int main()
{
    // Register the signal handler
    signal(SIGINT, handle_signal);

    printf("Press Ctrl-C to exit.\n");

    // Infinite loop
    while (1)
    {
        // Your main program logic goes here
        printf("Hello\n");

        // Sleeping for a short duration to avoid high CPU usage
        // sleep(1);
    }

    return 0;
}
