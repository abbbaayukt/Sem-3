#include <iostream>
#include <vector>
#include <string>
using namespace std;

class person {
protected:
    string name;
    int day, month, year;
public:
    person() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Date of birth (DD MM YYYY): ";
        cin >> day >> month >> year;
    }

    int age() {
        int currentYear = 2024;
        int currentMonth = 2;
        int currentDay = 28;
        int calculatedAge = currentYear - year;

        if (month > currentMonth || (month == currentMonth && day > currentDay)) {
            calculatedAge--;
        }
        return calculatedAge;
    }
};

class teaching : virtual public person {
protected:
    string course;
public:
    teaching() {
        cout << "Enter course: ";
        cin >> course;
    }
};

class nonteaching : virtual public person {
protected:
    int experience;
public:
    nonteaching() {
        cout << "Enter experience (years): ";
        cin >> experience;
    }
};

class employee : public teaching, public nonteaching {
protected:
    string department;
    long long salary;
    int empId;
public:
    employee() : person(), teaching(), nonteaching() {
        cout << "Enter Department: ";
        cin >> department;
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter empId: ";
        cin >> empId;
    }

    string getCourse() {
        return course;
    }

    string getDepartment() {
        return department;
    }

    long long getSalary() {
        return salary;
    }

    void display() {
        int a = age();
        cout << "Name: " << name << endl;
        cout << "Age: " << a << endl;
        cout << "Salary: " << salary << endl;
        cout << "EmpId: " << empId << endl;
        cout << "Department: " << department << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

void empByCourse(string s, vector<employee>& v) {
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getCourse() == s) {
            count++;
        }
    }
    cout << "Employees for course " << s << " are " << count << endl;
}

void empByDepartment(string s, vector<employee>& v) {
    int count = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getDepartment() == s) {
            count++;
        }
    }
    cout << "Employees for department " << s << " are " << count << endl;
}

long long totalSalary(vector<employee>& v) {
    long long ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += v[i].getSalary();
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    
    vector<employee> v;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Employee " << i + 1 << ":" << endl;
        employee e;
        v.push_back(e);
    }
    
    cout << "\nEmployees Details:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << ":" << endl;
        v[i].display();
    }
    
    string course;
    cout << "\nEnter course to find employees: ";
    cin >> course;
    empByCourse(course, v);

    string department;
    cout << "Enter department to find employees: ";
    cin >> department;
    empByDepartment(department, v);

    cout << "Total salary of all employees: " << totalSalary(v) << endl;
    
    return 0;
}
