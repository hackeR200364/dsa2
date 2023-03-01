#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int i, num;
    clock_t start, end;
    double cpu_time_used;
    FILE *file;
    int random_numbers[150000];

    // Read random numbers from file
    file = fopen("random_numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < 150000; i++) {
        fscanf(file, "%d", &num);
        random_numbers[i] = num;
    }

    fclose(file);

    // Sort the numbers using heap sort
    start = clock();
    heapSort(random_numbers, 150000);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by system: %.4f seconds\n", cpu_time_used);

    return 0;
}
