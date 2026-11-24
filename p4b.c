// Practical 4(ii): parent and child execute different code
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid < 0) {
        printf("fork failed\n");
    } else if (pid == 0) {
        printf("Child: pid=%d, running ls using exec\n", getpid());
        execlp("ls", "ls", NULL);
    } else {
        printf("Parent: pid=%d, child pid=%d\n", getpid(), pid);
    }
    return 0;
}
