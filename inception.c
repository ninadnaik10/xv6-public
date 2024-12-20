#include "types.h"
#include "user.h"

int main(int argc, char *argv[])

{
//	for (int i=0; i<argc; i++){
	//	printf(1, argv[i]);
	//}

    if (argc < 2)

    {

        printf(1, "Usage: %s <program> [arguments...]\n", argv[0]);

        exit();

    }

//	int parentid = getpid();
//	printf(1, "[P] Parent process PID: %d\n", parentid);
	int pid = fork();
        if(pid > 0) {
//		printf(1, "[P] Waiting for child process w/ PID %d\n", pid);
		pid = wait();
//		printf(1, "[P] Child process w/ PID %d exited\n", pid);
	}
	else if (pid == 0) {
//		int childpid = getpid();
//		printf(1, "[C] Child process w/ PID %d\n", childpid);
// printf(1, "[C] Executing a program");
		exec(argv[1], argv+1);
		exit();
	}

//	exit();
}
