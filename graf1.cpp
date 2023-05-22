//Граф представлен в виде списка смежности. Реализовать обход в ширину, используя очередь, и нерекурсивный обход в глубину.

#include <iostream>
#include <vector>
using namespace std;

//стек
struct stack	//описание стека
{
	int inf;
	stack* next;
};

void push_s(stack*& h, int x) {	//добавление элемента в стек
	stack* r = new stack;	//создание нового элемента
	r->inf = x;	//поле inf = х
	r->next = h;	//следующим элементом является h
	h = r;	//теперь r является головой
}

int pop_s(stack*& h) {	//удаление элемента из стека
	int i = h->inf;	//значение первого элемента
	stack* r = h;	//указатель на голову стека
	h = h->next;	//перенос указателя на след.элемент
	delete r;	//удаление первого элемента
	return i;	//возвращение значения
}


//очередь
struct queue	//описание очереди
{
	int inf;
	queue* next;
};

void push_q(queue*& h, queue*& t, int x) {	//добавление элемента в очередь
	queue* r = new queue;	//создание нового элемента
	r->inf = x;	//поле inf = х
	r->next = NULL;	//всегда последний
	if (!h && !t)	//если очередь пуста
		h = t = r;	//это и голова и хвост
	else {
		t->next = r;	//r - следующий для хвоста
		t = r;	//теперь r - хвост
	}
}

int pop_q(queue*& h, queue*& t) {	//удаление элемента из очереди
	queue* r = h;	//указатель на голову очереди
	int i = h->inf;	//сохранение значения головы
	h = h->next;	//сдвиг указателя на след.элемент
	if (!h)	//если удаляем последний элемент из очереди
		t = NULL;
	delete r;	//удаление первого элемента
	return i;	//возвращение значения
}


//в ширину
void bfs(vector<vector<int>>& Gr, vector<int>& used, queue*& h, queue*& t, int x) {

	used[x] = 1;	//помечаем как посещенную
	push_q(h, t, x);	//добавляем в очередь
	cout << x << " ";	//выводим на экран
	while (h) {	//пока очередь не пуста
		int y = pop_q(h, t);	//берем элемент	
		for (int i = 0; i < Gr[y].size(); i++) {
			if (used[Gr[y][i]] == 0) {	//проверяем посещались ли смежные вершины, если нет, то отмечаем как посещенную, добавляем в очередь и выводим на экран
				used[Gr[y][i]] = 1;
				push_q(h, t, Gr[y][i]);
				cout << Gr[y][i] << " ";
			}
		}
	}
}


//в глубину
void dfs(vector<vector<int>>& Gr, vector<int>& used, stack*& h, int x) {

	used[x] = 1;	//помечаем как посещенную
	cout << x << " ";	//выводим на экран
	push_s(h, x);	//добавляем в стек
	while (h) {	//пока стек не пуст
		x = h->inf;	//берем элемент	
		bool fl = false;
		int i;
		for (i = 0; i < Gr[x].size(); i++) {	//проверяем посещались ли смежные вершины, если нет, то отмечаем как посещенную, добавляем в стек и выводим на экран
			if (!used[Gr[x][i]]) {
				fl = true;
				break;
			}
		}
		if (fl) {
			cout << Gr[x][i] << " ";
			used[Gr[x][i]] = 1;
			push_s(h, Gr[x][i]);
		}
		else pop_s(h);	//если вершина посещалась, то просто удаляем ее
	}
}

void adjacency(vector<vector<int>>& Gr, int n) {	//создание списка смежности
	int count, vertex;
	int N = 0;
	for (int i = 0; i < n; i++) {
		cout << endl << "Количество смежных вершин для вершины Gr[" << i << "] : ";
		cin >> count;
		if (count <= n) {	//если количество смежных вершин введено правильно
			for (int j = 0; j < count; j++) {
				cout << j + 1 << "-я " << "смежная вершина: ";
				cin >> vertex;
				if (vertex > n) {
					cout << endl << "Некорректная вершина" << endl << endl;
					j--;
				}
				else {
					Gr[i].push_back(vertex);
				}
			}
		}

		else {
			cout << endl << "Введеное количество вершин больше размера графа" << endl;
			i--;
		}
	}

	cout << endl << "Список смежности: " << endl;
	for (int i = 0; i < n; i++, cout << endl) {
		cout << i << ": ";
		for (int j = 0; j < Gr[i].size(); j++) {
			cout << Gr[i][j] << ", ";
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n, x;
	cout << "Введите количество вершин графа: ";
	cin >> n;
	cout << endl << "Заполните список смежности: " << endl;
	vector<vector<int>> Gr(n);
	vector<int> used_q(n);
	vector<int> used_s(n);

	queue* h_q = NULL;
	queue* t = NULL;
	stack* h_s = NULL;

	adjacency(Gr, n);

	for (int i = 0; i < n; i++) {
		used_q[i] = used_s[i] = 0;
	}

	cout << endl << "Результат обхода в ширину: ";
	for (int i = 0; i < n; i++) {
		if (!used_q[i])
			bfs(Gr, used_q, h_q, t, i);
	}

	cout << endl << "Результат обхода в глубину: ";
	for (int i = 0; i < n; i++) {
		if (!used_s[i])
			dfs(Gr, used_s, h_s, i);
	}

	return 0;
}
