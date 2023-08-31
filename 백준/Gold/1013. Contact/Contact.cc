#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define ll long long
int dx[8] = { 1,0,-1,0, 1, 1, -1, -1 };
int dy[8] = { 0,1,0,-1, 1, -1, 1, -1 };
int n, m;
int mx, mn = '????';
int ans, cnt;


//1000 11 01 111
void solve() {
	string s;
	cin >> s;

	int idx = 0;
	bool flag = true;

	while (idx < s.size() && flag) {
		switch (s[idx]) {
		case '0': //다음이 1인지 체크
			idx++;
			if (s.size() <= idx || s[idx] == '0')
				flag = false;
			idx++;
			break;

		case '1':
			idx++;
			int nxt1 = s.find('1', idx); //다음 1이 무조건 두칸보다 뒤에 나와야함
			if (nxt1 == string::npos || nxt1 - idx < 2) {
				flag = false;
				break;
			}

			int nxt0 = s.find('0', nxt1);
			if (nxt0 == s.size() - 1) { 
				flag = false;
				break;
			}
			if (nxt0 == string::npos) {
				idx = s.size();
				break;
			}
			idx = nxt0;

			if ('0' == s[nxt0 + 1] && nxt0 - nxt1 > 1)
				idx--;
			break;
		}
	}

	cout << (idx == s.size() && flag ? "YES" : "NO") << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}