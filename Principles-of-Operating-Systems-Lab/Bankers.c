#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    
    // Number of processes (n) and resource types (m)
    n = 5;
    m = 3;

    // Allocation matrix: Resources currently allocated to each process
    int alloc[5][3] = { { 0, 1, 0 }, 
                        { 2, 0, 0 },
                        { 3, 0, 2 }, 
                        { 2, 1, 1 }, 
                        { 0, 0, 2 } }; 

    // Maximum matrix: Maximum resources each process may request
    int max[5][3] = { { 7, 5, 3 }, 
                      { 3, 2, 2 }, 
                      { 9, 0, 2 }, 
                      { 2, 2, 2 }, 
                      { 4, 3, 3 } }; 

    // Available resources: Total resources available initially
    int avail[3] = { 3, 3, 2 }; 

    // Need matrix: Resources still required by each process to finish
    int need[n][m];
    
    // Calculate the Need matrix (need = max - alloc)
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    // Array to track if a process is finished (1 if finished, 0 if not)
    int f[n], ans[n], ind = 0; // f is finished array, ans is the safe sequence
    for (k = 0; k < n; k++) {
        f[k] = 0;  // Initialize all processes as unfinished
    }

    // Begin Banker's algorithm
    int y = 0;
    for (k = 0; k < 5; k++) {  // Try to find a safe sequence
        for (i = 0; i < n; i++) {  // Check each process
            if (f[i] == 0) {  // If process is not finished

                int flag = 0;  // To track if resources can satisfy the process
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {  // If process needs more resources than available
                        flag = 1;  // Not enough resources, so break
                        break;
                    }
                }

                // If resources are sufficient (flag == 0)
                if (flag == 0) {
                    ans[ind++] = i;  // Add process to safe sequence

                    // Release resources allocated to this process and add them to available resources
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];

                    f[i] = 1;  // Mark the process as finished
                }
            }
        }
    }
  
    // After the loop, check if all processes are finished
    int flag = 1;  // Flag to check if system is safe
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {  // If any process is not finished
            flag = 0;  // Set flag to unsafe
            printf("The following system is not safe\n");
            break;
        }
    }
    
    // If the system is safe, print the safe sequence
    if (flag == 1) {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);  // Print processes in safe order
        printf(" P%d", ans[n - 1]);  // Print the last process without an arrow
    }

    return (0);  // End of program
}
