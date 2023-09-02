#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define ll long long
int dx[8] = { 1,0,-1,0, 1, 1, -1, -1 };
int dy[8] = { 0,1,0,-1, 1, -1, 1, -1 };

int n;
string s;

bool chk() {
	int i = 0;
	while(s[i]) {
		if (s[i++] == '1') { //1시작
			int cnt = 0;
			while (s[i] == '0') //다음 0이 1개이상 나와야함
				i++, cnt++;
			if (cnt < 2) return false;

			cnt = 0; //개수 2개이상인경우 / 끝나거나, 다음1이거나, 다다음1이거나
			while (s[i] == '1' && (s[i + 1] == 0 || s[i + 1] == '1' || s[i + 2] == '1'))
				i++, cnt++;
			if (cnt < 1) return false;
		}
		else { //0시작 : 다음이 1인지 확인
			if (s[i] != '1') return false;
			i++;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	cout << (chk() ? "SUBMARINE" : "NOISE");
}