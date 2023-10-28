#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w, h, l;
	cin >> n >> w >> h >> l;

	int mn = min(n, (w/l) * (h/l));
	cout << mn;
}