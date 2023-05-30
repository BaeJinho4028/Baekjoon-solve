#include <bits/stdc++.h>
using namespace std;

int t[10005];
int i;

void postorder(int st, int en) {
	if (st >= en) return;

	for (i = st + 1; i < en; i++)
		if (t[st] < t[i]) break;

	postorder(st + 1, i);
	postorder(i, en);
	cout << t[st] << '\n';

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, idx = 0;
	while (cin >> n)
		t[idx++] = n;

	postorder(0, idx);
}
