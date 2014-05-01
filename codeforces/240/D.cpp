#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, j, k, l, r = 0;
	scanf("%d %d", &n, &k);
	int** s = (int**) malloc(k * sizeof(int*));
	for (i = 0; i < k; i++) {
		s[i] = (int*) malloc(n * sizeof(int));
		for (j = 0; j < n; j++) {
			s[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++) {
		s[0][i] = 1;
	}
	for (j = 1; j < k; j++) {
		for (i = 0; i < n; i++) {
			for (l = i + 1; l < n + 1; l += i + 1) {
				s[j][l - 1] = (s[j][l - 1] + s[j - 1][i]) % 1000000007;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		r = (r + s[j-1][i]) % 1000000007;
	}
	printf("%d\n", r);
	return 0;
}
