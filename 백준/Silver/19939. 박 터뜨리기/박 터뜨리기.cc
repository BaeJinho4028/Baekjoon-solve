#include <bits/stdc++.h>
using namespace std;

int d[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int sum = 0;
	for (int i = 1; i <= k; i++)
		sum += i;

	n -= sum;

	if (n < 0)
		cout << -1;
	else {
		if (n % k == 0) //등차수열은 각각 1씩 더해져도 k의 배수임
			cout << k - 1;
		else //각각 다르게 더해져도 결국 kㅇ
			cout << k;
	}
}