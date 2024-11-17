#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Employee {
public:
    int id;
    string name;
    float salary;
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }
    void displayData() const {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};
void writeToTextFile(Employee &emp) {
    ofstream out("employee.txt", ios::app);
    if (out.is_open()) {
        out << emp.id << " " << emp.name << " " << emp.salary << endl;
        out.close();
        cout << "Employee data written to text file successfully." << endl;
    } else {
        cout << "Unable to open file in text mode." << endl;
    }
}

void readFromTextFile() {
    ifstream in("employee.txt");
    if (in.is_open()) {
        Employee emp;
        while (in >> emp.id >> emp.name >> emp.salary) {
            emp.displayData();
            cout << "--------------------" << endl;
        }
        in.close();
    } else {
        cout << "Unable to open file in text mode." << endl;
    }
}

void writeToBinaryFile(Employee &emp) {
    ofstream out("employee.dat", ios::binary | ios::app);
    if (out.is_open()) {
        out.write((char*)(&emp), sizeof(emp));
        out.close();
        cout << "Employee data written to binary file successfully." << endl;
    } else {
        cout << "Unable to open file in binary mode." << endl;
    }
}
void readFromBinaryFile() {
    ifstream in("employee.dat", ios::binary);
    if (in.is_open()) {
        Employee emp;
        while (in.read((char*)(&emp), sizeof(emp))) {
            emp.displayData();
            cout << "--------------------" << endl;
        }
        in.close();
    } else {
        cout << "Unable to open file in binary mode." << endl;
    }
}

int main() {
    Employee emp;
    int choice;
    do {
        cout << "\nEmployee Record Management\n";
        cout << "1. Add Employee (Text Mode)\n";
        cout << "2. Display Employees (Text Mode)\n";
        cout << "3. Add Employee (Binary Mode)\n";
        cout << "4. Display Employees (Binary Mode)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            emp.getData();
            writeToTextFile(emp);
            break;
        case 2:
            readFromTextFile();
            break;
        case 3:
            emp.getData();
            writeToBinaryFile(emp);
            break;
        case 4:
            readFromBinaryFile();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
