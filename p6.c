// Practical 6: memory information - configured, free and used memory (Linux only)
#include <stdio.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo s;
    sysinfo(&s);
    unsigned long total = s.totalram * s.mem_unit / (1024 * 1024);
    unsigned long free_ = s.freeram * s.mem_unit / (1024 * 1024);
    printf("Total memory: %lu MB\n", total);
    printf("Free memory : %lu MB\n", free_);
    printf("Used memory : %lu MB\n", total - free_);
    return 0;
}
