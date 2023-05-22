#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Employee {
    string surname;
    string position;
    int day;
    int month;
    int year;
    int experience;
    int salary;
};

// функция для сравнения по зарплате
bool compareSalary(const Employee& a, const Employee& b) {
    return a.salary < b.salary;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Employee> employees;

    // читаем данные из файла в вектор
    ifstream input("employees.txt");
    if (!input.is_open()) {
        cout << "Ошибка при открытии файла\n";
        return 1;
    }

    Employee employee;
    while (input >> employee.surname >> employee.position >> employee.day
        >> employee.month >> employee.year >> employee.experience >> employee.salary) {
        employees.push_back(employee);
    }

    // сортируем вектор по зарплате
    sort(employees.begin(), employees.end(), compareSalary);

    // записываем данные в новый файл
    ofstream output("sorted_employees.txt", ios::out | ios::binary);
    if (!output.is_open()) {
        cout << "Ошибка при создании файла\n";
        return 1;
    }

    output << "Фамилия\tДолжность\tДата рождения\tСтаж\tЗарплата\n";
    for (const auto& emp : employees) {
        output << emp.surname << '\t' << emp.position << '\t'
            << emp.day << '.' << emp.month << '.' << emp.year << '\t'
            << emp.experience << '\t' << emp.salary << '\n';
    }

    input.close();
    output.close();
    cout << "Данные успешно отсортированы и записаны в файл sorted_employees.txt\n";
    return 0;
}
