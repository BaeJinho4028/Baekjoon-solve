#include <bits/stdc++.h>
using namespace std;

using namespace std;

int n;
vector<pair<int, int>> arr;

int Distance(int low, int high) {
	int lowX = arr[low].first, lowY = arr[low].second;
	int highX = arr[high].first, highY = arr[high].second;

	int disX = highX - lowX, disY = highY - lowY;

	return disX * disX + disY * disY;
}

int BinarySearch(int low, int high) {
	if (low == high)
		return '????';

	if (low + 1 >= high)
		return Distance(low, high);

	int disMin = Distance(low, high);
	int tempDis = 0, mid = (low + high) / 2;

	if ((tempDis = BinarySearch(low, mid)) < disMin) {
		disMin = tempDis;
	}
	if ((tempDis = BinarySearch(mid + 1, high)) < disMin) {
		disMin = tempDis;
	}

	vector<pair<int, int>> inner;
	int lineX = arr[mid].first;
	
	for (int i = mid; i >= low; i--) {
		int x = arr[i].first, dist = lineX - x;
		if (disMin <= dist * dist) break;
		inner.push_back({ arr[i].second, arr[i].first });
	}

	for (int i = mid + 1; i <= high; i++) {
		int x = arr[i].first, dist = lineX - x;
		if (disMin <= dist * dist) break;
		inner.push_back({ arr[i].second, arr[i].first });
	}

	int len = inner.size();

	if (len == 0) return disMin;

	sort(inner.begin(), inner.end());

	for (int i = 0; i < len; i++) {
		int iX = inner[i].second, iY = inner[i].first;
		for (int j = i + 1; j < len; j++) {
			int jX = inner[j].second, jY = inner[j].first;
			int distX = jX - iX, distY = jY - iY;
			if (disMin <= distY * distY) break;
			if (disMin <= distX * distX) continue;

			int dist = distX * distX + distY * distY;
			if (dist < disMin)
				disMin = dist;
		}
	}

	return disMin;
}

int main() {
	cin >> n;

	arr = vector<pair<int, int>>(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end());

	printf("%d \n", BinarySearch(0, n - 1));
}