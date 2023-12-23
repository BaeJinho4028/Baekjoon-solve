#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
vector<int> dish;
int chk[3005];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;
	
	chk[c] = 1;

	int cnt = 1;

	int l = 0, r = k - 1;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		dish.push_back(x);
		if (i < k) {
			chk[x]++;
			if(chk[x]==1) cnt++;
		}
	}
	for (int i = 0; i < k; i++)
		dish.push_back(dish[i]);

	while (1) {
		ans = max(ans, cnt);
		if (l == n) break;
		chk[dish[l]]--;
		if (chk[dish[l++]] == 0) cnt--;
		chk[dish[++r]]++;
		if (chk[dish[r]] == 1)cnt++;
	}

	cout << ans;

}