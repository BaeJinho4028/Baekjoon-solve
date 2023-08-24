#include <iostream>
#include <stack>
using namespace std;
int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	bool possible = true;
	stack<int> stk;
	string result;
	int temp = 1;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		for (int j = temp; j <= a; j++)
		{
			stk.push(j);
			result += '+';
			temp++;
		}
		if (stk.top() == a)
		{
			stk.pop();
			result += '-';
		}
		else
		{
			possible = false;
		}
	}
	if (possible == false)
	{
		cout << "NO";
	}
	else
	{
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "\n";
		}
	}
	return 0;
}