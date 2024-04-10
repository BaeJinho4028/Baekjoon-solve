#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int d[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> v;  
    v.push_back(a[1]);

    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;

        if (v[cnt] < a[i]) {
            v.push_back(a[i]);
            d[i] = ++cnt;
        }
        else {
            int pos = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            v[pos] = a[i];
            d[i] = pos;
        }
    }

    stack<int> ans;
    for (int i = n; i >= 1; i--) {
        if (d[i] == cnt) {
            ans.push(a[i]);
            cnt--;
        }
    }

    cout << ans.size() << '\n';
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }
}