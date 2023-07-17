#include <bits/stdc++.h>
using namespace std;

int n;
bool s[105];

void turn(int b) {
	if (s[b] == 0) s[b] = 1;
	else s[b] = 0;
}

void nam(int b) {
	for (int i = b; i <= n; i += b) {
		turn(i);
	}
;
}

void yeo(int b) {
	int i = 1;
	turn(b);
	while (b-i >=1 && b+i <=n && s[b - i] == s[b + i]) {


		turn(b - i);
		turn(b + i);

		i++;

	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> s[i];

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			nam(b);
		}
		else {
			yeo(b);
		}
		cin.ignore();
	}

	for (int i = 1; i <= n; i++) {
		cout << s[i] << ' ';
		if (i % 20 == 0) cout << '\n';
	}
}
