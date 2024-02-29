#include <bits/stdc++.h>
using namespace std;

int n, m;
string d[55];
bool vis[55];
int p[55];

bool cmp(string a, string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

string f(int x, bool first) {
	if (d[x] != "" && vis[x]) return d[x];
	vis[x] = true;
	
	for (int i = 0; i < n; i++) {
		if (i == 0 && first) continue;
		if (x - p[i] < 0) continue;

		string tmp = to_string(i) + f(x - p[i], false);

		if (cmp(d[x], tmp)) d[x] = tmp;
	}

	return d[x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//많이 사는것이 중요, 길이 같다면 최대 큰숫자

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		d[p[i]] = to_string(i);
	}
	cin >> m;

	f(m, true);

	cout << (d[m] == "" ? "0" : d[m]);
}