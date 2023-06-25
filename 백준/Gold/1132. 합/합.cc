#include <bits/stdc++.h>
using namespace std;

long long n, ans;
long long az[10];
bool chk[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		long long pow = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			az[s[i] - 'A'] += pow;
			pow *= 10;
		}
		chk[s[0] - 'A'] = true; //앞에 0인지
	}

	int tmp =0;
	for (int i = 0; i < 10; i++) {
		if (!chk[i]) {
			tmp = i;
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (!chk[i] && az[i] < az[tmp]) {
			tmp = i;
		}
	}
	az[tmp] = 0; // 맨 앞에 0이 오지 않으면서 가장 적게 등장하는 알파벳에 0을 넣어줌

	sort(az, az + 10, greater<>());

	int num = 9;
	for (int i = 0; i < 26; i++) {
		if (az[i] == 0) break;
		ans += az[i] * num--;
	}

	cout << ans;
}