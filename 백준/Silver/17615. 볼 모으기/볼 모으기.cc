#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int mn = '????';

	bool flag = false;
	int cnt = 0;
	for (int i = 0; i < n; i++) { //빨강을 왼쪽으로
		if (s[i] == 'B') flag = true;
		if (flag && s[i] == 'R') cnt++;
	}

	mn = min(mn, cnt);
	flag = false;
	cnt = 0;
	for (int i = 0; i < n; i++) { //파랑을 왼쪽으로
		if (s[i] == 'R') flag = true;
		if (flag && s[i] == 'B') cnt++;
	}

	mn = min(mn, cnt);
	flag = false;
	cnt = 0;
	for (int i = n-1; i >= 0; i--) { //빨강을 오른쪽으로
		if (s[i] == 'B') flag = true;
		if (flag && s[i] == 'R') cnt++;
	}

	mn = min(mn, cnt);
	flag = false;
	cnt = 0;
	for (int i = n - 1; i >= 0; i--) { //파랑을 오른쪽으로
		if (s[i] == 'R') flag = true;
		if (flag && s[i] == 'B') cnt++;
	}

	mn = min(mn, cnt);

	cout << mn;
}