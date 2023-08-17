#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid, vpid;
    int status;

    // Fork system call
    pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process created using fork. Process ID: %d\n", getpid());
        printf("Child process exiting.\n");
        exit(0);
    } else if (pid > 0) {
        // Parent process
        printf("Parent process. Child process ID: %d\n", pid);
        printf("Parent process waiting for child to terminate.\n");
        wait(&status);
        printf("Child process terminated.\n");
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed.\n");
        return 1;
    }

    // Vfork system call
    vpid = vfork();

    if (vpid == 0) {
        // Child process
        printf("Child process created using vfork. Process ID: %d\n", getpid());
        printf("Child process exiting.\n");
        _exit(0);
    } else if (vpid > 0) {
        // Parent process
        printf("Parent process. Child process ID: %d\n", vpid);
        printf("Parent process waiting for child to terminate.\n");
        wait(&status);
        printf("Child process terminated.\n");
    } else {
        // Vfork failed
        fprintf(stderr, "Vfork failed.\n");
        return 1;
    }

    return 0;
}
