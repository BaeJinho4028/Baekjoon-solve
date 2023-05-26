#include <bits/stdc++.h>
using namespace std;


int main() { //왼쪽을 정렬한후   전체 전선 - 오른쪽가장긴증가하는부분수열 
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 3) cout << 0;
	else cout << (n * (n - 1) * (n - 2) * (n - 3)) / (4 * 3 * 2 * 1);
}