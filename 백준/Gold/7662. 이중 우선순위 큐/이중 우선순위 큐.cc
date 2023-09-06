#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		multiset<int> m;
		for (int i = 0; i < n; i++) {
			char a;
			cin >> a;
			int b;
			cin >> b;
			if (a == 'D') {
				if (m.empty())continue;
				if (b == 1) m.erase(prev(m.end()));
				else m.erase(m.begin());
			}
			else {
				m.insert(b);
			}
		}
		if (m.empty()) cout << "EMPTY\n";
		else cout << *prev(m.end()) << ' ' << *m.begin() << '\n';
	}
}