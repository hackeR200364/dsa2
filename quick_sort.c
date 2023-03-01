#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    // Sort the numbers using quick sort
    start = clock();
    quickSort(random_numbers, 0, 149999);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by system: %.4f seconds\n", cpu_time_used);

    return 0;
}
