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

    };
}
