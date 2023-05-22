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

// функция для сравнения по дате рождения
bool compareBirthday(const Employee& a, const Employee& b) {
    if (a.year != b.year) {
        return a.year < b.year;
    }
    if (a.month != b.month) {
        return a.month < b.month;
    }
    return a.day < b.day;
}

// функция сортировки перемешиванием
void cocktailSort(vector<Employee>& v, bool (*comp)(const Employee&, const Employee&)) {
    int n = v.size();
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++) {
            if (comp(v[i + 1], v[i])) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        end--;
        for (int i = end - 1; i >= start; i--) {
            if (comp(v[i + 1], v[i])) {
                swap(v[i], v[i + 1]);
                swapped = true;
            }
        }
        start++;
    }
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

    // сортируем вектор по дате рождения
    cocktailSort(employees, compareBirthday);

    // записываем данные в новый файл
    ofstream output("13.txt");
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
