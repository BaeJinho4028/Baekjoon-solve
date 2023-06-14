#include <bits/stdc++.h>
using namespace std;

map<string, double> ma;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	int cnt = 0;
	while (getline(cin, s)) {
		ma[s]++;
		cnt++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto x : ma) {
		cout << x.first << ' ' << x.second / cnt * 100 << '\n';
	}
}