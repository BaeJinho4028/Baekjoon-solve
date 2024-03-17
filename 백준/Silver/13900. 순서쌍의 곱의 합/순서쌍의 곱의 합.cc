#include <bits/stdc++.h>
using namespace std;

long long a[100005], p[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = a[i] + p[i - 1];
    }

    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += a[i] * (p[n] - p[i]);
    }

    cout << ans;
}