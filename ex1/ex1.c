// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{

    // When the parent changes the value it changes in both the parent and the child. When the child changes the value it changes only in the child.
    int x = 100;
    //fork() returns twice
    int pid = fork();

    x = 5;

    if (pid == 0)
    {

        x = 10;

        printf("I'm x in child: %d\n", x);

        exit(1);
    }
    else
    {
        wait(NULL);

        printf("I'm x in parent: %d\n", x);
    }

    return 0;
}
