const ATTENDANCE_FILENAME = "attendance.csv";

//Constuctor function for the Student object
function Student() {
    this._identifier = 0;
    this._name = "";
    this.surname = "";
}

//Adds setters and getter to the Student prototype
Student.prototype.setIdentifier = function(identifier) {
    this._identifier = identifier;
  };
  
  Student.prototype.setName = function(name) {
    this._name = name;
  };
  
  Student.prototype.setSurname = function(surname) {
    this._surname = surname;
  };
  
  Student.prototype.getIdentifier = function() {
    return this._identifier;
  };
  
  Student.prototype.getName = function() {
    return this._name;
  };
  
  Student.prototype.getSurname = function() {
    return this._surname;
  };


//Constuctor function for the Course object
function Course() {
    this._identifier = 0;
    this._name = "";
}

//Adds setters and getters to the Course prototype
Course.prototype.setIdentifier = function(identifier) {
    this._identifier = identifier;
}

Course.prototype.setName = function(name) {
    this._name = name;
}

Course.prototype.getIdentifier = function() {
    return this._identifier;
}

Course.prototype.getName = function() {
    return this._name;
}

//Empty Constuctor function for the Course object
function AttendanceManagement() {}

//Methods for the AttendanceManagement object
AttendanceManagement.prototype.takeAttendance = function(student, course, datetime, state) {
        //Use the filesystem module from node.js
        const fs = require("fs");
        //existsSync returns true if the path exists.
        const fileExists = fs.existsSync(ATTENDANCE_FILENAME);
        //Flags a opens the path for appending, creates the file if it does not exist, w is for writing. 
        const attendanceFile = fs.createWriteStream(ATTENDANCE_FILENAME, {
            flags: fileExists ? "a" : "w",
        });
        //If the file didn`t exist, write the table headers.
        if (!fileExists) {
            attendanceFile.write(
                "Id del estudiante,Nombre/s,Apellidos/s,Id de la materia,Nombre de la materia,Marca temporal,Presente\n"
            );
        }

        attendanceFile.write(
            `${student.getIdentifier()},${student.getName()},${student.getSurname()},${course.getIdentifier()},${course.getName()},${datetime},${state}\n`
        );

        attendanceFile.close();
}

AttendanceManagement.prototype.showAttendance = function() {

    const fs = require("fs");
    const fileStream = fs.createReadStream(ATTENDANCE_FILENAME);
    fileStream.on("data", (line) => {
        console.log(line.toString());
    });
}

const student = new Student();
student.setIdentifier(1);
student.setName("Juan");
student.setSurname("Perez");

const course = new Course();
course.setIdentifier(1);
course.setName("Algebra");

const attendanceManagements = new AttendanceManagement();
attendanceManagements.takeAttendance(student, course, "2021-06-08", true);

attendanceManagements.showAttendance();
