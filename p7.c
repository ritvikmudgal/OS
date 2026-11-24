// Practical 7: copy a file using system calls
// Usage: ./p7 source.txt dest.txt
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s source dest\n", argv[0]);
        return 1;
    }
    int src = open(argv[1], O_RDONLY);
    int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (src < 0 || dst < 0) {
        printf("Error opening files\n");
        return 1;
    }
    char buf[512];
    int n;
    while ((n = read(src, buf, sizeof(buf))) > 0)
        write(dst, buf, n);
    close(src);
    close(dst);
    printf("File copied\n");
    return 0;
}
