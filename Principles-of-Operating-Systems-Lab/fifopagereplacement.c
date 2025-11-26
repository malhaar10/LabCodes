#include <stdio.h>

#define MAX 100 // Define a maximum size for the arrays

// Function to find page faults using FIFO
int pageFaults(int pages[], int n, int capacity) {
    int page_faults = 0;   // To count page faults
    int frames[MAX];       // Array to store pages in memory (FIFO)
    int index = 0;         // Points to the next frame to be replaced

    // Initialize all frames as empty (-1 means empty)
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    // Traverse through the list of pages
    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1; // Page hit
                break;
            }
        }

        // If the page is not found (page miss), replace a page
        if (!found) {
            frames[index] = pages[i];    // Replace the oldest page
            index = (index + 1) % capacity; // Move to the next frame in a circular way
            page_faults++;               // Increment page fault count
        }
    }

    return page_faults;
}

// Driver code
int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;

    printf("Page faults: %d\n", pageFaults(pages, n, capacity));
    return 0;
}
