#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define ARRAY_SIZE 5

int main() {
    key_t key = ftok("shared_memory_key", 65);  // Generate a key for shared memory

    // Create shared memory segment
    int shmid = shmget(key, ARRAY_SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory to the process
    int *sharedArray = (int *)shmat(shmid, NULL, 0);
    if ((int)sharedArray == -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Read array elements from the user
    printf("Enter %d integers for the array:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        scanf("%d", &sharedArray[i]);
    }

    // Detach shared memory from the process
    shmdt(sharedArray);

    // Fork a new process
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {  // Child process
        // Wait for a moment to ensure parent completes writing to shared memory
        sleep(1);

        // Reattach shared memory to the child process
        int *childArray = (int *)shmat(shmid, NULL, 0);
        if ((int)childArray == -1) {
            perror("shmat in child");
            exit(EXIT_FAILURE);
        }

        // Print the array received from the parent
        printf("Array received by the child process:\n");
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            printf("%d ", childArray[i]);
        }
        printf("\n");

        // Detach shared memory from the child process
        shmdt(childArray);
    } else {  // Parent process
        // Wait for the child to finish
        wait(NULL);

        // Delete the shared memory segment
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
