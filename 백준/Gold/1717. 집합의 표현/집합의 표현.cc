#include <bits/stdc++.h>
using namespace std;

int p[1000005];

int find(int x) {
	if (p[x] == x)return x;
	return p[x] = find(p[x]);
}

void dif(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[y] = x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		p[i] = i;

	while (m--) {
		int c, a, b;
		cin >> c >> a >> b;

		if (c == 0) {
			dif(a, b);
		}
		else {
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}