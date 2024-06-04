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
        TEST_METHOD(GetResultMenuOptions)
        {
            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf();
            std::cout.rdbuf(buffer.rdbuf());
            std::cout << "Choose the number of the desired action:\n";
            std::cout << "1. Add new person\n";
            std::cout << "2. Show the list of persons\n";
            std::string expectedOutput = "Choose the number of the desired action:\n1. Add new person\n2. Show the list of persons\n";
            Assert::AreEqual(expectedOutput, buffer.str());
            std::cout.rdbuf(oldCout);
        }

        TEST_METHOD(GetNameValueFalseTrue)
        {
            std::string longname = "NameNameNameNameNameNameNameNam";
            std::string name = "Name";
            Assert::IsFalse(longname.length() <= 30);
            Assert::IsTrue(name.length() <= 30);
        }

        TEST_METHOD(GetSurnameValueFalseTrue)
        {
            std::string longsurname = "SurnameSurnameSurnameSurnameSurnameSur";
            std::string surname = "Surname";
            Assert::IsFalse(longsurname.length() <= 30);
            Assert::IsTrue(surname.length() <= 30);
        }
        TEST_METHOD(GetValueAgeTrueTrueFalse)
        {
            int invalidAge = 10;
            int validAge = 30;
            int moreAge = 65;
            Assert::IsTrue(moreAge >= 15 && moreAge <= 65);
            Assert::IsTrue(validAge >= 15 && validAge <= 65);
            Assert::IsFalse(invalidAge >= 15 && invalidAge <= 65);
        }

        TEST_METHOD(GetNormalEvaderWanted)
        {
            std::string status1 = "normal";
            std::string status2 = "evader";
            std::string status3 = "wanted";
            Assert::AreEqual(status1.c_str(), "normal");
            Assert::AreEqual(status2.c_str(), "evader");
            Assert::AreEqual(status3.c_str(), "wanted");
        }
    };
}
