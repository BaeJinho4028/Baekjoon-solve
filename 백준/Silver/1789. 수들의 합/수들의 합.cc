#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long s;
	cin >> s;

	long long c = 0;
	long long i = 1;

	while (1) {
		c += i;
		if (c > s) break;
		i++;
	}
	cout << i-1;
}