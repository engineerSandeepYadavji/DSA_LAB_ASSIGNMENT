#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    int rollNo;
    char name[50];      // Fixed-length character array for name
    char address[100];  // Fixed-length character array for address
    char division;

    void inputStudentData() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore(); // Clear the input buffer
        cout << "Enter Name: ";
        cin.getline(name, 50); // Read name into char array
        cout << "Enter Division: ";
        cin >> division;
        cin.ignore(); // Clear the input buffer again for getline
        cout << "Enter Address: ";
        cin.getline(address, 100); // Read address into char array
    }

    void displayStudentData() {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Division: " << division << endl;
        cout << "Address: " << address << endl;
    }
};

void addStudent() {
    Student student;
    student.inputStudentData();

    ofstream outFile;
    outFile.open("student.dat", ios::binary | ios::app);
    if (outFile) {
        outFile.write((char*)&student, sizeof(student)); // Directly write the object
        cout << "Student record added successfully.\n";
    } else {
        cout << "Error: Unable to open file for writing.\n";
    }
    outFile.close();
}

void searchStudent(int roll) {
    ifstream inFile;
    inFile.open("student.dat", ios::binary);
    if (!inFile) {
        cout << "Error: Unable to open file for reading.\n";
        return;
    }

    Student student;
    bool found = false;

    while (inFile.read((char*)&student, sizeof(student))) { // Read the object
        if (student.rollNo == roll) {
            student.displayStudentData();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record not found.\n";
    }
    inFile.close();
}

void displayStudent() {
    ifstream inFile("student.dat", ios::binary);
    if (!inFile) {
        cout << "Error: Unable to open file for reading.\n";
        return;
    }

    Student student;
    bool found = false;

    while (inFile.read((char*)&student, sizeof(student))) { // Read the object
        student.displayStudentData();
        found = true;
    }

    if (!found) {
        cout << "File is empty.\n";
    }
    inFile.close();
}

void deleteStudent(int roll) {
    ifstream inFile("student.dat", ios::binary);
    ofstream tempFile("temp.dat", ios::binary);
    if (!inFile || !tempFile) {
        cout << "Error: Unable to open files.\n";
        return;
    }

    Student student;
    bool found = false;

    while (inFile.read((char*)&student, sizeof(student))) { // Read the object
        if (student.rollNo == roll) {
            found = true;
        } else {
            tempFile.write((char*)&student, sizeof(student)); // Write to temp file
        }
    }

    inFile.close();
    tempFile.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found) {
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Record not found.\n";
    }
}

int main() {
    int choice, roll;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout<<"4. Display All Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter Roll Number to search: ";
                cin >> roll;
                searchStudent(roll);
                break;
            case 3:
                cout << "Enter Roll Number to delete: ";
                cin >> roll;
                deleteStudent(roll);
                break;
            case 4:
                displayStudent() ;
                break;
            case 5:
                cout<<"Program EXITTED Successfully :) "<<endl; 
                break ;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
