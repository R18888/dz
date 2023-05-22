// Дано дерево. Вывести все листья.

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct tree { //дерево
	int inf;
	tree* right;
	tree* left;
};

tree* node(int x) { //начальный узел
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	return n;
}

void create(tree*& tr, int n) { //создание идеально сбалансированного дерева
	int x;
	if (n > 0) {
		cin >> x;
		tr = node(x);
		int nl = n / 2;
		int nr = n - nl - 1;
		create(tr->left, nl);
		create(tr->right, nr);
	}
}

void preorder(tree* tr) { //прямой обход
	if (tr) {
		cout << tr->inf << ' ';
		preorder(tr->left);
		preorder(tr->right);
	}
}

void print1(tree*& tr) { //функция для вывода листьев
	if (!tr)
		return;
	if (!tr->left && !tr->right) { //если у узла нет детей
		cout << tr->inf << ' '; //выводим значение узла
		return;
	}
	if (tr->left) //если слева есть ребенок
		print1(tr->left); //рекурсивно вызываем функцию
	if (tr->right) //если справа есть ребенок
		print1(tr->right); //рекурсивно вызываем функцию
}

int main() {
	tree* tr = NULL;
	int n, x;
	cout << "n = ";
	cin >> n;
	create(tr, n); //создание дерева
	print1(tr); //вывод листьев дерева
	return 0;
}
