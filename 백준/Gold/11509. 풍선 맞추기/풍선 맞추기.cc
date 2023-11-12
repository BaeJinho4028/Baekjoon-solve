#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int a[1000005];
bool vis[1000005];
int mx;
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (a[x + 1] > 0) a[x + 1]--;
		else ans++;

		a[x]++;
	}
	cout << ans;
}
