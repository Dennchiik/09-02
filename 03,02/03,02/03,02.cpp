#include <iostream>
#include <initializer_list>
#include <cstring>

class MyString {
private:
    char* str;

public:
    MyString() : str(nullptr) {}

    MyString(const char* s) {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }

    MyString(std::initializer_list<char> il) {
        str = new char[il.size() + 1];
        int i = 0;
        for (char c : il) {
            str[i++] = c;
        }
        str[i] = '\0';
    }

    ~MyString() {
        delete[] str;
    }

    void display() const {
        std::cout << str << std::endl;
    }
};

int main() {
    MyString str1("Hello");
    str1.display();

    MyString str2{ 'W', 'o', 'r', 'l', 'd' };
    str2.display();

    return 0;
}
