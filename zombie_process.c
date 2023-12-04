#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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
        printf("Child process: PID=%d\n", getpid());
        sleep(2); // Introduce a delay to allow the parent to wait
        printf("Child process terminating.\n");
    } else {
        // Code executed by the parent process
        printf("Parent process: PID=%d\n", getpid());

        // Parent process waits for the child process
        sleep(5); // Introduce a delay to let the child terminate
        wait(NULL);

        printf("Parent process terminating.\n");
    }

    return 0;
}
