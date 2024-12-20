#include "types.h"
#include "user.h"

int main(){
	int parentid = getpid();
	printf(1, "[P] Parent process PID: %d\n", parentid);
	int pid = fork();
        if(pid > 0) {
		printf(1, "[P] Waiting for child process w/ PID %d\n", pid);
		pid = wait();
		printf(1, "[P] Child process w/ PID %d exited\n", pid);
	}
	else if (pid == 0) {
		int childpid = getpid();
		printf(1, "[C] Child process w/ PID %d\n", childpid);
		exit();
	}

	exit();
}	
