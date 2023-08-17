#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int childStatus;

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0) {
        // Forking failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process

        // Print the child process ID and its parent's ID
        printf("Child process ID: %d\n", getpid());
        printf("Parent process ID: %d\n", getppid());

        // Execute system calls to analyze process creation and termination
        execl("/bin/ls", "ls", "-l", NULL);
        // If execl() returns, it means the system call failed
        perror("Exec failed");
        exit(EXIT_FAILURE);
    } else {
        // Parent process

        // Wait for the child process to terminate
        wait(&childStatus);

        if (WIFEXITED(childStatus)) {
            // Child process terminated normally
            int exitStatus = WEXITSTATUS(childStatus);
            printf("Child process terminated with exit status: %d\n", exitStatus);
        } else if (WIFSIGNALED(childStatus)) {
            // Child process terminated due to a signal
            int termSignal = WTERMSIG(childStatus);
            printf("Child process terminated due to signal: %d\n", termSignal);
        }
    }

    return 0;
}

