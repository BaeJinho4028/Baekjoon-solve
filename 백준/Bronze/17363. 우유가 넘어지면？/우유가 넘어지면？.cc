#include <bits/stdc++.h>
using namespace std;

char a[105][105], b[105][105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];

			if (a[i][j] == '-')
				a[i][j] = '|';
			else if (a[i][j] == '|')
				a[i][j] = '-';
			else if (a[i][j] == '/')
				a[i][j] = '\\';
			else if (a[i][j] == '\\')
				a[i][j] = '/';
			else if (a[i][j] == '^')
				a[i][j] = '<';
			else if (a[i][j] == '<')
				a[i][j] = 'v';
			else if (a[i][j] == 'v')
				a[i][j] = '>';
			else if (a[i][j] == '>')
				a[i][j] = '^';
		}
	}

	for (int i = m-1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			cout << a[j][i];
		}
		cout << '\n';
	}
}