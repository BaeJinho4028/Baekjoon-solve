#include <bits/stdc++.h>
using namespace std;

int v[55];
bool prime[1500000];

void isprime() {
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i * i < 1500000; i++) {
		if (prime[i] == false) continue;
		for (int j = i + i; j < 1500000; j += i)
			prime[j] = false;
	}
}

bool solve(int x) {
	string s = to_string(x);
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	isprime();

	for (int i = n; i <= 1500000; i++) {
		if (!prime[i]) continue;
		if (solve(i)) {
			cout << i;
			return 0;
		}
	}
}