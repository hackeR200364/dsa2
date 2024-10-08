#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    const char *fifo_path = "my_fifo";

    // Create the named pipe (FIFO)
    mkfifo(fifo_path, 0666);

    // Open the FIFO for writing
    int fifo_fd = open(fifo_path, O_WRONLY);
    if (fifo_fd == -1)
    {
        perror("Failed to open the FIFO for writing");
        exit(EXIT_FAILURE);
    }

    // Write data to the FIFO
    const char *message = "Hello, Named Pipe!";
    write(fifo_fd, message, sizeof(message));
    close(fifo_fd);

    printf("Writer process completed.\n");

    return 0;
}
