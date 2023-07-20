#include <bits/stdc++.h>
using namespace std;

int p[105];
double x[105], y[105];
vector<pair<double,pair<int, int>>> xy;
double ans;

int find(int x) {
	if (!p[x]) return x;
	return p[x] = find(p[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) p[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double d = sqrt(((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j])));
			xy.push_back({ d, {i, j} });
		}
	}

	sort(xy.begin(), xy.end());

	for (auto z : xy) {
		int a = z.second.first;
		int b = z.second.second;
		double c = z.first;

		if (find(a) == find(b)) continue;
		ans += c;
		merge(a, b);
	}

	cout << fixed << setprecision(2) << ans;
}