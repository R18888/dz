//Создать двусвязный список, содержащий целые числа. Выполнить сортировку пузырьком, меняя указатели, а не значения.

#include <iostream>
#include <climits>
using namespace std;

struct list {	//описание списка
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x) {	//функция добавления элемента в конец списка
	list* r = new list;	//создание нового элемента
	r->inf = x;
	r->next = NULL;	//всегда последний
	if (!h && !t) {	//если список пуст
		r->prev = NULL;	//первый элемент
		h = t = r;	//это голова
	}
	else {
		t->next = r;	//r - следующий для хвоста
		r->prev = t;	//хвост - предыдущий для r
		t = r;	//r теперь хвост
	}

}

void print(list* h, list* t) {	//вывод элементов списка
	list* p = h;	//указатель на голову 
	while (p) {	//пока не дошли до конца списка
		cout << p->inf << " ";
		p = p->next;	//переход к следующему элементу
	}
}

void BubbleSort(list*& h, list*& t) {	//сортировка пузарьком
	list* left = h;	//первый элемент - голова списка
	list* right = h->next;	//второй элемент - следующий за головой
	list* x = new list;	//пустой список
	while (left->next) {	//обход во всем элементам
		while (right) {
			if ((left->inf) > (right->inf)) {	//если текущий элемент больше следующего, то меняем их местами
				x->inf = left->inf;
				left->inf = right->inf;
				right->inf = x->inf;
			}
			right = right->next;	//меняем указатель на следующий элемент
		}
		left = left->next;	//меняем указатель текущего на след элемент
		right = left->next;	//указатель на следующий меняем на второй после текущего
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	list* h = new list;
	list* t = new list;
	h = NULL;
	t = NULL;

	int n, x;
	cout << "Введите количество элементов: "; cin >> n;
	cout << "Введите элементы: ";

	for (int i = 0; i < n; i++) {
		cin >> x;	//заполняем список
		push(h, t, x);
	}

	BubbleSort(h, t);	//вывод результата
	print(h, t);

	return 0;
}
