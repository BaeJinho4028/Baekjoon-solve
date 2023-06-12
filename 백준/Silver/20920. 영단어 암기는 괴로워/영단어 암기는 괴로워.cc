#include <bits/stdc++.h>
using namespace std;

map<string, int> ma;

bool cmp(string a, string b) {
	if (ma[a] == ma[b]) {
		if (a.size() == b.size()) {
			return a < b;
		}

		return a.size() > b.size();
	}

	return ma[a] > ma[b];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	vector<string> v;
	while (n--) {
		string s;
		cin >> s;

		if (s.size() < m) continue;

		ma[s]++;
		if(ma[s] == 1)v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);

	for (auto x : v)
		cout << x << '\n';
}