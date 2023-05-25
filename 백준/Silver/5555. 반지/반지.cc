#include <bits/stdc++.h>
using namespace std;

int p[1005][7];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int n;
	cin >> n;

	int cnt = 0;
	while (n--) {
		string tmp;
		cin >> tmp;

		tmp = tmp + tmp;

		for (int i = 0; i < tmp.size(); i++) {
			bool flag = false;
			for (int j = 0; j < s.size(); j++) {
				if (tmp[i + j] != s[j]) {
					flag = true;
					break;
				}
			}
			if (!flag) {
				cnt++;
				break;
			}
		}
	}

	cout << cnt;
}