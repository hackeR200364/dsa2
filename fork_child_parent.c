#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    // Create a new process
    child_pid = fork();

    if (child_pid == -1) {
        // Fork failed
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        // Code executed by the child process
        for (int i = 1; i <= 5; ++i) {
            printf("Child process: %d\n", i);
            sleep(1); // Optional sleep to make output clearer
        }
    } else {
        // Code executed by the parent process
        for (int i = 100; i <= 105; ++i) {
            printf("Parent process: %d\n", i);
            sleep(1); // Optional sleep to make output clearer
        }
    }

    return 0;
}
