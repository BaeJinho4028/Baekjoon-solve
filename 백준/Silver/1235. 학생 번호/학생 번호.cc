#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string > v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        v.push_back(s);
    }

    int i = 0;
    for (; i < v[0].size(); i++) {
        set<string> se;
        for (auto s : v) {
            se.insert(s.substr(0, i + 1));
        }
        if (se.size() == v.size()) break;
    }
    cout << i+1;
}