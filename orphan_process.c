#include <stdio.h>
#include <stdlib.h>
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
        printf("Child process: PID=%d, PPID=%d\n", getpid(), getppid());

        // Introduce a delay in the child process
        sleep(2);

        // The parent has terminated, and the child becomes an orphan
        printf("Orphan process: PID=%d, PPID=%d\n", getpid(), getppid());
    } else {
        // Code executed by the parent process
        printf("Parent process: PID=%d\n", getpid());

        // Introduce a delay in the parent process
        sleep(1);

        // Parent process terminates
        printf("Parent process terminating.\n");
    }

    return 0;
}
