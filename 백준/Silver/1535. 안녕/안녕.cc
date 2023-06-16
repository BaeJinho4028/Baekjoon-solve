#include <bits/stdc++.h>
using namespace std;

int d[105];
int a[25], b[25]; //체력 점수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 100; j > a[i]; j--) {
			d[j] = max(d[j], d[j - a[i]] + b[i]);
		}
	}

	cout << d[100];
}