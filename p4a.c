// Practical 4(i): parent and child execute same program, same code
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    printf("Hello, my pid is %d (fork returned %d)\n", getpid(), pid);
    return 0;
}
