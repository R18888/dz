#include <iostream>
#include <list>


using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    list<int> lst = { 8, 2, 1, 6, 8, 8, 1, 2, 2, 8, 2, 1 };
    list<int> itog;

    int max, k = 0, c = 0;

    bool flag = true;

    // начальный вывод
    for (auto it = lst.begin(); it != lst.end(); ++it)
        cout << *it << "  ";

    cout << endl << endl;

    auto pos_it = lst.begin();
    max = *pos_it;

    for (auto it = lst.begin(); it != lst.end(); ++it)
        if (*it > max)
            max = *it; // максимальное число

    for (auto it = lst.begin(); it != lst.end(); ++it) // подсчет максимальных чисел
    {
        if (*it == max)
        {
            k++;
        }
    }


    for (auto it = lst.begin(); it != lst.end(); ++it) // удаление первого и последнего максимального числа
    {
        if (*it == max)
            c++;

        itog.push_back(*it);

        if (*it == max && flag)
        {
            itog.pop_back();
            flag = false;
        }

        if (*it == max && c == k)
            itog.pop_back();

    }

    // измененный вывод
    for (auto it = itog.begin(); it != itog.end(); ++it)
        cout << *it << "  ";

    return 0;
}
