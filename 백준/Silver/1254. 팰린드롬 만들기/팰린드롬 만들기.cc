#include <bits/stdc++.h>
using namespace std;

bool palin(string s)
{
	for (int i = 0; i < s.size()/2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}

	return true;
}

int main() { //앞부분을 잘라내며 팰린드롬이면 잘라낸만큼 더하면 팰린드롬됨
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;

	int flag;
	for (int i = 0; i < s.size(); i++) {
		string tmp = s.substr(i); //앞부분 자르기
		if (palin(tmp)) {
			cout << s.size() + i;
			break;
		}
	}
}