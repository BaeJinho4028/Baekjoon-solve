#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int az[26];
int cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	string s;
	cin >> s;

	int a, c, g, t;
	cin >> a >> c >> g >> t;

	int st = 0, en = 0;
	az[s[0] - 'A']++;

	while (st <= en) {
		if (en >= s.size()) break;
		if (en - st + 1 < m) {
			en++;
			az[s[en] - 'A']++;
		}
		else if (en - st + 1 > m) {
			az[s[st] - 'A']--;
			st++;
		}
		else {
			if (az['A' - 'A'] >= a && az['C' - 'A'] >= c && az['G' - 'A'] >= g && az['T' - 'A'] >= t) {
				cnt++;
				//cout << s[st] << s[en] << '\n';
			}
			az[s[st] - 'A']--;
			st++, en++;
			az[s[en] - 'A']++;
		}
	}

	cout << cnt;
}