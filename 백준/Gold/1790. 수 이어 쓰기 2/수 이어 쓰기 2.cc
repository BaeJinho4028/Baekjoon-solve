#include <bits/stdc++.h>
using namespace std;

int n, k;

/*
바킹독님 해설 참고
숫자들 길이가 같은 것으로 묶으면 9(1~9), 180(10~99), 2700(100~999)
k에서 9 * i * 10^(i - 1)을 순차적으로 빼주고 ( 9LL * len * exp )
k번째 숫자를 포함하는 수 target을 찾는다.
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int len = 1, exp = 1;
	while (k > 9LL * len * exp) {
		k -= 9LL * len * exp;
		exp *= 10;
		len++;
	}

	int t = exp + ((k - 1) / len); //0부터 세므로 k-1

	if (t > n) cout << -1;
	else cout << to_string(t)[(k - 1) % len];
	//14     t = 10 + 13/2 = 16     ans = 16[13%2] = 6
}