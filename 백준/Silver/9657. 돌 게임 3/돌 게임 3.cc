#include <bits/stdc++.h>
using namespace std;

bool d[1005];

int main() { //불리한건 CY, CY가 확정인 경우 다음은 무조건 SK거임
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	d[1] = d[3] = d[4] = true;

	for (int i = 5; i <= n; i++) {
		if (!d[i - 1] || !d[i - 3] || !d[i - 4]) d[i] = true; //셋중 하나에 0이 있으면
		else d[i] = false;
	}

	if (d[n]) cout << "SK";
	else cout << "CY";
}