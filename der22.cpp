//  Дано дерево. Определить высоту дерева.
// 10 - 9 4 8 7 6 3 5 2 1 0

#include <iostream>

using namespace std;

struct tree
{
	int inf;
	tree* left;
	tree* right;
	tree* parent;
};

tree* node(int x)
{
	tree* n = new tree;
	n->inf = x;
	n->parent = NULL;
	n->right = NULL;
	n->left = NULL;
	return n;
}

void insert(tree*& tr, int x) //вставка
{
	tree* n = node(x);
	if (!tr) tr = n; //если дерево пустое - корень
	else
	{
		tree* y = tr;
		while (y) //ищем куда вставлять
		{
			if (n->inf > y->inf) //правая ветка
				if (y->right) y = y->right;
				else
				{
					n->parent = y; //узел становится правым ребенком
					y->right = n;
					break;
				}
			else if (n->inf < y->inf)//левая ветка
				if (y->left)
					y = y->left;
				else
				{
					n->parent = y;//узел становится левым ребенком
					y->left = n;
					break;
				}
		}
	}
}

int node_depth(tree* v)
{
	int k = -1;
	while (v != NULL)
	{
		v = v->parent; k++;
	}
	return k;
}

int leaves_to_root(tree* tr) // обратный обход (левый потомок, правый потомок, корень)
{
	static int max = 0;
	if (tr)
	{
		leaves_to_root(tr->left); //левое
		leaves_to_root(tr->right); //правое
		if (!tr->left && !tr->right && node_depth(tr) > max) max = node_depth(tr);
	}
	return max;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, x;
	cout << "n = "; cin >> n;
	tree* tr = NULL;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		insert(tr, x);
	}
	cout << "высота дерева: ";
	cout << leaves_to_root(tr);
	cout << endl;
	return 0;
}
