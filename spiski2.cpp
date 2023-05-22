#include <iostream>
#include <list>


using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    list<int> lst = { 8, 2, 1, 6, 3, 5, 4, 2, 1, 8, 9, 7 };
    list<int> itog;
    list<int> m5;

    int x = 5;

    // начальный вывод
    for (auto it = lst.begin(); it != lst.end(); ++it)
        cout << *it << "  ";

    cout << endl << endl;

    for (auto it = lst.begin(); it != lst.end(); ++it) // перенос в конец списка числа меньшие Х
    {
        if (*it < 5)
            m5.push_back(*it);
        else
            itog.push_back(*it);
    }

    for (auto it = m5.begin(); it != m5.end(); ++it) // перенос в конец списка числа меньшие Х
    {
        itog.push_back(*it);
    }

    // измененный вывод
    for (auto it = itog.begin(); it != itog.end(); ++it)
        cout << *it << "  ";

    return 0;
}
