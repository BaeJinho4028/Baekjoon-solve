#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int n;
int b[55];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> b[i];

	int cnt = 0;
	while (1) {
		int z = 0;

		for (int i = 0; i < n; i++) {
			if (b[i] % 2) {
				cnt++;
				b[i]--;
			}
			if (b[i] == 0)
				z++;
		}


		if (z == n) break;

		for (int i = 0; i < n; i++)
			b[i] /= 2;
		cnt++;
	}

	cout << cnt;
}
