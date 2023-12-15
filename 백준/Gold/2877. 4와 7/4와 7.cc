#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v, tmp;

	n++;
	while (n >= 1) {
		tmp.push_back(n % 2);
		n /= 2;
	}

	for (int i = tmp.size() - 1; i >= 0; i--) {
		v.push_back(tmp[i]);
	}

	for (int i = 1; i < v.size(); i++) {
		if (v[i] == 0)
			printf("4");
		else
			printf("7");
	}
}