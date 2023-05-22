#include <iostream>
#include <stack>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    // стэки
    stack <string> q({ "q", "w", "e", "r", "t", "u", "i", "o", "p", "s", "d", "a" });
    stack <string> sogl;
    stack <string> gl;
    stack <string> itog;
    stack <string> itog0;

    while (!q.empty())
    {
        
        if (q.top() == "e" || q.top() == "u" || q.top() == "i" || q.top() == "o" || q.top() == "a") // если гласные буквы
        {
            gl.push(q.top()); // добавляем в новый стэк
            q.pop(); // удаляем из старого стэка
        }
        else // согласные буквы
        {
            sogl.push(q.top());
            q.pop();

        }
    }

    while (!sogl.empty()) // реверс стэка с согласными
    {
        itog0.push(sogl.top());
        sogl.pop();
    }
    while (!itog0.empty()) // добавление согласных букв к итогову стеку
    {
        itog.push(itog0.top());
        itog0.pop();
    }
    while (!gl.empty()) // реверс стэка с гласными
    {
        itog0.push(gl.top());
        gl.pop();
    }
    while (!itog0.empty()) // добавление гласных букв к итогову стеку
    {
        itog.push(itog0.top());
        itog0.pop();
    }
    while (!itog.empty()) // вывод полученного стека
    {
        cout << itog.top() << "  ";
        itog.pop();
    }
}
