import csv
import os

ATTENDANCE_FILENAME =  "attendance.csv"

class Student:
    
    #Ask the teacher wich constructor is better, this one or the one below it.  
    #def __init__(self):
    #    self._identifier = 0
    #    self._name = ""
    #    self._surname = ""
        
    def __init__(self, identifier = 0, name = "", surname = ""):
        self._identifier = identifier
        self._name = name
        self._surname = surname

    def setIdentifier(self, identifier):
        self._identifier = identifier

    def setName(self, name):
        self._name = name

    def setSurname(self, surname):
        self._surname = surname

    def getIdentifier(self):
        return self._identifier

    def getName(self):
        return self._name

    def getSurname(self):
        return self._surname

class Course:
    def __init__(self):
        self._identifier = 0
        self._name = ""

    def setIdentifier(self, identifier):
        self._identifier = identifier

    def setName(self, name):
        self._name = name

    def getIdentifier(self):
        return self._identifier

    def getName(self):
        return self._name

class AttendanceManagement:
 
    def __init__(self):
        pass

    def takeAttendance(self, student, course, datetime, state):
        #mode="a" creates the file if it didnt exist before or to add data at the end of the file.
        with open(ATTENDANCE_FILENAME, mode="a", newline="") as attendanceFile:
            #Creates a "writer" object that writes in the attendanceFile
            attendanceFileWriter = csv.writer(attendanceFile)
            #If the filezise is equal to 0 (is empty) write the table headers
            if os.path.getsize(ATTENDANCE_FILENAME) == 0:
                attendanceFileWriter.writerow(["Id del estudiante", "Nombre/s", "Apellidos/s", "Id de la materia", "Nombre de la materia", "Marca temporal", "Presente"])

            attendanceFileWriter.writerow([student.getIdentifier(), student.getName(), student.getSurname(), course.getIdentifier(), course.getName(), datetime, state])

    def showAttendance(self):
        with open(ATTENDANCE_FILENAME, mode="r") as attendanceFile:
            #reader provides an iterator that reads through the csv file and 
            #returns the content as a list of strings.
            #each time it reads a line the __next__ method of the operator is called
            #to read the next line.         
            attendanceFileReader = csv.reader(attendanceFile)
            for row in attendanceFileReader:
                print(row)


#Which way of creating an object is better?
student = Student(1, "Juan", "Perez")

#student.setIdentifier(1)
#student.setName("Juan")
#student.setSurname("Perez")

course = Course()
course.setIdentifier(1)
course.setName("Algebra")

attendanceManagement = AttendanceManagement()
attendanceManagement.takeAttendance(student, course, "2021-06-08", True)

attendanceManagement.showAttendance()
