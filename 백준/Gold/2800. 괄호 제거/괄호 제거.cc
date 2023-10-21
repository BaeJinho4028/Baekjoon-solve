#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define X first
#define Y second

string s;
set<string> ans;
stack<int> st;
vector<pair<int, int>> v;

bool vis[205];
bool ch[205];

void dfs(int cur, int idx) {
	if (cur >= 1) {
		string tmp = "";
		for (int i = 0; i < s.size(); i++) {
			if (ch[i]) continue;
			tmp += s[i];
		}
		ans.insert(tmp);
	}

	for (int i = idx; i < v.size(); i++) {
		if (vis[i]) continue;

		vis[i] = true;
		ch[v[i].X] = true;
		ch[v[i].Y] = true;
		dfs(cur + 1, idx + 1);
		vis[i] = false;
		ch[v[i].X] = false;
		ch[v[i].Y] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(i);
		}
		else if (s[i] == ')') {
			v.push_back({ st.top(), i });
			st.pop();
		}
	}
	
	dfs(0, 0);
	for (auto x : ans) {
		cout << x << '\n';
	}
}