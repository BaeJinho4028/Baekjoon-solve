#include <bits/stdc++.h>
using namespace std;

int sum;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 0)
		cout << 0;
	else {
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}

		sort(v.begin(), v.end());

		for (int i = round(n * 0.15); i < n - round(n * 0.15); i++)
			sum += v[i];


		cout << round(sum / (n - 2 * round(n * 0.15)));
	}
}