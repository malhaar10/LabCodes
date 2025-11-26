#include <stdio.h>
#include <stdlib.h>

int size = 8;
int disk_size = 200;

void sortArray(int arr[], int n) {
    // A simple bubble sort to sort arrays
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void CSCAN(int arr[], int head) {
    int seek_count = 0;
    int distance, cur_track;

    int left[size + 1], right[size + 1];  // Arrays to store requests
    int seek_sequence[size + 2];          // Array to store the seek sequence
    int left_size = 0, right_size = 0, seq_index = 0;

    // appending end values which have to be visited
    // before reversing the direction
    left[left_size++] = 0;
    right[right_size++] = disk_size - 1;

    // tracks on the left of the head will be serviced after reaching the end
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left[left_size++] = arr[i];
        if (arr[i] > head)
            right[right_size++] = arr[i];
    }

    // sorting left and right arrays
    sortArray(left, left_size);
    sortArray(right, right_size);

    // first service the requests on the right side of the head
    for (int i = 0; i < right_size; i++) {
        cur_track = right[i];
        seek_sequence[seq_index++] = cur_track;

        // calculate absolute distance
        distance = abs(cur_track - head);

        // increase the total count
        seek_count += distance;

        // accessed track is now the new head
        head = cur_track;
    }

    // once reached the right end, jump to the beginning
    head = 0;

    // adding seek count for head returning from the last disk to 0
    seek_count += (disk_size - 1);

    // Now service the requests on the left
    for (int i = 0; i < left_size; i++) {
        cur_track = left[i];
        seek_sequence[seq_index++] = cur_track;

        // calculate absolute distance
        distance = abs(cur_track - head);

        // increase the total count
        seek_count += distance;

        // accessed track is now the new head
        head = cur_track;
    }

    // Output results
    printf("Total number of seek operations = %d\n", seek_count);
    printf("Seek Sequence is:\n");
    for (int i = 0; i < seq_index; i++) {
        printf("%d\n", seek_sequence[i]);
    }
}

// Driver code
int main() {
    // request array
    int arr[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    printf("Initial position of head: %d\n", head);
    CSCAN(arr, head);

    return 0;
}
