#include <bits/stdc++.h>
using namespace std;

/*
v[i] = m * temp[i] + r   r이 같아야함
즉, v[i] - v[i - 1] = m * (temp[i] - temp[i-1]) + (r - r) 으로
나머지가 0이 되어야함
*/

int GCD(int a, int b){
	if (b == 0) return a;
	return GCD(b, a%b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v, ans;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	int gcd = v[1] - v[0];
	for (int i = 2; i < n; i++)
		gcd = GCD(gcd, v[i] - v[i - 1]);

	ans.push_back(gcd);
	for (int i = 2; i * i <= gcd; i++) { //최대공약수의 약수
		if (gcd % i == 0) {
			ans.push_back(i);
			ans.push_back(gcd / i);
		}
	}

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	for (auto x : ans)
		cout << x << ' ';
}