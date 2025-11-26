#include <stdio.h>

#define MAX 10

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }

    return pos;
}

int lru_page_replacement(int capacity, int n, int pages[]) {
    int frames[MAX], time[MAX], counter = 0, faults = 0;
    int i, j, pos, found;

    for (i = 0; i < capacity; ++i) {
        frames[i] = -1;  // Initialize the frames as empty (-1)
    }

    for (i = 0; i < n; ++i) {
        found = 0;  // Flags to check if the page is already in frames

        // Check if the page is already in memory (frames)
        for (j = 0; j < capacity; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;  // Update the access time of the page
                found = 1;
                break;
            }
        }

        // If the page is not in memory
        if (!found) {
            // Check for an empty frame
            for (j = 0; j < capacity; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    frames[j] = pages[i];  // Insert the page into the empty frame
                    time[j] = counter;     // Set the current time (for tracking usage)
                    faults++;              // Page fault occurred
                    found = 1;
                    break;
                }
            }
        }

        // If there are no empty frames, replace the least recently used page
        if (!found) {
            pos = findLRU(time, capacity);  // Find the least recently used page's position
            counter++;
            frames[pos] = pages[i];  // Replace the page at the LRU position
            time[pos] = counter;     // Update its usage time
            faults++;                // Page fault occurred
        }
    }

    return faults;
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};  // Page reference string
    int n = sizeof(pages) / sizeof(pages[0]);  // Number of pages
    int capacity = 3;  // Number of available frames

    // Call the LRU page replacement function and print the result
    printf("\nNumber of page faults: %d\n", lru_page_replacement(capacity, n, pages));

    return 0;
}
