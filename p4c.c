// Practical 4(iii): parent waits for child to finish before terminating
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("Child: working...\n");
        sleep(2);
        printf("Child: done\n");
    } else {
        wait(NULL);
        printf("Parent: child finished, parent exiting\n");
    }
    return 0;
}
