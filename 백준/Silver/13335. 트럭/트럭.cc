#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w, l; //트럭수, 다리길이, 다리하중
	cin >> n >> w >> l;

	for (int i = 0; i < n; i++) 
		cin >> a[i];
	
	queue<int> q;
	int time = 0, total = 0;
	
	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) {
				total -= q.front();
				q.pop();
			}
			if (total + a[i] <= l) break;
			q.push(0); // 하중이 넘치면 0 삽입
			time++;
		}
		q.push(a[i]);
		total += a[i];
		time++;
	}
	cout << time + w;
}