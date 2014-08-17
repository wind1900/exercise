/*
  ID: wind1900
  LANG: C
  TASK: subset
*/

#include <stdio.h>
#include <string.h>

// improve: 01knapsack / 2

int main() {
  int n, s, i, j;
  int r[40][800];
  freopen("subset.in", "r", stdin);
  freopen("subset.out", "w", stdout);
  scanf("%d", &n);
  s = n * (n + 1) / 2;
  if (s % 2) {
    printf("%d\n", 0);
    return 0;
  }
  memset(r, 0, sizeof(int) * (n + 1) * 800);
  r[1][1] = 1;
  s = 1;
  for (i = 2; i <= n; i++) {
    for (j = 0; j <= s; j++) {
      r[i][j + i] += r[i - 1][j];
      if (j - i >= 0) {
	r[i][j - i] += r[i - 1][j];
      } else {
	r[i][i - j] += r[i - 1][j];
      }
    }
    s += i;
  }
  printf("%d\n", r[n][0]);
  return 0;
}
