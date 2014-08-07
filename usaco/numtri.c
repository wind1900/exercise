/*
ID: wind1900
LANG: C
TASK: numtri
*/
#include <stdio.h>

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int i, j, s[1010] = {0}, r, t;
  freopen("numtri.in", "r", stdin);
  freopen("numtri.out", "w", stdout);
  scanf("%d", &r);
  for (i = 0; i <= r; i++) {
    for (j = 0; j < i; j++) {
      scanf("%d", &t);
      s[r - i + j] = max(s[r - i + j], s[r - i + j + 1]) + t;
    }
  }
  t = 0;
  for (i = 1; i <= r; i++) {
    t = max(t, s[i]);
  }
  printf("%d\n", t);
  return 0;
}
