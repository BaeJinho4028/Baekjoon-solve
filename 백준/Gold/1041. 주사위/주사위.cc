#include <bits/stdc++.h>
using namespace std;

int a[6];
long long b[6];
long long n, ans;

//나올수 있는 가장 작은 숫자면을 나오게 한다면?
int main() { //3면 : 4개 / 2면 : (n-2)*4 + (n-1)*4  / 1면 (n-2)^2 + (n-2)*(n-1)*4
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		int sum = 0, mx = 0;
		for (int i = 0; i < 6; i++) {
			sum += a[i];
			mx = max(mx, a[i]);
		}

		cout << sum - mx;
		return 0;
	}

	b[0] = min(a[0], a[5]);
	b[1] = min(a[1], a[4]);
	b[2] = min(a[2], a[3]);
	
	sort(b, b + 3);

	b[1] += b[0]; //2면 += 1면
	b[2] += b[1]; // 3면 += 2면(+1면)

	ans += b[2] * 4;
	ans += b[1] * (4 * (2*n - 3));
	ans += b[0] * ((n - 2) * (n - 2) + 4 * (n - 1) * (n - 2));

	cout << ans;
}