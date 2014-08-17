/*
  ID: wind1900
  LANG: C
  TASK: nocows
*/
#include <stdio.h>

int main() {
  int r[201][100], i, j, n, k, kk, l;
  freopen("nocows.in", "r", stdin);
  freopen("nocows.out", "w", stdout);
  scanf("%d%d", &n, &k);
  r[1][1] = 1;
  if ((n & 1) == 0) {
    printf("0\n");
    return 0;
  }
  for (l = 3; l <= n; l += 2) {
    for (kk = 2; kk <= (l + 1) / 2; kk++) {
      r[l][kk] = 0;
      for (i = 1; i < l; i += 2) {
	if (r[i][kk - 1] == 0) continue;
	for (j = 1; j < kk; j++) {
	  if (r[l - i - 1][j]) {
	    if (j == kk - 1) {
	      r[l][kk] += r[i][kk - 1] * r[l - i - 1][j];
	    } else {
	      r[l][kk] += 2 * r[i][kk - 1] * r[l - i - 1][j];
	    }
	    if (r[l][kk] >= 9901) {
	      r[l][kk] = r[l][kk] % 9901;
	    }
	  }
	}
      }
    }
  }
  printf("%d\n", r[n][k]);
  return 0;
}
