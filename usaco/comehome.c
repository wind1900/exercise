/*
  ID: wind1900
  LANG: C
  TASK: comehome
*/
#include <stdio.h>

int map(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a';
  }
  return 26 + c - 'A';
}

int main() {
  int p, i, j, k, le, d[52], l[52][52] = {0};
  char a, b, v[52] = {0};
  freopen("comehome.in", "r", stdin);
  freopen("comehome.out", "w", stdout);
  scanf("%d\n", &p);
  for (i = 0; i < 52; i++) {
    d[i] = 100000;
  }
  for (i = 0; i < p; i++) {
    scanf("%c %c %d\n", &a, &b, &le);
    j = map(a);
    k = map(b);
    if (j == k) continue;
    if (l[j][k]) {
      if (l[j][k] > le) {
	l[j][k] = l[k][j] = le;
      }
    } else {
      l[j][k] = le;
      l[k][j] = le;
    }
  }
  k = 51;
  d[k] = 0;
  v[k] = 1;
  for (i = 0; i < 52; i++) {
    if (l[k][i] > 0) {
      d[i] = l[k][i];
    }
  }
  while (1) {
    k = -1;
    for (i = 0; i < 52; i++) {
      if (v[i]) continue;
      if (k == -1 || d[i] < d[k]) {
	k = i;
      }
    }
    if (k >= 26) break;
    v[k] = 1;
    for (i = 0; i < 52; i++) {
      if (v[i]) continue;
      if (l[k][i] > 0 && d[i] > d[k] + l[k][i]) {
	d[i] = d[k] + l[k][i];
      }
    }
  }
  printf("%c %d\n", 'A' + k - 26, d[k]);
  return 0;
}
