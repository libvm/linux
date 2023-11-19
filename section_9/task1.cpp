#include<iostream>
#include<unistd.h>
#include<sys/syscall.h>

using namespace std;

int main() {
  pid_t id1 = getpid();
  pid_t id2 = syscall(SYS_gettid);
  if (id1 == id2)
    cout << id1 << " and " << id2 << " are equal" << endl;
  else cout << id1 << " and " << id2 << " are not equal" << endl;
  return 0;
}
