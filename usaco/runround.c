/*
  ID: wind1900
  LANG: C
  TASK: runround
*/
#include <stdio.h>

int valid(int m) {
  char num[10] = {0}, v[10] = {0};
  int i, l, r = 0;
  for (l = 0; m; l++) {
    i = m % 10;
    if (v[i]) return 0;
    v[i] = 1;
    num[l] = i;
    m = m / 10;
  }
  if (v[0]) return 0;
  i = l - 1;
  while (v[num[i]]) {
    r++;
    v[num[i]] = 0;
    i = i - num[i];
    while (i < 0) i += l;
  }
  return (r == l && i == (l - 1));
}

int main() {
  int m;
  freopen("runround.in", "r", stdin);
  freopen("runround.out", "w", stdout);
  scanf("%d", &m);
  while (++m) {
    if (valid(m)) break;
  }
  printf("%d\n", m);
  return 0;
}
