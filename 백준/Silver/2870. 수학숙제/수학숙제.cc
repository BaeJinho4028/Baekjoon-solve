#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> num;
	while (n--) {
		string s, tmp = "";
		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0' && s[i] <= '9')
				tmp += s[i];

			else if (!tmp.empty()) {
				while (tmp.size() > 1 && tmp[0] == '0')
					tmp.erase(0, 1);
				num.push_back(tmp);
				tmp = "";
			}
		}

		if (!tmp.empty()) {
			while (tmp.size() > 1 && tmp[0] == '0')
				tmp.erase(0, 1);
			num.push_back(tmp);
			tmp = "";
		}
	}
	sort(num.begin(), num.end(), cmp);
	for (auto v : num) cout << v << "\n";
}