#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++) {
        if (i == 0 || i == 2 * n - 2) {
            for (int j = 0; j < n; j++) cout << '*';
            for (int j = 0; j < 2 * n - 3; j++) cout << ' ';
            for (int j = 0; j < n; j++) cout << '*';
        }
        else if (i < n - 1) {
            for (int j = 0; j < i; j++) cout << ' ';
            cout << '*';
            for (int j = 0; j < n - 2; j++) cout << ' ';
            cout << '*';
            for (int j = 0; j < (2 * n) - 3 - (2 * i); j++) cout << ' ';
            cout << '*';
            for (int j = 0; j < n - 2; j++) cout << ' ';
            cout << '*';
        }
        else if (i == n - 1) {
            for (int j = 0; j < i; j++) cout << ' ';
            cout << '*';
            for (int j = 0; j < n - 2; j++) cout << ' ';
            cout << '*';
            for (int j = 0; j < n - 2; j++) cout << ' ';
            cout << '*';
        }
        else {
            for (int j = 0; j < (2 * n - 2 - i); j++) cout << ' ';
            cout << '*';
            for (int j = 0; j < n - 2; j++) cout << ' ';
            cout << '*';
            for (int j = 0; j < (i - (n - 1)) * 2 - 1; j++) cout << ' ';
            cout << '*';
            for (int j = 0; j < n - 2; j++) cout << ' ';
            cout << '*';
        }
        cout << '\n';
    }
}