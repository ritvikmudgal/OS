// Practical 12: First-fit, Best-fit and Worst-fit memory allocation
#include <stdio.h>

int nb, np, block[20], proc[20];

void allocate(int type) {
    int b[20], alloc[20];
    for (int i = 0; i < nb; i++) b[i] = block[i];     // copy blocks
    for (int i = 0; i < np; i++) alloc[i] = -1;

    for (int i = 0; i < np; i++) {
        int idx = -1;
        for (int j = 0; j < nb; j++) {
            if (b[j] >= proc[i]) {
                if (type == 1) { idx = j; break; }                       // first fit
                if (type == 2 && (idx == -1 || b[j] < b[idx])) idx = j;  // best fit
                if (type == 3 && (idx == -1 || b[j] > b[idx])) idx = j;  // worst fit
            }
        }
        if (idx != -1) {
            alloc[i] = idx;
            b[idx] -= proc[i];
        }
    }

    printf("Process\tSize\tBlock\n");
    for (int i = 0; i < np; i++) {
        printf("P%d\t%d\t", i + 1, proc[i]);
        if (alloc[i] != -1) printf("%d\n", alloc[i] + 1);
        else printf("Not allocated\n");
    }
}

int main() {
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    printf("Enter block sizes: ");
    for (int i = 0; i < nb; i++) scanf("%d", &block[i]);
    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter process sizes: ");
    for (int i = 0; i < np; i++) scanf("%d", &proc[i]);

    printf("\n--- First Fit ---\n");
    allocate(1);
    printf("\n--- Best Fit ---\n");
    allocate(2);
    printf("\n--- Worst Fit ---\n");
    allocate(3);
    return 0;
}
