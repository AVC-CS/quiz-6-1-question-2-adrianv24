// main.hpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int writeFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file." << endl;
         return 0;
    }
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    file << numEmployees << endl;
    for (int i = 0; i < numEmployees; ++i) {
        int id;
        string name, department;
        double salary;

        
        
        cout << "Enter Employee ID, Name, Department, and Salary: ";
        cin >> id >> name >> department >> salary;
        file << id << " " << name << " " << department << " " << salary << endl;
    }
    cout << "Employee records have been written to " << filename << endl;
    file.close();
    return numEmployees;
}

int readFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 0;
    }

    int totalEmployees = 0;
    int numEmployees;
    file >> numEmployees;

    cout << "ID\tName\tDepartment\tSalary" << endl;
    for (int i = 0; i < numEmployees; ++i) {
        int id;
        string name, department;
        double salary;

        file >> id >> name >> department >> salary;

        totalEmployees++;

        cout << id << "\t" << name << "\t" << department << "\t" << salary << endl;
    }

    file.close();
    return totalEmployees;
}