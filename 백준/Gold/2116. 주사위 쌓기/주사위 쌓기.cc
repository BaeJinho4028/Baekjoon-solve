#include <bits/stdc++.h>
using namespace std;

int n, ans;
int a[10005][7]; //가려진 주사위 체크
bool chk[10005][7];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 6; j++)
			cin >> a[i][j];

	for (int i = 1; i <= 6; i++) {
		memset(chk, false, sizeof(chk));
		int bot = 0, top = 0, mx = 0;

		for (int j = 1; j <= n; j++) {
			if (j == 1) { //맨 밑 주사위 아래칸
				bot = i;
				chk[j][i] = true;
			}
			else {
				for (int k = 1; k <= 6; k++) {
					int val = top;
					if (val == a[j][k]) {
						bot = k;
						chk[j][k] = true;
						break;
					}
				}
			}


			if (bot == 1) { //위칸이 다음 주사위의 아래칸이고, 위칸을 체크
				top = a[j][6];
				chk[j][6] = true;
			}
			else if (bot == 2) {
				top = a[j][4];
				chk[j][4] = true;
			}
			else if (bot == 3) {
				top = a[j][5];
				chk[j][5] = true;
			}
			else if (bot == 4) {
				top = a[j][2];
				chk[j][2] = true;
			}
			else if (bot == 5) {
				top = a[j][3];
				chk[j][3] = true;
			}
			else if (bot == 6) {
				top = a[j][1];
				chk[j][1] = true;
			}
		}

		for (int j = 1; j <= n; j++) {
			int tmp = 0;
			for (int k = 1; k <= 6; k++) {
				if (!chk[j][k]) tmp = max(tmp, a[j][k]); //제외된 칸 제외하고 가장 큰값(회전)
			}
			mx += tmp;
		}
		ans = max(ans, mx);
	}

	cout << ans;
}