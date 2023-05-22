#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    // очереди
    queue <int> q({ 1, 2, 2, 1, 3, 4, 5, 1, 2, 5, 4, 3, 5 });
    queue <int> qq({ 1, 2, 2, 1, 3, 4, 5, 1, 2, 5, 4, 3, 5 });
    queue <int> w;
    queue <int> res;
    vector <int> vec;
    int x = 0;

    cout << "Начальная очередь: " << endl << endl;

    while (!qq.empty())
    {
        cout << qq.front() << "  ";
        qq.pop();
    }
    cout << endl << endl;

    cout << "Измененная очередь: " << endl << endl;

    while (!q.empty())
    {
        w.push(q.front());
        vec.push_back(w.back());

        q.pop();
        cout << w.back() << "  "; // вывод измененной очереди


        for (int i = 0; i < vec.size(); i++)
        {
            if (!q.empty() && q.front() == vec[i])
            {
                q.pop();
                i = -1;
            }
        }

    }




}
