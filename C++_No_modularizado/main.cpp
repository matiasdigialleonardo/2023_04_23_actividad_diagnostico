#include <iostream>
#include <string>
#include <fstream>

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

class AttendanceManagement
{
	public:
		AttendanceManagement();
		~AttendanceManagement();
		void takeAttendance(Student* student, Course* course, string datetime, bool state);
		void showAttendance();
};



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

AttendanceManagement::AttendanceManagement(){};

AttendanceManagement::~AttendanceManagement(){};

// Pide dos parametros por puntero que son student y course, de sus respectivas clases.
void AttendanceManagement::takeAttendance(Student *student, Course *course, string datetime, bool state)
{
	// Abre archivo para lectura
	ifstream testOpenFile("attendance.csv");
	// Si el archivo existe guarda true, si no, guarda false
	bool fileExists = testOpenFile.good();
	testOpenFile.close();

	ofstream attendanceFile;
	// Se utiliza "app" para escribir en el archivo al final del mismo.
	attendanceFile.open("attendance.csv", ofstream::app);
	if (!fileExists) // Si el archivo no existia, se escriben los encabezados.
	{
		attendanceFile << "Id del estudiante, "
			<< "Nombre/s,"
			<< "Apellidos/s,"
			<< "Id de la materia,"
			<< "Nombre de la materia,"
			<< "Marca temporal,"
			<< "Presente\n";
	}

	// Se piden los datos para cada campo del archivo.
	attendanceFile << student->getIdentifier() << ","
		<< student->getName() << ","
		<< student->getSurname() << ","
		<< course->getIdentifier() << ","
		<< course->getName() << ","
		<< datetime << ","
		<< state << "\n";

	attendanceFile.close();
}

void AttendanceManagement::showAttendance()
{
	ifstream attendanceFile("attendance.csv");
	string line;

	if (attendanceFile.is_open())
	{
		while(getline(attendanceFile, line))
		{
			cout << line << endl;
		}
	}

	attendanceFile.close();
}