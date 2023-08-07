#include <iostream>
using namespace std;

int Euclidean(int m, int n)
{
	if (n == 0)
		return m;
	else
		return Euclidean(n, m % n);
}

int main(void)
{
	long long n, a, b;
	cin >> n;


	for (int i{ 0 }; i < n; ++i)
	{
		cin >> a >> b;
		cout << b * (a / Euclidean(a, b)) << '\n';
	}

	return 0;
}