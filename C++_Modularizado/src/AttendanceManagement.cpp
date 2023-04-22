#include <AttendanceManagement.hpp>

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