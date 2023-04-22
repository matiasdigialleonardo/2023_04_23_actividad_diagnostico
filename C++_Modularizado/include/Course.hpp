#if !defined(COURSE_HPP)
#define COURSE_HPP

#include <iostream>
#include <string>

using namespace std;

class Course
{
	private:
		int _identifier;
		string _name;
	
	public:
		Course();
		~Course();
		void setIdentifier(int identifier);
		void setName(string name);
		int getIdentifier();
		string getName();

};


#endif // COURSE_HPP
