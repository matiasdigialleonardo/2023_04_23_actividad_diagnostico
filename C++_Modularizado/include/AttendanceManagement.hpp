#if !defined(ATTENDANCEMANAGEMENT_HPP)
#define ATTENDANCEMANAGEMENT_HPP

#include <iostream>
#include <string>
#include <Student.hpp>
#include <Course.hpp>
#include <fstream>

class AttendanceManagement
{
	public:
		AttendanceManagement();
		~AttendanceManagement();
		void takeAttendance(Student* student, Course* course, string datetime, bool state);
		void showAttendance();
};

#endif // ATTENDANCEMANAGEMENT_HPP
