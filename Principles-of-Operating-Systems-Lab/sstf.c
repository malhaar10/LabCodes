#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000000 // Large value to represent infinity

// Calculates the difference of each track number with the head position
void calculateDifference(int request[], int head, int diff[][2], int n) {
    for (int i = 0; i < n; i++) {
        diff[i][0] = abs(head - request[i]);
    }
}

// Finds the unaccessed track which is at the minimum distance from the head
int findMIN(int diff[][2], int n) {
    int index = -1;
    int minimum = MAX;

    for (int i = 0; i < n; i++) {
        if (!diff[i][1] && minimum > diff[i][0]) {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

// Function to implement SSTF Disk Scheduling
void shortestSeekTimeFirst(int request[], int head, int n) {
    if (n == 0) {
        return;
    }

    // Array to store difference of each request with head
    int diff[n][2]; // diff[i][0] is distance, diff[i][1] is 1 if track is accessed
    for (int i = 0; i < n; i++) {
        diff[i][1] = 0; // Initially all tracks are unaccessed
    }

    // Count total number of seek operations
    int seekCount = 0;

    // Array to store the sequence in which disk access happens
    int seekSequence[n + 1];

    for (int i = 0; i < n; i++) {
        seekSequence[i] = head;
        calculateDifference(request, head, diff, n);
        int index = findMIN(diff, n);
        diff[index][1] = 1;

        // Increase the total seek count
        seekCount += diff[index][0];

        // The accessed track is now the new head
        head = request[index];
    }
    seekSequence[n] = head;

    printf("Total number of seek operations = %d\n", seekCount);
    printf("Seek sequence is:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d\n", seekSequence[i]);
    }
}

// Driver code
int main() {
    int n = 8;
    int proc[] = {176, 79, 34, 60, 92, 11, 41, 114};

    shortestSeekTimeFirst(proc, 50, n);

    return 0;
}
