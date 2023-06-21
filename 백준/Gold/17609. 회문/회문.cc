#include <bits/stdc++.h>
using namespace std;

string s;

int palin(int st, int en, bool flag) { //t: 원본? 하나를 제거했는지안했는지
	while (st < en) {
		if (s[st] != s[en]) {
			if (!flag) { //아직 제거 안했다면
				if (palin(st + 1, en, true) == 0 || palin(st, en - 1, true) == 0)
					return 1; //유사회문
			}
			return 2; // 아님
		}
		st++, en--;
	}
	return 0; //회문
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		cin >> s;

		cout << palin(0, s.size() - 1, false) << '\n';
	}
}