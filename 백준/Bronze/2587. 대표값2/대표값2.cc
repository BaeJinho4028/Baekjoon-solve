#include <cstdio>

int main() {
	int n[5];
	int sum = 0;
	int i, j, temp;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &n[i]);
		sum += n[i];
	}


	for (i = 0; i < 5; i++) {
		j = i;
		while (j >= 0 && n[j] > n[j + 1]) {
			temp = n[j];
			n[j] = n[j + 1];
			n[j + 1] = temp;
			j--;
		}
	}

	printf("%d\n%d", sum / 5, n[2]);
}