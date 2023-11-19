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
        const char* buffer = path.c_str(); 
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
        this->check(write(this->filedir, buf, txt.size()));    
    }

    string readFile(int size) {
        char buf[size + 1];
        this->check(read(this->filedir, buf, size));
        buf[size] = '\0';
        return string(buf);
    }

     off_t getCurrentPosition() const {
       off_t currentPosition = lseek(filedir, 0, SEEK_CUR);
       if (currentPosition == -1) {
         throw std::system_error(errno, std::generic_category());
       }
       return currentPosition;
    }

    void setPosition(off_t offset) {
        off_t newPosition = lseek(filedir, offset, SEEK_SET);
        if (newPosition == -1) {
            throw std::system_error(errno, std::generic_category());
        }
    }
};

void function() {
  File name("file.txt");
  cout << "Current position: " << name.getCurrentPosition() << endl;
  name.setPosition(10);
  cout << "Updated position: " << name.getCurrentPosition() << endl;
  string str = "something";
  cout << name.readFile(str.length()) << endl;
  name.writeFile(str);
}

int main() {
  function();
  return 0;
}
