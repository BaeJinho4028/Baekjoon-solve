#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int ans[4];
int arr[6][3];
int res[6][3];
int cnt;
vector<pair<int,int>> v;

void dfs(int cur) {
	if (cur == v.size()) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (arr[i][j] != res[i][j]) return;
			}
		}

		ans[cnt] = 1;
		return;
	}

	int a = v[cur].X, b = v[cur].Y;
	
	//승패
	res[a][0]++;
	res[b][2]++;
	dfs(cur + 1);
	res[a][0]--;
	res[b][2]--;
	
	//무무
	res[a][1]++;
	res[b][1]++;
	dfs(cur + 1);
	res[a][1]--;
	res[b][1]--;

	//패승
	res[a][2]++;
	res[b][0]++;
	dfs(cur + 1);
	res[a][2]--;
	res[b][0]--;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 6; i++) {
		for (int j = i + 1; j < 6; j++) {
			v.push_back({ i, j });
		}
	}


	for (int t = 0; t < 4; t++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
			}
		}

		dfs(0);
		cnt++;
	}

	for (int i = 0; i < 4; i++) 
		cout << ans[i] << ' ';
}