             a.push_back(x);
        }
        int max = *max_element(a.begin(), a.end()); // поиск максимальных элеме>
        int k = 0;
        for (int i = 0; i < n; i++) {
                if (max == a[i])
                        k = k + 1;
        }
        cout << k;
}

