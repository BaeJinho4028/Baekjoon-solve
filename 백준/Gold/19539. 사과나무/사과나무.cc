#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int sum = 0, two = 0;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
		two += x / 2;
	}

	//3의배수여야하고
	//(총합 / 3)= (물뿌리개를 사용하는 횟수) = (2를 사용해야 하는 횟수) <= 2로 나눈 몫의 합 
	if (sum % 3 == 0 && sum / 3 <= two)
		cout << "YES";
	else cout << "NO";
}