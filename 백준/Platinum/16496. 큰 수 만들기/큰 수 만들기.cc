#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

vector<string> v;

bool cmp(string a, string b) {
	return a + b > b + a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		v.push_back(s);
	}
	sort(v.begin(), v.end(), cmp);
	
	if (v[0] == "0") {
		cout << "0";
		return 0;
	}

	string ans = "";
	for (int i = 0; i < n; i++) {
		ans += v[i];
	}

	cout << ans;
}