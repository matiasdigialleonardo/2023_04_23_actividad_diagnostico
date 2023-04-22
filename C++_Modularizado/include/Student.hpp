#if !defined(STUDENT_HPP)
#define STUDENT_HPP

#include <iostream>
#include <string>

using namespace std;

class Student
{
	private:
		int _identifier;
		string _name;
		string _surname;

	public:
		Student();
		~Student();
		void setIdentifier(int identifier);
		void setName(string name);
		void setSurname(string surname);
		int getIdentifier();
		string getName();
		string getSurname();
};


#endif // STUDENT_HPP
