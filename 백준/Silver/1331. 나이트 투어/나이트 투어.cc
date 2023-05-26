#include <bits/stdc++.h>
using namespace std;

bool vis[10][10];


int main() { //왼쪽을 정렬한후   전체 전선 - 오른쪽가장긴증가하는부분수열 
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool flag = false;

	char a, ta, sta;
	int b, tb, stb;
	for (int i = 0; i < 36; i++) {
		cin >> a >> b;

		if (vis[a - 'A' + 1][b]) flag = true;
		vis[a - 'A' + 1][b] = 1;

		if (i == 0) {
			sta = a;
			stb = b;
		}

		if (i > 0) {
			if ((int)(a - ta) == 2) {
				if (!(b - tb == 1 || b - tb == -1)) flag = true;
			}
			else if ((int)(a - ta) == -2) {
				if (!(b - tb == 1 || b - tb == -1)) flag = true;
			}
			else if ((int)(a - ta)== 1) {
				if (!(b - tb == 2 || b - tb == -2)) flag = true;
			}
			else if ((int)(a - ta) == -1) {
				if (!(b - tb == 2 || b - tb == -2)) flag = true;
			}
			else flag = true;
		}

		if (i == 35) {
			if ((int)(a - sta) == 2) {
				if (!(b - stb == 1 || b - stb == -1)) flag = true;
			}
			else if ((int)(a - sta) == -2) {
				if (!(b - stb == 1 || b - stb == -1)) flag = true;
			}
			else if ((int)(a - sta) == 1) {
				if (!(b - stb == 2 || b - stb == -2)) flag = true;
			}
			else if ((int)(a - sta) == -1) {
				if (!(b - stb == 2 || b - stb == -2)) flag = true;
			}
			else flag = true;
		}

		ta = a;
		tb = b;
	}

	if (flag) cout << "Invalid";
	else cout << "Valid";
}