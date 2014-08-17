/*
ID: wind1900
LANG: C
TASK: sort3
*/
#include <stdio.h>

int min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  int n, i, j, k, r = 0, t = 0;
  int a[1000], c[3] = {0};
  int mis[3][3] = {0};
  freopen("sort3.in", "r", stdin);
  freopen("sort3.out", "w", stdout);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", a + i);
    c[a[i]-1]++;
  }
  for (i = 0, k = 0; i < 3; i++) {
    j = 0;
    while (j < c[i]) {
      mis[i][a[k] - 1]++;
      j++;
      if (i != a[k] - 1) t++;
      k++;
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = i + 1; j < 3; j++) {
      k = min(mis[i][j], mis[j][i]);
      mis[i][j] -= k;
      mis[j][i] -= k;
      mis[i][i] += k;
      mis[j][j] += k;
      r += k;
      t -= 2 * k;
    }
  }
  // r = min(mis[0][1],mis[1][0]) + min(mis[0][2], mis[2][0]) + mis(mis[1][2], mis[2][1]) + 2 * (max(mis[0][1], mis[1][0]) - min(mis[0][1], mis[1][0]));
  r += t / 3 * 2;
  printf("%d\n", r);
  return 0;
}
