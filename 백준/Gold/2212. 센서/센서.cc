#include <bits/stdc++.h>
using namespace std;

int a[10005];

int main() { //수신영역 최소거리가 되어야 전체값도 최솟값됨
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) 
		cin >> a[i];

	sort(a, a + n);


	vector<int> v;
	for (int i = 0; i < n - 1; i++)
		v.push_back(a[i + 1] - a[i]);

	sort(v.begin(), v.end()); // 두 센서 간의 차이가 큰 것 빼면 합이 최소

	int ans = 0;
	for (int i = 0; i < (n-1) - (k - 1); i++) //차이가 큰 것 K-1개 빼고 더함
		ans += v[i];

	cout << ans;
}