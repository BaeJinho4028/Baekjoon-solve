#include <bits/stdc++.h>
using namespace std;

string d[251];

string solve(string a, string b, string c) {
	int sum = 0;
	string ans = "";
	while (!a.empty() || !b.empty() || !c.empty() || sum) {
		if (a != "") {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b != ""){
			sum += b.back() - '0';
			b.pop_back();
		}
		if (c != "") {
			sum += c.back() - '0';
			c.pop_back();
		}
		ans.push_back(sum % 10 + '0');
		sum /= 10;
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	d[0] = "1";
	d[1] = "1";
	d[2] = "3";
	for (int i = 3; i <= 250; i++) {
		d[i] = solve(d[i - 1], d[i - 2], d[i-2]); // d[i] = d[i-1] + d[i-2] + d[i-2];
	}

	while (cin >> n) {
		cout << d[n] << '\n';
	}
}