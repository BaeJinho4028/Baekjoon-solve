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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	int a, b;
	stack<int> st;
	while (n--) {
		cin >> a;

		switch (a) {
		case 1:
			cin >> b;
			st.push(b);
			break;
			
		case 2:
			if (st.empty()) cout << "-1\n";
			else {
				cout << st.top() << '\n';
				st.pop();
			}
			break;
		case 3:
			cout << st.size() << '\n';
			break;
		case 4:
			cout << st.empty() << '\n';
			break;
		case 5:
			if (st.empty()) cout << "-1\n";
			else {
				cout << st.top() << '\n';
			}
			break;
		}
	}
}