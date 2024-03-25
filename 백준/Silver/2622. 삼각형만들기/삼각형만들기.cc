#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            int k = n - i - j;
            if (j > k) break;
            if (i + j > k) ans++;
        }
    }
    cout << ans;
}
