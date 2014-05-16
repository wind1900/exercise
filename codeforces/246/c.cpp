#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>

using namespace std;

vector<pair<int, int>> r;

int p[100001];

bool isPrime(int i) {
	for (int j = 2; j < sqrt(i)+1; j++) {
		if (i % j == 0) return false;
	}
	return true;
}

void swap(int i, int j, int a[100000], int ps[100001]) {
	int d = j - i + 1, t, k;
	while (p[d]) {
		t = p[d];
		pair<int, int> pa(j - t + 2, j + 1);
		r.push_back(pa);
		k = j - t + 1;
		a[k] ^= a[j];
		a[j] ^= a[k];
		a[k] ^= a[j];
		ps[a[k]] ^= ps[a[j]];
		ps[a[j]] ^= ps[a[k]];
		ps[a[k]] ^= ps[a[j]];
		j = j - t + 1;
		d = j - i + 1;
	}
}

int main() {
	int n, i, j, m, t = 3;
	int a[100000];
	int ps[100001];
	scanf("%d", &n);
	p[0] = 0;
	p[1] = 0;
	p[2] = 2;
	p[3] = 3;
	for (i = 4; i < 100001; i++) {
		if (isPrime(i)) t = i;
		p[i] = t;
	}
	for (i = 0; i < n; i++) {
		scanf("%d", a + i);
		ps[a[i]] = i;
	}
	for (i = 0; i < n - 1; i++) {
		t = ps[i+1];
		swap(i, t, a, ps);
	}
	printf("%d\n", r.size());
	for (pair<int,int> p : r) {
		printf("%d %d\n", p.first, p.second);
	}
	return 0;
}
