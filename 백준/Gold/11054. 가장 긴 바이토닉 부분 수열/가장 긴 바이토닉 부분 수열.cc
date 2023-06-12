#include <bits/stdc++.h>
using namespace std;

int a[1005], d[1005][2]; //0증가 1 반대쪽에서부터 증가
int mx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i][0] = d[i][1] = 1;
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i])
				d[i][0] = max(d[i][0], d[j][0] + 1);
		}
	}

	for (int i = n; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			if (a[j] < a[i]) 
				d[i][1] = max(d[i][1], d[j][1] + 1);
		}
	}

	for (int i = 1; i <= n; i++)
		mx = max(mx, d[i][0] + d[i][1]); //증가 + 역방향 증가 (i번째 중복)

	cout << mx - 1; //가운데 중복 제거
}