#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, num;
    FILE *file;
    srand(time(NULL)); // Seed the random number generator with the current time

    // Open a new file for writing
    file = fopen("random_numbers.txt", "w");

    // Generate 150000 random numbers and write them to the file
    for (i = 0; i < 150000; i++)
    {
        num = rand() % 101;         // Generate a random number between 0 and 100
        fprintf(file, "%d\n", num); // Write the number to the file, followed by a newline character
    }

    fclose(file); // Close the file
    return 0;
}
