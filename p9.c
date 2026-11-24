// Practical 9: SJF scheduling, non-preemptive (all processes arrive at time 0)
#include <stdio.h>

int main() {
    int n, bt[20], p[20], wt[20], tat[20], t;
    float avwt = 0, avtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // sort by burst time
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (bt[i] > bt[j]) {
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("Average WT = %.2f\nAverage TAT = %.2f\n", avwt / n, avtat / n);
    return 0;
}
