#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void shel_sort(vector<int>& tm, int d) {
    int n = tm.size();
    for (int i = d; i < n; i++) {
        int temp = tm[i];
        int j = i;
        while (j >= d && tm[j - d] > temp) {
            tm[j] = tm[j - d];
            j -= d;
        }
        tm[j] = temp;
    }
}


void o_sort(vector<vector<int>>& tm) {
    int n = tm.size();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            int d = 1;
            while (d < n / 3) {
                d = 3 * d + 1;
            }
            while (d >= 1) {
                shel_sort(tm[i], d);
                d /= 3;
            }
            reverse(tm[i].begin(), tm[i].end());
        }
        else {
            int d = 1;
            while (d < n / 3) {
                d = 3 * d + 1;
            }
            while (d >= 1) {
                shel_sort(tm[i], d);
                d /= 3;
            }
        }
    }
}

int main() {
    ifstream input("input.txt");


    int n;
    input >> n;

    vector<vector<int>> tmp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            input >> tmp[i][j];
        }
    }

    input.close();


    o_sort(tmp);


    ofstream output("output.txt");



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            output << tmp[i][j] << " ";
        }
        output << endl;
    }


    output.close();

    return 0;
