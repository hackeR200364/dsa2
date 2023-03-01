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

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

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

void create()
{
    int i, num;
    FILE *file;
    file = fopen("random_numbers.txt", "w");

    for (i = 1; i <= 150000; i++)
    {
        num = rand();
        fprintf(file, "%d\n", num); // Write the number to the file, followed by a newline character
    }

    fclose(file); // Close the file
}

int main()
{
    int i, num;
    clock_t start, end;
    double cpu_time_used;
    FILE *file;
    int random_numbers[150000];

    // Read random numbers from file
    file = fopen("random_numbers.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < 150000; i++)
    {
        fscanf(file, "%d", &num);
        random_numbers[i] = num;
    }

    fclose(file);

    // Sort the numbers using merge sort and print the time taken for every 25000 numbers
    int interval = 25000;
    printf("\nPerforming Merge Sort:\n");
    
    for (i = 0; i < 150000; i += interval)
    {
        start = clock();

        mergeSort(random_numbers, i, i + interval - 1);

        end = clock();
        cpu_time_used = ((double)(end - start)) /CLOCKS_PER_SEC;

        printf("Time taken by system for numbers %d-%d: %.4f seconds\n", i + 1, i + interval, cpu_time_used);
    }
    
    printf("\nPerforming Heap Sort:\n");
    
    for (i = 0; i < 150000; i += interval)
    {
        start = clock();

        heapSort(random_numbers, i + interval - 1);

        end = clock();
        cpu_time_used = ((double)(end - start)) /CLOCKS_PER_SEC;

        printf("Time taken by system for numbers %d-%d: %.4f seconds\n", i + 1, i + interval, cpu_time_used);
    }
    
    printf("\nPerforming Quick Sort:\n");
    
    for (i = 0; i < 150000; i += interval)
    {
        start = clock();

        quickSort(random_numbers, 0, i + interval - 1);

        end = clock();
        cpu_time_used = ((double)(end - start)) /CLOCKS_PER_SEC;

        printf("Time taken by system for numbers %d-%d: %.4f seconds\n", i + 1, i + interval, cpu_time_used);
    }
    return 0;
}

