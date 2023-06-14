#include <bits/stdc++.h>
using namespace std;

int color[4], num[10];  // R B Y G의 개수 숫자의 개수
int mx;
int two1, two2, three, four;
bool same, pre;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		char a;
		int b;
		cin >> a >> b;

		if (a == 'R') color[0]++;
		if (a == 'B') color[1]++;
		if (a == 'Y') color[2]++;
		if (a == 'G') color[3]++;

		num[b]++;

		mx = max(mx, b);
	}

	for (int i = 1; i < 10; i++) {
		if (num[i] == 2) {
			if (two1 == 0) two1 = i;
			else two2 = i;
		}
		if (num[i] == 3)
			three = i;
		if (num[i] == 4)
			four = i;
	}

	if (color[0] == 5 || color[1] == 5 || color[2] == 5 || color[3] == 5 || color[4] == 5)
		same = true;
	for (int i = 5; i < 10; i++)
		if (num[i - 4] && num[i - 3] && num[i - 2] && num[i - 1] && num[i])
			pre = true;

	if (same && pre)
		cout << mx + 900;
	else if (four)
		cout << four + 800;
	else if (three && two1)
		cout << three * 10 + two1 + 700;
	else if (same)
		cout << mx + 600;
	else if (pre)
		cout << mx + 500;
	else if (three)
		cout << three + 400;
	else if (two1 && two2)
		cout << two2 * 10 + two1 + 300;
	else if (two1)
		cout << two1 + 200;
	else
		cout << mx + 100;

}