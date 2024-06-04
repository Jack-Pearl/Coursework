#include "pch.h"
#include "CppUnitTest.h"
#include "/Git/GitProjectAll/GitCoursework/CourseWork/CourseWork/main.cpp" 
#include <iostream>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCourseWork
{
    TEST_CLASS(TestCourseWork)
    {
    public:

        TEST_METHOD(GetJohnDoe30normal)
        {
            Person person("John", "Doe", 30, "normal");
            Assert::AreEqual(std::string("John"), person.name);
            Assert::AreEqual(std::string("Doe"), person.surname);
            Assert::AreEqual(30, person.age);
            Assert::AreEqual(std::string("normal"), person.status);
        }

        TEST_METHOD(WriteJohnDoe30normal)
        {
            std::vector<Person> people = { Person("John", "Doe", 30, "normal") };
            writeToFile(people, "/Git/GitProjectAll/GitCoursework/CourseWork/TestCourseWork/TestCourseWork.txt");

            std::ifstream file("/Git/GitProjectAll/GitCoursework/CourseWork/TestCourseWork/TestCourseWork.txt");
            std::string name, surname, status;
            int age;
            file >> name >> surname >> age >> status;

            Assert::AreEqual(std::string("John"), name);
            Assert::AreEqual(std::string("Doe"), surname);
            Assert::AreEqual(30, age);
            Assert::AreEqual(std::string("normal"), status);
        }

        TEST_METHOD(ReadJohnDoe30normal)
        {
            std::vector<Person> people = readFromFile("/Git/GitProjectAll/GitCoursework/CourseWork/TestCourseWork/TestCourseWork.txt");
            Assert::IsFalse(people.empty());
            Assert::AreEqual(std::string("John"), people[0].name);
            Assert::AreEqual(std::string("Doe"), people[0].surname);
            Assert::AreEqual(30, people[0].age);
            Assert::AreEqual(std::string("normal"), people[0].status);
        }
    };
}
