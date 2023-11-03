#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int a[51], b[51];

	int i;
	for (i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
	}
	sort(a, a + m);
	sort(b, b + m);

	int cnt;
	int min = 9999, result;
	
	if (n <= 6) {
		if (a[0] >= n * b[0]) min = n * b[0];
		else if (a[0] < n * b[0]) min = a[0];
	}
	else {
		min = a[0] * (n / 6 + 1);     //6세트 초과
		if (a[0] * (n / 6) + (b[0] * (n % 6)) < min) min = a[0] * (n / 6) + (b[0] * (n % 6));
		if (b[0] * n < min) min = b[0] * n;
	}

	cout << min;
}