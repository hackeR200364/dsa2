#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    const char *fifo_path = "my_fifo";

    // Open the FIFO for reading
    int fifo_fd = open(fifo_path, O_RDONLY);
    if (fifo_fd == -1)
    {
        perror("Failed to open the FIFO for reading");
        exit(EXIT_FAILURE);
    }

    // Read data from the FIFO
    char buffer[256];
    ssize_t bytes_read = read(fifo_fd, buffer, sizeof(buffer));
    close(fifo_fd);

    if (bytes_read == -1)
    {
        perror("Error reading from the FIFO");
        exit(EXIT_FAILURE);
    }

    // Null-terminate the received data
    buffer[bytes_read] = '\0';

    // Display the received message
    printf("Received message: %s\n", buffer);

    printf("Reader process completed.\n");

    return 0;
}
