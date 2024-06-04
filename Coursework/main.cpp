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
    std::vector<Person> people;
    std::string name, surname, status;
    int age;
    char more = 'y';

    do {
        std::cout << "Choose the number of the desired action:\n";
        std::cout << "1. Add new person\n";
        std::cout << "2. Show the list of persons\n";
        int number;
        std::cin >> number;

        if (number == 1) {
            do {
                std::cout << "Enter name (max 30 characters): ";
                std::cin >> name;
                if (name.length() > 30) {
                    std::cout << "Name is too long. Please try again.\n";
                }
            } while (name.length() > 30);

            do {
                std::cout << "Enter surname (max 30 characters): ";
                std::cin >> surname;
                if (surname.length() > 30) {
                    std::cout << "Surname is too long. Please try again.\n";
                }
            } while (surname.length() > 30);

            do {
                std::cout << "Enter age: ";
                std::cin >> age;
                if (age < 15 || age > 65) {
                    std::cout << "Invalid age. Please try again.\n";
                }
            } while (age < 15 || age > 65);

            do {
                std::cout << "Enter status (normal, evader, wanted): ";
                std::cin >> status;
                if (status != "normal" && status != "evader" && status != "wanted") {
                    std::cout << "Invalid status. Please try again.\n";
                }
            } while (status != "normal" && status != "evader" && status != "wanted");

            people.push_back(Person(name, surname, age, status));
            writeToFile(people, "people.txt");
            people.clear();
        }
        else if (number == 2) {
            std::vector<Person> loadedPeople = readFromFile("people.txt");
            for (const auto& person : loadedPeople) {
                std::cout << "Name: " << person.name << " Surname: " << person.surname << " Age: " << person.age << " Status: " << person.status << "\n";
            }
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << "Would you like more? (y/n): \n";
        std::cin >> more;
    } while (more == 'y' || more == 'Y');

    return 0;
}