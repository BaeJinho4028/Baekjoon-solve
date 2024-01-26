#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, k;
	cin >> n >> k;

	ll st= 0, en = n/2;
	/*
	가위로 가로를 색종이를 자르는 횟수를 x번, 그러면 세로는 n-x번
	개수는 (x+1)*(n-x +1)개가 됨 
	음수 2차함수이므로 n/2일때 최대값 가짐(가로 세로 상관없음)
	0 <= x <= n/2
	*/

	while (st <= en) {
		ll mid = (st + en) / 2;
		
		ll tmp = (mid + 1) * (n - mid + 1);

		if (tmp == k) {
			cout << "YES";
			return 0;
		}
		if (tmp > k) en = mid - 1;
		else st = mid + 1;
	}
	cout << "NO";
}