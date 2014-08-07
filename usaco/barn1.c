/*
ID: wind1900
LANG: C
TASK: barn1
*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  return *(int*) a - *(int*) b;
}

int main() {
  int m, s, c, i, j, cow[200], sep[200];
  freopen("barn1.in", "r", stdin);
  freopen("barn1.out", "w", stdout);
  scanf("%d%d%d", &m, &s, &c);
  for (i = 0; i < c; i++) {
    scanf("%d", cow + i);
  }
  qsort(cow, c, sizeof(int), cmp);
  for (i = 0, j = 0; i < c - 1; i++) {
    if (cow[i + 1] - cow[i] - 1 > 0)
      sep[j++] = cow[i + 1] - cow[i] - 1;
  }
  qsort(sep, j, sizeof(int), cmp);
  m = j + 1 - m;
  i = 0;
  for (i = 0; m > 0; i++) {
    c += sep[i];
    m--;
  }
  printf("%d\n", c);
  return 0;
}
