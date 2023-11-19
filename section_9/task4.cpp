#include <iostream>
#include <string>
#include <sys/wait.h>
#include <thread>

using namespace std;

const int MAX_SIZE = 100;
string nameToAppend;

int changeName(void* ptr) {
  char nameToCheck[MAX_SIZE];
  sethostname(nameToAppend.data(), nameToAppend.length());
  gethostname(nameToCheck, MAX_SIZE);
  cout << "Child hostname: " << nameToCheck << endl;
  
  return 0;
}

int main(int n, char *argv[]) {
  char currName[MAX_SIZE];
	nameToAppend = argv[1];
	gethostname(currName, MAX_SIZE);
	cout << "Parent hostname: " << currName << endl;

	const int STACK_SIZE = 1024 * 10;
	unique_ptr<char[]> child_stack(new char[STACK_SIZE]);

	clone(changeName, child_stack.get() + STACK_SIZE, CLONE_NEWUSER | CLONE_NEWUTS | SIGCHLD, 0);
	int status = 0;
	wait(&status);

	return 0;
}
