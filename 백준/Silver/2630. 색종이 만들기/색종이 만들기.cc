#include <bits/stdc++.h>
using namespace std;
int n;
int paper[130][130];
int cnt[2]; // 0 은 하양 1은 파랑

bool c(int a, int b, int n) {
	for (int i = a; i < a + n; i++) {
		for (int j = b; j < b + n; j++) {
			if (paper[a][b] != paper[i][j])
				return false;
		}
	}
	return true;
}

void fuc(int a, int b, int n) {
	if (c(a, b, n)) {
		cnt[paper[a][b]]++;
		return;
	}
	int half = n / 2;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			fuc(a + i * half, b + j * half, half);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	fuc(0, 0, n);

	cout << cnt[0] << '\n' << cnt[1];
}