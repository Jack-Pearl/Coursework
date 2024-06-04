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
void writeToFile(const std::vector<Person>& people, const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    for (const auto& person : people) {
        file << person.name << " " << person.surname << " " << person.age << " " << person.status << "\n";
    }
}

std::vector<Person> readFromFile(const std::string& filename) {
    std::vector<Person> people;
    std::ifstream file(filename);
    std::string name, surname, status;
    int age;
    while (file >> name >> surname >> age >> status) {
        people.push_back(Person(name, surname, age, status));
    }
    return people;
}

int main() {

    return 0;
}