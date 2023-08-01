#include <bits/stdc++.h>
using namespace std;

int n, ans;
int chk[1005];
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		v.push_back({ d, w });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) { //점수가 큰 순서
		for (int j = v[i].first; j > 0; j--) { //큰 점수 과제를 최대한 뒤에 배치
			if (chk[j] == 0) {
				chk[j] = v[i].second;
				break;
			}
		}
	}

	for (int i = 1; i <= 1000; i++)
		ans += chk[i];

	cout << ans;
}