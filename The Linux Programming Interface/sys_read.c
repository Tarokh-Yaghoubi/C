#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[100];
    int file_descriptor = 0;  // File descriptor 0 represents standard input (stdin)
    ssize_t bytes_read;

    asm volatile (
        "syscall"
        : "=a" (bytes_read)      // Output: store the result in bytes_read variable
        : "D" (file_descriptor), // Input: store file descriptor in RDI (D register)
          "S" (buffer),          // Input: store buffer address in RSI (S register)
          "d" (sizeof(buffer))   // Input: store buffer size in RDX (d register)
        : "rcx", "r11", "memory" // Clobbered registers and memory
    );

    if (bytes_read == -1) {
        perror("Error reading from stdin");
        return 1;
    }

    buffer[bytes_read] = '\0';  // Null-terminate the string

    // Display the content read from standard input
    printf("Content read from stdin: %s\n", buffer);

    return 0;
}

