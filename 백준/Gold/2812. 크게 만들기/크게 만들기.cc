#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	cin >> s;

	deque<int> dq;
	for (int i = 0; i < s.size(); i++) {
		while (!dq.empty() && k && dq.back() < s[i] - '0') {
			dq.pop_back();
			k--;
		}
		dq.push_back(s[i] - '0');
	}

	for (int i =0; i < dq.size() - k; i++)
		cout << dq[i];
}