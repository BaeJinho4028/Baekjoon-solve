#include <bits/stdc++.h>
using namespace std;

string a, b;
int d[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}

	cout << d[a.size()][b.size()] << '\n';

    //yun님코드참고
    
	int len = d[a.size()][b.size()];
	int i = a.size(), j = b.size();
	char ans[1005]{};

	for (int k = 0; k < len; ++k) {
		while (1) {
			if (d[i][j] == d[i][j - 1]) --j;
			else if (d[i][j] == d[i - 1][j]) --i;
			else break;
		}

		ans[len - k - 1] = a[i-1];
		--i, --j;
	}

	cout << ans;
}