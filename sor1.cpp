#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <codecvt>
#include <locale>

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

// функция для сравнения по зарплате, затем по фамилии
bool compareSalaryName(const Employee& a, const Employee& b) {
    if (a.salary == b.salary) {
        return a.surname < b.surname;
    }
    return a.salary < b.salary;
}

// функция для сортировки Шелла с шагом d = 3i - 1
void shellSort(vector<Employee>& arr, int n) {
    for (int gap = n / 3; gap > 0; gap /= 3) {
        for (int i = gap; i < n; i++) {
            Employee temp = arr[i];
            int j;
            for (j = i; j >= gap && compareSalaryName(arr[j - gap], temp); j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");

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

    // сортируем вектор по зарплате и фамилии с помощью сортировки Шелла
    shellSort(employees, employees.size());


    for (const auto& employee : employees) {
        std::cout << employee.surname << ", " << employee.position << ", " << employee.day
            << "." << employee.month << "." << employee.year << ", " << employee.experience
            << " years, salary: " << employee.salary << std::endl;
    }
    // записываем данные в новый файл
    ofstream output("7.txt", ios::out | ios::binary);
    if (!output.is_open()) {
        cout << "Ошибка при создании файла\n";
        return 1;
    }
    // устанавливаем локаль и кодировку UTF-8
    std::locale utf8_locale(std::locale(), new std::codecvt_utf8<wchar_t>);
    output.imbue(utf8_locale);

    output << "Фамилия\tДолжность\tДата рождения\tСтаж\tЗарплата\n";
    for (const auto& emp : employees) {
        output << emp.surname << '\t' << emp.position << '\t'
            << emp.day << '.' << emp.month << '.' << emp.year << '\t'
            << emp.experience << '\t' << emp.salary << '\n';
    }

    input.close();
    output.close();
    cout << "Данные успешно отсортированы и записаны в файл 7.txt\n";
    return 0;
}
