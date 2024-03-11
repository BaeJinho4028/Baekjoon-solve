#include <cstdio>

int main() {
	int N, M, t, sum;
	int e = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		t = i;
		sum = t;
		while (t != 0) {
			sum += t % 10;
			t /= 10;
		}
		if (sum == N) {
			e = i;
			break;
		}
	}
	printf("%d", e);
}
