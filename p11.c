// Practical 11: sum of n numbers using Pthreads
// Compile with -pthread
#include <stdio.h>
#include <pthread.h>

int n;
long sum = 0;

void *add(void *arg) {
    for (int i = 1; i <= n; i++)
        sum += i;
    pthread_exit(NULL);
}

int main() {
    pthread_t t;
    printf("Enter n: ");
    scanf("%d", &n);

    pthread_create(&t, NULL, add, NULL);
    pthread_join(t, NULL);

    printf("Sum of first %d numbers = %ld\n", n, sum);
    return 0;
}
