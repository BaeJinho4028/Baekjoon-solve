#include <bits/stdc++.h>
using namespace std;

vector<int> a, b; //크레인 상자

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		b.push_back(x);
	}

	sort(a.begin(), a.end(), greater<>());
	sort(b.begin(), b.end(), greater<>());

	if (a[0] < b[0]) {
		cout << -1;
		return 0;
	}

	int cnt = 0;
	while (!b.empty()) {
		cnt++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.size(); j++) {
				if (a[i] >= b[j]) { //크레인이 박스를 옮길 수 잇으면
					b.erase(b.begin() + j);
					break;
				}
			}
		}
	}

	cout << cnt;
}