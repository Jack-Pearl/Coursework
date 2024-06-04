#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Person {
public:
    std::string name;
    std::string surname;
    int age;
    std::string status;

    Person(std::string n, std::string s, int a, std::string st) : name(n), surname(s), age(a), status(st) {}
};

int main() {

    return 0;
}