#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int sum = 1;
	for (int i = 0; i < n; i++) {
		if (v[i] > sum)
			break;
		sum += v[i];
	}
	
	cout << sum;
}
