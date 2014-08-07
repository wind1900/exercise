#include <stdio.h>

int main() {
	int n, m, k, i, j, t;
	long long a, b, r;
	scanf("%d%d%d", &n, &m, &k);
	if (m + n - 2 < k) {
		printf("-1\n");
		return 0;
	}
	r = 0;
	i = 0;
	t = 0;
	if (k >= m) {
		i = k - (m - 1);
	}
	while (t < 100) {
		j = k - i;
		if (i >= n || j < 0) break;
		a = n / (i + 1);
		b = m / (j + 1);
		if (r < a * b) r = a * b;
		t++;
		i++;
	}
	
	t = 0;
	i = n - 1;
	if (k < i) {
		i = k;
	}
	while (t < 100) {
		j = k - i;
		if (i < 0 || j >= m) break;
		a = n / (i + 1);
		b = m / (j + 1);
		if (r < a * b) r = a * b;
		t++;
		i--;
	}
	printf("%I64d\n", r);
	return 0;
}