#include <bits/stdc++.h>
using namespace std;

int board[105][105], tmp[105][105];
int n, m, r;

void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = tmp[i][j];
		}
	}
}

void one() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[n - i - 1][j] = board[i][j];
		}
	}
}

void two() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][m-j-1] = board[i][j];
		}
	}
}

void three() {
	int k = n;
	swap(n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = board[k - 1 - j][i];
		}
	}
}

void four() {
	int k = m;
	swap(n, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = board[j][k - i -1];
		}
	}
}

void five() {
	int hn = n / 2, hm = m / 2;

	for (int i = 0; i < hn; i++) { //1to2
		for (int j = 0; j < hm; j++) {
			tmp[i][j + hm] = board[i][j];
		}
	}
	for (int i = 0; i < hn; i++) { //2to3
		for (int j = hm; j < m; j++) {
			tmp[i+hn][j] = board[i][j];
		}
	}
	for (int i = hn; i < n; i++) { //3to4
		for (int j = hm; j < m; j++) {
			tmp[i][j -hm] = board[i][j];
		}
	}
	for (int i = hn; i < n; i++) { //4to1
		for (int j = 0; j < hm; j++) {
			tmp[i-hn][j] = board[i][j];
		}
	}
}

void six() {
	int hn = n / 2, hm = m / 2;

	for (int i = 0; i < hn; i++) { //1to4
		for (int j = 0; j < hm; j++) {
			tmp[i+hn][j] = board[i][j];
		}
	}
	for (int i = hn; i < n; i++) { //4to3
		for (int j = 0; j < hm; j++) {
			tmp[i][j + hm] = board[i][j];
		}
	}
	for (int i = hn; i < n; i++) { //3to2
		for (int j = hm; j < m; j++) {
			tmp[i - hn][j] = board[i][j];
		}
	}
	for (int i = 0; i < hn; i++) { //2to1
		for (int j = hm; j < m; j++) {
			tmp[i][j - hm] = board[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	while (r--) {
		int x;
		cin >> x;

		if (x == 1) one();
		if (x == 2) two();
		if (x == 3) three();
		if (x == 4) four();
		if (x == 5) five();
		if (x == 6) six();
		copy();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}