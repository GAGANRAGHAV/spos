#include <iostream>
using namespace std;

// Function to implement Next-Fit allocation algorithm
void nextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];  // To store the block allocated to each process
    int j = 0;          // To track the position of the last allocated block

    // Initially, no block is assigned to any process
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Pick each process and allocate using the next-fit approach
    for (int i = 0; i < n; i++) {
        // Start from the last allocated position and search in a linear manner
        bool allocated = false;

        // Loop through the blocks starting from the last allocation position
        for (int count = 0; count < m; count++) {
            if (blockSize[j] >= processSize[i]) {
                // Allocate block j to process i
                allocation[i] = j;

                // Reduce available memory in this block
                blockSize[j] -= processSize[i];

                // Move to the next block for the next allocation
                allocated = true;
                break;
            }

            // Move to the next block, and wrap around if we reach the end
            j = (j + 1) % m;
        }

        if (!allocated) {
            // If no suitable block was found after one full loop, the process remains unallocated
            allocation[i] = -1;
        }
    }

    // Output the allocation results
    cout << "\nNext-Fit Allocation:\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600};  // Sizes of memory blocks
    int processSize[] = {212, 417, 112, 426};     // Sizes of processes
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    // Call Next-Fit algorithm to allocate memory
    nextFit(blockSize, m, processSize, n);

    return 0;
}
