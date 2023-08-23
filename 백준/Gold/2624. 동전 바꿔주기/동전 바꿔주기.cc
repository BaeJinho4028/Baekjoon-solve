#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003

int d[10005];
int c[105], b[105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n;
	cin >> t >> n;

	for (int i = 0; i < n; i++)
		cin >> c[i] >> b[i];

	d[0] = 1;
	for (int i = 0; i < n; i++) {//동전종류
		for (int j = t; j >= 0; j--) {//비용 반대로 : 1부터 할 경우 dp[1~j-1] 이 dp[j] 에 포함될 수 있기 때문
			int sum = 0;
			for (int k = 0; k < b[i]; k++) { //동전개수
				sum += c[i];
				if (j - sum >= 0 && d[j - sum] > 0) d[j] += d[j - sum];
			}
		}
	}

	cout << d[t];
}