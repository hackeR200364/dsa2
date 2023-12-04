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

// Function to find the page that will not be used for the longest time
int findOptimalPage(int pages[], int pageIndices[], int start, int end, int frameCount) {
    int optimalPageIndex = -1;
    int farthestIndex = -1;

    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = start; j < end; j++) {
            if (pages[j] == pageIndices[i]) {
                if (j > farthestIndex) {
                    farthestIndex = j;
                    optimalPageIndex = i;
                }
                break;
            }
        }

        if (j == end) {
            // If a page will not be used, return it
            return i;
        }
    }

    return optimalPageIndex;
}

// Function to perform page replacement using Optimal algorithm
void performOptimal(int pages[], int pageCount) {
    int frames[MAX_FRAMES];
    int frameCount = 0;
    int pageFaults = 0;

    // Initialize frames with -1 to indicate empty slots
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
    }

    // Process each page reference
    for (int i = 0; i < pageCount; i++) {
        printf("Page reference: %d\n", pages[i]);

        // Check if the page is present in frames
        if (!isPagePresent(pages[i], frames, frameCount)) {
            // Page fault occurred
            pageFaults++;
            printf("Page fault!\n");

            // Find the index of the page to be replaced
            int replaceIndex = findOptimalPage(pages, pages, i + 1, pageCount, frameCount);

            // Replace the page using Optimal algorithm
            frames[replaceIndex] = pages[i];

            // Display the frames after replacement
            displayFrames(frames, MAX_FRAMES);
        } else {
            // Page hit
            printf("Page hit!\n");
            displayFrames(frames, MAX_FRAMES);
        }
    }

    // Display the total number of page faults
    printf("Total page faults: %d\n", pageFaults);
}

int main() {
    // Given page reference sequence
    int pages[] = {7,8,9,5,7,2,3,1,0};
    int pageCount = sizeof(pages) / sizeof(pages[0]);

    // Perform Optimal page replacement
    performOptimal(pages, pageCount);

    return 0;
}
