#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
	pid_t pid = fork();
	
	if (pid == 0) {
		const char* name = "expr";
		execlp(name, name, "2", "+", "2", "*", "2", nullptr);
		exit(0);
	}

	int status = 0;
	wait(&status);

	return 0;
}
