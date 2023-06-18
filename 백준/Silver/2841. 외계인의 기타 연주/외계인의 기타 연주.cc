#include <bits/stdc++.h>
using namespace std;

stack<int> st[7];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, p;
	cin >> n >> p;

	int a, b, cnt = 0;
	while(n--) {
		cin >> a >> b;
		
		while (!st[a].empty()) {
			if (st[a].top() > b) { //누르려는게 더 낮을때
				st[a].pop();
				cnt++;
			}
			else break;
		}

		if (!st[a].empty() && st[a].top() == b) continue; //누르고있으면 패스

		st[a].push(b);
		cnt++;
	}

	cout << cnt;
}