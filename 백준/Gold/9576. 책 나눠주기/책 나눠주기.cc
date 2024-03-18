#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> v(m);
        for (int i = 0; i < m; i++) {
            cin >> v[i].second >> v[i].first;
        }

        sort(v.begin(), v.end());

        vector<bool> chk(n + 1);
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = v[i].second; j <= v[i].first; j++) {
                if (chk[j]) continue;
                chk[j] = true;
                cnt++;
                break;
            }
        }

        cout << cnt << '\n';
    }
}
