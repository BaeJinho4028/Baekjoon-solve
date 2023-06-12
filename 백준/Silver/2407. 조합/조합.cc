#include <bits/stdc++.h> //큰수연산 풀이
using namespace std;

string arr[105][105];

string add(string s1, string s2) {
	string num = "";
	int sum = 0;
	int size = max(s1.size(), s2.size());
	for (int i = 0; i < size || sum; i++) {
		if (s1.size() > i) sum += s1[i] - '0';
		if (s2.size() > i) sum += s2[i] - '0';

		num += sum % 10 + '0';
		sum /= 10;
	}

	return num;
}

string combi(int n, int m) {
	if (n == m || m == 0) return "1";

	string& ans = arr[n][m];
	if (ans != "") return ans;

	ans = add(combi(n - 1, m - 1), combi(n - 1, m));
	return ans;
}

int main() {
	int n, m;

	cin >> n >> m;

	combi(n, m);

	for (int i = arr[n][m].size() - 1; i >= 0; i--)
		cout << arr[n][m][i];
}