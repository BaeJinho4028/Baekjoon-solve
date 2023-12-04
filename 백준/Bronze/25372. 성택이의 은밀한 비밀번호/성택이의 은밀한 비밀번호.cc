#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

int d[55];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		int a = s.size();

		if (6 <= a && a <= 9) cout << "yes\n";
		else cout << "no\n";
	}
}