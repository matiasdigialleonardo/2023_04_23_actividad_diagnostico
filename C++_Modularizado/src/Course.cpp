#include <Course.hpp>

Course::Course(){};

Course::~Course(){}


void Course::setIdentifier(int identifier)
{
	_identifier = identifier;
}

void Course::setName(string name)
{
	_name = name;
}

int Course::getIdentifier()
{
	return _identifier;
}

string Course::getName()
{
	return _name;
}