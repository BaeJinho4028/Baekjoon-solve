#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> A, B;
vector<int> C;

void bs(int t) {
	int st = 0;
	int en = B.size() - 1;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (t > B[mid])
			st = mid + 1;
		else if (t < B[mid])
			en = mid - 1;
		else return;
	}
	
	C.push_back(t);
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		A.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		cin >> num;
		B.push_back(num);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());


	for(int i=0; i<A.size(); i++){
		bs(A[i]);
	}

	cout << C.size() << '\n';
	for (int i = 0; i < C.size(); i++) {
		cout << C[i] << ' ';
	}
}