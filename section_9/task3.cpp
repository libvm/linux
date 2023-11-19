#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
  char** first = environ;

  while (*first) {
    string str(*first);
    if (str.find("L") < str.length()) { 
      cout << str << endl;
    }

    ++first;
  }

  return 0;
}
