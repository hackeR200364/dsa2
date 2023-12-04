#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Get the process ID (PID)
    pid_t pid = getpid();
    printf("Process ID (PID): %d\n", pid);

    // Get the parent process ID (PPID)
    pid_t ppid = getppid();
    printf("Parent Process ID (PPID): %d\n", ppid);

    // Use ps command to verify process status
    const char* ps_command = "ps -p %d -o pid,ppid,stat,cmd";
    char command[100];
    snprintf(command, sizeof(command), ps_command, pid);

    printf("\nVerifying process status using ps command:\n");
    system(command);

    return 0;
}
