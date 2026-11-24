// Practical 5: kernel version, CPU type and CPU info (Linux only)
#include <stdio.h>
#include <string.h>
#include <sys/utsname.h>

int main() {
    struct utsname u;
    uname(&u);
    printf("OS: %s\nKernel version: %s\nMachine: %s\n", u.sysname, u.release, u.machine);

    FILE *f = fopen("/proc/cpuinfo", "r");
    char line[256];
    int n = 0;
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "model name", 10) == 0) {
            n++;
            if (n > 1) break;          // only first CPU
        }
        if (strncmp(line, "model name", 10) == 0 || strncmp(line, "cpu MHz", 7) == 0 ||
            strncmp(line, "cache size", 10) == 0 || strncmp(line, "cpu cores", 9) == 0)
            printf("%s", line);
    }
    fclose(f);
    return 0;
}
