#include <iostream>
#include <bits/stdc++.n>
 using namespace std;
int f(int n) {
    if (n == 1 || n == 2) return (n-1);
    return f(n-1) + f(n-2);
}
int main() {
    cout << "Hello, World!\n";
    int n;
    cout << "n="; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << f(i) << endl;
    }
    return 0;
}
