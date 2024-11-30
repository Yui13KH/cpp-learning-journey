#include <iostream>
#include <string>
using namespace std;

struct strStudent {
    string name;
    int age;
    int grade;
};

void readStudent(strStudent &student) {
    cout << "Enter first name: ";
    getline(cin, student.name);

    cout << "Enter age: ";
    cin >> student.age;

    cout << "Enter grade: ";
    cin >> student.grade;  
    cin.ignore(1, '\n'); // ignores the Enter key or else the getline will skip taking the Enter as an input
    cout << '\n';
}

void printStudent(strStudent student) {
    cout << "Name: " << student.name << endl;
    cout << "Age: " << student.age << endl;
    cout << "Grade: " << student.grade << endl;
    cout << '\n';
}

void readStudents(strStudent student[3]) {
    readStudent(student[0]);
    readStudent(student[1]);
    readStudent(student[2]);
}

void printStudents(strStudent student[3]) {
    cout << "Students:" << endl;

    printStudent(student[0]);
    printStudent(student[1]);
    printStudent(student[2]);
}

int main() {
    strStudent student[3];
    readStudents(student);
    printStudents(student);
}
