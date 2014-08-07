/*
  ID: wind1900
  LANG: C
  TASK: crypt1
*/
#include <stdio.h>

int valid(int n, int v[]) {
  int i = 0;
  while (n) {
    if (!v[n % 10]) return 0;
    n = n / 10;
  }
  return 1;
}

int main() {
  int n, num[10] = {0}, i, j, r, dn[10], di, a, b, c, d, e;
  freopen("crypt1.in", "r", stdin);
  freopen("crypt1.out", "w", stdout);
  scanf("%d", &n);
  for (i = 0, di = 0; i < n; i++) {
    scanf("%d", &j);
    num[j] = 1;
    dn[di++] = j;
  }
  r = 0;
  for (a = 0; a < n; a++) {
    for (b = 0; b < n; b++) {
      for (c = 0; c < n; c++) {
	i = 100 * dn[a] + 10 * dn[b] + dn[c];
	for (d = 0; d < n; d++) {
	  if (!valid(i * dn[d], num)) continue;
	  if (i * dn[d] > 999 || i * dn[d] < 100) continue;
	  for (e = 0; e < n; e++) {
	    if (!valid(i * dn[e], num)) continue;
	    if (i * dn[e] > 999 || i * dn[e] < 100) continue;
	    j = 10 * dn[d] + dn[e];
	    if (!valid(i * j, num)) continue;
	    if (i * j > 9999 || i * j < 1000) continue;
	    r++;
	  }
	}
      }
    }
  }
  printf("%d\n", r);
  return 0;
}
