#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid, terminated_child;
    int status;

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

        // The child process terminates
        printf("Child process terminating.\n");
        exit(42); // Exit with a status code of 42
    } else {
        // Code executed by the parent process
        printf("Parent process: PID=%d\n", getpid());

        // Wait for the termination of the child process
        terminated_child = wait(&status);

        printf("Parent process: Child with PID=%d terminated.\n", terminated_child);

        if (WIFEXITED(status)) {
            // Child terminated normally
            printf("Parent process: Child exit status = %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            // Child terminated by a signal
            printf("Parent process: Child terminated by signal %d\n", WTERMSIG(status));
        }

        // Parent process terminates
        printf("Parent process terminating.\n");
    }

    return 0;
}
