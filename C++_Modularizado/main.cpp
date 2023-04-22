#include <iostream>
#include <Student.hpp>
#include <Course.hpp>
#include <AttendanceManagement.hpp>

using namespace std;

int main()
{
    Student* student = new Student();
    student->setIdentifier(1);
    student->setName("Juan");
    student->setSurname("Perez");

    Course* course = new Course();
    course->setIdentifier(1);
    course->setName("Algebra");

    AttendanceManagement* attendanceManagement = new AttendanceManagement();
    attendanceManagement->takeAttendance(student, course, "2021-06-08", true);


    attendanceManagement->showAttendance();

    delete student;
    delete course;
    delete attendanceManagement;

    return 0;
}