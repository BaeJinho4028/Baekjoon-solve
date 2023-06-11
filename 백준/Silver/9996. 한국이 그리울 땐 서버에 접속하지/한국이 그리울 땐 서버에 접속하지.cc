#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	string s, t;
	cin >> s;

	int idx = s.find('*');
	string l = s.substr(0, idx);
	string r = s.substr(idx + 1);

	while (n--) {
		cin >> t;
		
		if (l.size() + r.size() > t.size()) cout << "NE\n";
		else if (t.find(l) == 0) {
			string tmp = t.substr(t.size() - r.size());

			if (tmp == r) cout << "DA\n";
			else cout << "NE\n";
		}
		else cout << "NE\n";
	}
}