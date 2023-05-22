#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool odd(int x) {
	return x % 2 == 0;
}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "Введите колличество целых чисел: \n"; int n; cin >> n;// колличество целых чисел
	cout << "Введите число X: \n"; int x; cin >> x;
	vector<int>a;
	cout << "Введите члены первой последовательности " << endl;
	for (int i = 0; i < n; i++) { // ввожу в вектор нужные значения
		int x; cin >> x;
		a.push_back(x);
	}
	cout << "Удаление чётных элементов:" << endl;
	vector<int>::iterator it = remove_if(a.begin(), a.end(), odd); // удаляю чётные элементы с помощью функции
	a.erase(it, a.end());
	for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	int m = a.size();//размерность вектора
	int max = *max_element(a.begin(), a.end()); // поиск максимального эл-та
	int min = *min_element(a.begin(), a.end()); // поиск минимального эл-та
	cout << "Замена максимальных на минимальный :" << endl; //замена и вывод максимальных на минимальный элементов
	for (int i = 0; i < m; i++) {
		if (a[i] == max)
			a[i] = min;
	}
	for (int i = 0; i < m; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	int k = 0;
	for (int i = 0; i < m; i++) {// счётчик кратных элменетов
		if (a[i] % x == 0) {
			k = k + 1;
		}
	}
	cout << "Колличество элементов кратных " << x << ": " << k;
}
