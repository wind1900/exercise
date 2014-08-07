/*
ID: wind1900
LANG: C
TASK: ariprog
*/
#include <stdio.h>

char bs[125001] = {0};

typedef struct {
  int a;
  int b;
} ans;

ans anss[10000];
int ai = 0;

int main() {
  int p, q, a, b, n, m;
  freopen("ariprog.in", "r", stdin);
  freopen("ariprog.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (p = 0; p <= m; p++) {
    for (q = p; q <= m; q++) {
      bs[p * p + q * q] = 1;
    }
  }
  for (b = 1; (n - 1) * b <= 2 * m * m; b++) {
    for (a = 0; a + (n - 1) * b <= 2 * m * m; a++) {
      if (a == 1 && b == 4) {
	a = 1;
      }
      for (p = 0, q = a; p < n; p++, q += b) {
	if (!bs[q]) break;
      }
      if (p == n) {
	anss[ai].a = a;
	anss[ai++].b = b;
      }
    }
  }
  for (a = 0; a < ai; a++) {
    printf("%d %d\n", anss[a].a, anss[a].b);
  }
  if (ai == 0) printf("NONE\n");
  return 0;
}
