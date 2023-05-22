#include <iostream>
#include <stack>
#include <string>
using namespace std;



int PostfixToValue(string postfix) {
	stack<int> s;
	for (int i = 0; i <= postfix.length() - 1; i++) {
		if ((postfix[i] >= '0' && postfix[i] <= '9')) {
			s.push(postfix[i] - '0');
		}
		//if (postfix[i] >= 'a' && postfix[i] <= 'z') {
			//s.push(postfix[i] - 'a');
		//}
		else {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			switch (postfix[i]) {
			case '+':
				s.push(b + a);
				break;
			case '-':
				s.push(b - a);
				break;
			case '*':
				s.push(b * a);
				break;
			case '/':
				s.push(b / a);
				break;
			}
		}
	}
	return s.top();
}


// 34+      7
// 72+4*2+  38

int main() {
	setlocale(LC_ALL, "RUS");
	string postfix = "34+";
	cout << "Математическое выражение в постфиксной форме: " << postfix << endl;
	cout << "Вычисленное значение выражения: " << PostfixToValue(postfix) << endl;
}
