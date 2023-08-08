#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	set<string> se;
	se.insert("ChongChong");

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;

		if (se.find(a) != se.end() || se.find(b) != se.end()) {
			se.insert(a);
			se.insert(b);
		}
	}

	cout << se.size();
}