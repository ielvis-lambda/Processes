// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

//Different calls for different types of arguments (what they are/point to)

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{

    // printf("hello world (pid: %d)\n", (int)getpid());

    int rc = fork();
    // ------------------------------------------------ child process starts executing here
    if (rc < 0)
    { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    { // child process satisfies this branch

        //doesn't run it? 
        // execl("ls", "ls", NULL);
        
        //doesn't run it? 
        // execle("ls", "ls", NULL);
        
        execlp("ls", "ls", NULL);

        printf("hello, child here (pid: %d) \n", (int)getpid());
    }
    else
    {
        int wc = waitpid(rc, NULL, 0); // `waitpid` call added here
        printf("goodbye, parent here (pid: %d) of child %d\n", (int)getpid(), rc);
    }

    return 0;
}
