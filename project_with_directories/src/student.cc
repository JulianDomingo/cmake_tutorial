#include <iostream>
#include <student/student.h>

Student::Student(std::string name):name(name) {}

void Student::display(void)
{
    std::cout << "A student with name: " << this->name << std::endl;
}
