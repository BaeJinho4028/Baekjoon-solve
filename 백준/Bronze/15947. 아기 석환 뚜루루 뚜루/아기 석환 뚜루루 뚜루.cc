#include <bits/stdc++.h>
using namespace std;

string s[14] = { "baby", "sukhwan", "tururu", "turu",
		"very", "cute", "tururu", "turu",
		"in", "bed", "tururu", "turu",
		"baby", "sukhwan" };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string ans = s[(n - 1) % 14];

	if (ans == "turu" || ans == "tururu") {
		for (int i = 0; i < n / 14; i++)
			ans += "ru";
	}

	if (ans.length() >= 12)
		ans = "tu+ru*" + to_string((ans.size() - 2) / 2);

	cout << ans;
}