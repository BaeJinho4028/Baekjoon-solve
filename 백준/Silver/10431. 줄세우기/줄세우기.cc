#include <bits/stdc++.h>
using namespace std;

int s[20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p;
    cin >> p;
    for (int tc = 0; tc < p; tc++) {
        int t;
        cin >> t;

        int ans = 0;
        for (int i = 0; i < 20; i++) cin >> s[i];
        for (int i = 0; i < 20; i++) {
            for (int j = i; j < 20; j++) {
                if (s[i] > s[j]) ans++;
            }
        }
        cout << t << ' ' << ans << '\n';
    }
}