#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second

int a[200];//사면체 만들때 필요한 대포알 수
int d[300005];

int f(int x) {
	if (x == 0) return 0;

	int& ret = d[x];
	if (~ret) return ret;

	ret = '????';
	
	for (int i = 1; i < 200; i++) {
		if (a[i] > x) break;

		ret = min(ret, 1 + f(x - a[i]));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < 200; i++) {
		int tmp = i * (i + 1) / 2;
		a[i] = a[i - 1] + tmp;
	}

	int n;
	cin >> n;

	memset(d, -1, sizeof(d));
	cout << f(n);
}