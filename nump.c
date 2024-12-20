// #include "types.h"
// #include "stat.h"
// #include "user.h"

// int main(int argc, char *argv[])
// {

//     printf(1, "Total Number of Ready Processes before fork: %d\n", numberofprocesses());

//     for(int i=0;i<5;i++)
//     {
//         int id=fork();
//         if(id==0)
//         {
//             printf(1, "Total Number of Ready Processes After %d forks: %d\n", i+1,numberofprocesses());

//             exit();
//         }
//     }
//     for(int i=0;i<5;i++)
//         wait();

//     exit();
// }

#include "types.h"
#include "stat.h"
#include "user.h"

#define SHORT_LOOP 100
#define LONG_LOOP  1000

void busy_loop1(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
         {
    	    int*a =malloc(sizeof(int));
            *a=i*j;
            free(a);
         } // Simulate some busy work
    }
}

void busy_loop2(int n)
{
    int i;
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
         {
    	    int*a =malloc(sizeof(int));
            *a=i*j;
            free(a);
         } // Simulate some busy work
    }
}

int main(void) {
    int pid1 = fork();
    if (pid1 == 0)
    {
        // Child process 1

        busy_loop1(SHORT_LOOP); 
        exit();
    }
    else if(fork()==0)
    {
        // Child process 2
        busy_loop2(LONG_LOOP); 
        exit();
    }

    // Parent process
    int n1 = numberofprocesses();

    wait(); // Wait for child 1
    int n2 = numberofprocesses();

    wait(); // Wait for child 2
    int n3= numberofprocesses();

    printf(1, "ready processes: %d\n", n1);
    printf(1, "ready processes: %d\n", n2);
    printf(1, "ready processes: %d\n", n3);



    exit();
}




