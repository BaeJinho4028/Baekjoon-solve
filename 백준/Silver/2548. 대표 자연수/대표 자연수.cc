#include <bits/stdc++.h>
using namespace std;

int a[20005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int chk = n / 2;

    if (n % 2 == 0 && chk) chk--;
    cout << a[chk];
}