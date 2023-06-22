#include <bits/stdc++.h>
using namespace std;
/* 
0인 조건 -> 점화식

w 한조각 h 반조각
w == 0 : 반쪽만 남았으므로 어차피 H만 나옴 d[0][h] = 1;

h == 0 : w한개를 먹으면 w-1 개  h는 1개  d[w][0] = d[w-1][1]


w=w h=h개  w먹을시 반쪽 먹고 반쪽이 생김 d[w-1][h+1] 
			h먹을 시  w개 h-1개          d[w][h-1]

	즉, d[w][h] = d[w-1][h+1] + d[w][h-1]
*/

long long d[35][35]; //W H  개수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i <= 30; i++)
		d[0][i] = 1;

	for (int w = 1; w <= 30; w++) {
		for (int h = 0; h <= 30; h++) {
			if (h == 0)
				d[w][0] = d[w - 1][1];
			else
				d[w][h] = d[w - 1][h + 1] + d[w][h - 1];
		}
	}

	int n;
	while (cin >> n) {
		if (n == 0) break;

		cout << d[n][0] << '\n';
	}
}