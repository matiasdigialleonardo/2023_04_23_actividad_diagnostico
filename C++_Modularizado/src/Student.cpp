#include <Student.hpp>

Student::Student(){};

Student::~Student(){};

void Student::setIdentifier(int identifier)
{
	_identifier = identifier;
}

void Student::setName(string name)
{
	_name = name;
}

void Student::setSurname(string surname)
{
	_surname = surname;
}

int Student::getIdentifier()
{
	return _identifier;
}

string Student::getName()
{
	return _name;
}

string Student::getSurname()
{
	return _surname;
}