#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    cout << (int)(n * 0.78) << " " << (int)(n * 0.8 + n * 0.2 * 0.78);
}