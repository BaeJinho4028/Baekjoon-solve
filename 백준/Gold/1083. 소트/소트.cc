#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MOD 1000000003
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define ll long long
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1};

int arr[55];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int s;
	cin >> s;

	for (int i = 0; i < n; i++) {
		int mx = arr[i];
		int idx = i;

		for (int j = i + 1; j < n; j++) {
			if (s >= j - i) {
				if (mx < arr[j]) {
					mx = arr[j];
					idx = j;
				}
			}
		}

		for (int j = idx; j > i; j--) {
			swap(arr[j], arr[j - 1]);
		}
		s -= (idx - i);

		if (s <= 0) break;
	}
	

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
}