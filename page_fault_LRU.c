#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 3

// Function to check if a page is present in the frames
int isPagePresent(int page, int frames[], int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page) {
            return 1; // Page is present
        }
    }
    return 0; // Page is not present
}

// Function to display the content of frames
void displayFrames(int frames[], int frameCount) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == -1) {
            printf("[ ] ");
        } else {
            printf("[%d] ", frames[i]);
        }
    }
    printf("\n");
}

// Function to find the index of the least recently used page
int findLRUPage(int counters[], int frameCount) {
    int minIndex = 0;
    for (int i = 1; i < frameCount; i++) {
        if (counters[i] < counters[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to perform page replacement using LRU algorithm
void performLRU(int pages[], int pageCount) {
    int frames[MAX_FRAMES];
    int counters[MAX_FRAMES];
    int frameCount = 0;
    int pageFaults = 0;
    int counter = 0;

    // Initialize frames and counters with -1 to indicate empty slots
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        counters[i] = -1;
    }

    // Process each page reference
    for (int i = 0; i < pageCount; i++) {
        printf("Page reference: %d\n", pages[i]);

        // Check if the page is present in frames
        if (!isPagePresent(pages[i], frames, frameCount)) {
            // Page fault occurred
            pageFaults++;
            printf("Page fault!\n");

            // Find the index of the least recently used page
            int replaceIndex = findLRUPage(counters, frameCount);

            // Replace the least recently used page using LRU algorithm
            frames[replaceIndex] = pages[i];
            counters[replaceIndex] = counter++;

            // Display the frames after replacement
            displayFrames(frames, MAX_FRAMES);
        } else {
            // Page hit, update the counter for the accessed page
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == pages[i]) {
                    counters[j] = counter++;
                    break;
                }
            }
            printf("Page hit!\n");
            displayFrames(frames, MAX_FRAMES);
        }
    }

    // Display the total number of page faults
    printf("Total page faults: %d\n", pageFaults);
}

int main() {
    // Given page reference sequence
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    int pageCount = sizeof(pages) / sizeof(pages[0]);

    // Perform LRU page replacement
    performLRU(pages, pageCount);

    return 0;
}
