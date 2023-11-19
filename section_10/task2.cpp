#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <system_error>
#include <cerrno>
using namespace std;

class File {
private:
    int filedir;

    long check(long result) {
        if (result == long(-1)) {
            throw std::system_error(errno, std::generic_category());
        }
        return result;
    }

    void findFile(File& file) {
        filedir = file.filedir;
        file.filedir = -1;
    }

public:
    File(const File& file) {
        findFile(const_cast<File&>(file));
    }

    File(const string& path) {
        const char* buffer = path.c_str();  // Use c_str() to get a const char*
        this->filedir = this->check(open(buffer, O_CREAT | O_RDWR, 0644));
        clog << "Open" << endl;
    }

    ~File() {
        this->check(close(this->filedir));
    }

    File& operator=(const File& file) {
        findFile(const_cast<File&>(file));
        return *this;
    }

    void writeFile(const string& txt) {
        const char* buf = txt.c_str();
        this->check(write(this->filedir, buf, txt.size()));  // Use txt.size() instead of sizeof(txt)
    }

    string readFile(int size) {
        char buf[size + 1];
        this->check(read(this->filedir, buf, size));
        buf[size] = '\0';
        return string(buf);
    }
};

void function() {
  File name("file.txt");
  string str = "something";
  cout << name.readFile(str.length()) << endl;
  name.writeFile(str);
}

int main() {
	function();
	return 0;
}
