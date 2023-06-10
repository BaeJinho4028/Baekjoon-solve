#include <bits/stdc++.h>
using namespace std;

set<string> se;
bool e;
int ans;

int main() { //수신영역 최소거리가 되어야 전체값도 최솟값됨
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		if (e && s != "ENTER") se.insert(s);

		if (s == "ENTER") {
			e = true;
			ans += se.size();
			se.clear();
		}
	}
	ans += se.size();
	cout << ans;
}