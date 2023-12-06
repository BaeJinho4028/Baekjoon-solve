#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define ll long long

map<char, int> ma;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ma['I'] = 1;
	ma['V'] = 5;
	ma['X'] = 10;
	ma['L'] = 50;
	ma['C'] = 100;
	ma['D'] = 500;
	ma['M'] = 1000;

	string a, b;
	cin >> a >> b;

	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		if (ma[a[i]] < ma[a[i + 1]]) 
			sum -= ma[a[i]];
		else 
			sum += ma[a[i]];
	}
	for (int i = 0; i < b.size(); i++) {
		if (ma[b[i]] < ma[b[i + 1]])
			sum -= ma[b[i]];
		else
			sum += ma[b[i]];
	}
	cout << sum << '\n';


	string s = "";

	while (sum) {
		if (sum >= 1000) {
			s += "M";
			sum -= 1000;
		}
		else if (sum >= 900) {
			s += "CM";
			sum -= 900;
		}
		else if (sum >= 500) {
			s += "D";
			sum -= 500;
		}
		else if (sum >= 400) {
			s += "CD";
			sum -= 400;
		}
		else if (sum >= 100) {
			s += "C";
			sum -= 100;
		}
		else if (sum >= 90) {
			s += "XC";
			sum -= 90;
		}
		else if (sum >= 50) {
			s += "L";
			sum -= 50;
		}
		else if (sum >= 40) {
			s += "XL";
			sum -= 40;
		}
		else if (sum >= 10) {
			s += "X";
			sum -= 10;
		}
		else if (sum >= 9) {
			s += "IX";
			sum -= 9;
		}
		else if (sum >= 5) {
			s += "V";
			sum -= 5;
		}
		else if (sum >= 4) {
			s += "IV";
			sum -= 4;
		}
		else if (sum >= 1) {
			s += "I";
			sum -= 1;
		}
	}

	cout << s;
}