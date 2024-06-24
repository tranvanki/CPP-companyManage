#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    float rate;

public:
    Employee(int newId, float newRate, const string& newName) : id(newId), rate(newRate), name(newName) {}

    int getId() const {
        return id;
    }

    float getRate() const {
        return rate;
    }

    string getName() const {
        return name;
    }

    void show() const {
        cout << "ID: " << id << " Rate: " << rate << " Name: " << name << endl;
    }

    void setRate(float newRate) {
        rate = newRate;
    }
};

class Company {
private:
    vector<Employee> employees;

    Employee* __search_id(int id) {
        for (auto& employee : employees) {
            if (employee.getId() == id) {
                return &employee;
            }
        }
        return nullptr;
    }

public:
    void add_employee(const Employee& e) {
        employees.push_back(e); // push_back = append
        cout << "Employee " << e.getName() << " added successfully!" << endl;
    }

    void remove() {
        int id;
        cout << "Enter ID: ";
        cin >> id;
        int pos = check_id(id);
        if (pos == -1) {
            cout << "ID " << id << " not found!" << endl;
            return;
        }
        Employee removed_employee = employees[pos];
        employees.erase(employees.begin() + pos);
        cout << "Employee " << removed_employee.getName() << " removed!" << endl;
    }

    void change() {
        int id;
        cout << "Enter the ID: ";
        cin >> id;
        int pos = check_id(id);
        if (pos == -1) {
            cout << "ID " << id << " doesn't exist!" << endl;
            return;
        }
        float new_rate;
        cout << "Enter new rate: ";
        cin >> new_rate;
        employees[pos].setRate(new_rate);
        cout << "Rate for employee ID " << id << " updated successfully!" << endl;
    }

    void show_employee() {
        int id;
        cout << "Enter the ID: ";
        cin >> id;
        Employee* employee = __search_id(id);
        if (employee == nullptr) {
            cout << "ID " << id << " doesn't exist!" << endl;
            return;
        }
        employee->show();
    }

    void show_all() {
        cout << "All Employees:" << endl;
        for (const auto& employee : employees) {
            employee.show();
        }
    }

    int check_id(int id) {
        for (size_t i = 0; i < employees.size(); ++i) {
            if (employees[i].getId() == id) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Company company;

    while (true) {
        cout << "****COMPANY MANAGEMENT****" << endl;
        cout << "0. Quit" << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Remove employee" << endl;
        cout << "3. Change rate" << endl;
        cout << "4. Search employee" << endl;
        cout << "5. Show all" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Closing the program..." << endl;
            break;
        } else if (choice == 1) {
            string name;
            int id;
            float rate;
            cout << "Enter the employee's name: ";
            cin >> name;
            cout << "Enter the employee's ID: ";
            cin >> id;
            cout << "Enter the employee's rate: ";
            cin >> rate;
            Employee new_employee(id, rate, name);
            company.add_employee(new_employee);
        } else if (choice == 2) {
            company.remove();
        } else if (choice == 3) {
            company.change();
        } else if (choice == 4) {
            company.show_employee();
        } else if (choice == 5) {
            company.show_all();
        } else {
            cout << "Please enter a valid choice!" << endl;
        }
    }

    return 0;
}
