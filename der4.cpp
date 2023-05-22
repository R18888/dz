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

void find(tree* tr, int x, bool fl, int c) { //поиск глубины узла Х
	tree* res = NULL;
	if (tr) {
		if (tr->inf == x) { //если нашли узел Х
			res = 0; //присваиваем значение res
			fl = false;
		}
		else { //если еще не нашли узел Х
			c++;
			find(tr->left, x, fl, c); //идем по левому поддереву
			find(tr->right, x, fl, c); //идем по правому поддереву
			fl = true;
		}
	}
	if (!fl)
		cout << c << ' '; //выводим глубину узла Х
}

int main() {
	tree* tr = NULL;
	int n, y, c = 0;
	bool fl = true;
	cout << "n = ";
	cin >> n;
	cout << "X = ";
	cin >> y;
	create(tr, n); //создание дерева
	find(tr, y, fl, c); //вызов функции нахождения высоты узла Х
	return 0;
}
