#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int k;
	cin >> k;

	stack<int> st;

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;

		if (x == 0) 
			st.pop();
		else
			st.push(x);
	}

	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}

	cout << sum;
}