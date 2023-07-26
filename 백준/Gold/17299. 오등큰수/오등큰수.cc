#include <bits/stdc++.h>
using namespace std;

#define MAX 1000005

int a[MAX], f[MAX], ngf[MAX];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[a[i]]++;
	}

	memset(ngf, -1, sizeof(ngf));

	stack<int> st;

	for (int i = 1; i <= n; i++) {
		while (!st.empty() && f[a[st.top()]] < f[a[i]]) {
			ngf[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 1; i <= n; i++)
		cout << ngf[i] << ' ';
}