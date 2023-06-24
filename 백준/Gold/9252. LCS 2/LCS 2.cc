#include <bits/stdc++.h>
using namespace std;

string a, b;
int d[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}

	cout << d[a.size()][b.size()] << '\n';

	//역추적 ( 공부필요) 참고 : https://hyeo-noo.tistory.com/18 
	string ans = "";

	int idx = b.size();
	for (int row = a.size(); row >= 1; row--) {
		for (int col = idx; col >= 1; col--) {
			if (d[row][col] == d[row - 1][col]) {
				// 바로 위 dp값이 같으면 현재 열 값을 유지한다
				idx = col;
				break;
			}
			else if (d[row][col] == d[row][col - 1]) continue;
			else 
				ans += a[row - 1];
		}
	}

	reverse(ans.begin(), ans.end()); //이것이 아니라 ans = a[row-1] + ans; 하는법도잇음
	cout << ans;
}