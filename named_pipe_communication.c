//Write
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    int fd1;
    char arr[50];
    mkfifo("npipe1", 0774);
    while (1)
    {
        fd1 = open("npipe1", O_WRONLY);
        printf("Write: ");
        fgets(arr, 50, stdin);
        write(fd1, arr, strlen(arr) + 1);
        close(fd1);
    }

    return 0;
}

//Read
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    int fd1;
    char arr[50];
    while (1)
    {
        fd1 = open("npipe1", O_RDONLY);
        read(fd1, arr, 50);
        printf("Reading: %s", arr);
        close(fd1);
    }

    return 0;
}
