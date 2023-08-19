#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define MOD 1000000007
map<ll, ll> ma;

/*
F[n]= F[n-1] + F[n-2]
	= F[n-1] + F[n-2] + F[n-2] + F[n-3] = 3F[n-2] + 2F[n-3]
	= 8F[n-4] + 5F[n-5]

즉, F[n] = F[k+1]F[n-k] + F[k]F[n-k-1]

-> F[n] = F[n/2+1]F[n/2] + F[n/2]F[n/2-1]

짝수와 홀수 구분 (2k 와 2k + 1 대입 후 다시 n으로 변환)

짝수 : F[n/2] * ( F((n/2) + 1) + F((n/2) -1 ) )
홀수 : F[(n+1)/2] ^ 2  + F[(n-1)/2] ^ 2

*/

ll fibo(ll x) {
	if (ma[x]) return ma[x];

	ll ans;
	if (x % 2 == 0) ans = (fibo(x / 2) * (fibo(x / 2 + 1) + fibo(x / 2 - 1))) % MOD;
	else ans = ((fibo((x + 1) / 2) * fibo((x + 1) / 2)) % MOD) + ((fibo((x - 1) / 2) * fibo((x - 1) / 2)) % MOD) % MOD;

	return ma[x] = ans % MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;

	ma[0] = 0, ma[1] = 1, ma[2] = 1;
	cout << fibo(n);
}