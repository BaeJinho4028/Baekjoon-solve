#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> v[2005], x;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c, m;
	cin >> n >> c >> m;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	//x에 있는 i역 짐을 내린다 ->  x에 다 싣는다 -> 정렬 -> 되는것만 tmp에 넣고 가져간다. -> x=tmp -> 
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int idx = 0;
		for (auto box : x) {
 			if (box.X == i) {
				//cout << "버" << box.X << ' ' << box.Y << '\n';
				ans += box.Y;
				idx++;
			}
		}
		x.erase(x.begin(), x.begin() + idx);

		for (auto cur : v[i]) {
			//cout << i << ' ' << cur.X << ' ' << cur.Y << '\n';
			x.push_back(cur);
		}
		sort(x.begin(), x.end());

		vector<pair<int, int>> tmp;
		int cnt = c;
		for (auto box : x) {
			if (cnt - box.Y <= 0) box.Y = cnt;
			tmp.push_back({box.X, box.Y});
			cnt = cnt - box.Y;
			//cout << "담음 : " << i << ' ' << box.X << ' ' << box.Y << ' ' << cnt << '\n';
			if (cnt == 0) break;
		}

		x = tmp;
		for (auto box : x) {
			//cout << "x : " << ' ' << box.X << ' ' << box.Y << '\n';
		}
	}

	cout << ans;
}