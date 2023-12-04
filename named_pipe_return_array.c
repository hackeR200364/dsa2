//writer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd1;
    int arr[50];

    // Create the named pipe (FIFO)
    // mkfifo("npipe1", 0666);

    while (1)
    {
        fd1 = open("npipe1", O_WRONLY);

        // Take user input for an array of integers
        int n;
        printf("Enter the number of elements: ");
        scanf("%d", &n);

        printf("Enter %d integers:\n", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        // Write the array size and array to the FIFO
        write(fd1, &n, sizeof(int));
        write(fd1, arr, n * sizeof(int));

        close(fd1);

        // Open the FIFO for reading to receive the sorted array
        fd1 = open("npipe1", O_RDONLY);
        read(fd1, arr, n * sizeof(int));

        // Print the sorted array
        printf("Sorted Array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        close(fd1);
    }

    return 0;
}

//reader
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void insertionSort(int array[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;

        // Move elements of array[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

int main()
{
    int fd1;
    int arr[50];

    // Open the FIFO for reading to receive the array
    fd1 = open("npipe1", O_RDONLY);

    while (1)
    {
        // Read the array size and array from the FIFO
        int n;
        read(fd1, &n, sizeof(int));
        read(fd1, arr, n * sizeof(int));

        // Apply insertion sort on the received array
        insertionSort(arr, n);

        // Print the sorted array
        printf("Sorted Array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Open the FIFO for writing to send the sorted array back
        fd1 = open("npipe1", O_WRONLY);
        write(fd1, arr, n * sizeof(int));

        close(fd1);
    }

    return 0;
}
