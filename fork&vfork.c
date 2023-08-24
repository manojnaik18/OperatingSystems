#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t pid, vpid;
printf("Original process ID: %d\n", getpid());
    pid = fork();
if (pid == 0) {
        printf("Fork Child process ID: %d\n", getpid());
    } else if (pid > 0) {
        printf("Fork Parent process ID: %d\n", getpid());
        wait(NULL);
    } else {
        printf("Forking failed.\n");
        return 1;
    }
    vpid = vfork();
if (vpid == 0) {
        printf("vfork Child process ID: %d\n", getpid());
        exit(0);
    } else if (vpid > 0) {
        printf("vfork Parent process ID: %d\n", getpid());
    } else {
        printf("vForking failed.\n");
        return 1;
    }
 return 0;
}
