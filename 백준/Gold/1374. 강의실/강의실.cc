#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ll long long
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1};

int n;
vector < pair<pair<int, int>, int>> v;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ {b, c}, a });
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	sort(v.begin(), v.end());

	pq.push(v[0].X.Y);
	for (int i = 1; i < n; i++) {
		if (pq.top() <= v[i].X.X)pq.pop();

		pq.push(v[i].X.Y);
	}

	cout << pq.size();
}