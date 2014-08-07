/*
ID: wind1900
LANG: C
TASK: milk3
*/
#include <stdio.h>

int a, b, c, d[21][21][21] = {0}, r[21] = {0};

int min(a, b) {
  return a < b ? a : b;
}

void search(int i, int j, int k) {
  int s;
  if (d[i][j][k]) return;
  d[i][j][k] = 1;
  if (i == 0) {
    r[k] = 1;
  }
  if (i != 0) {
    s = min(b - j, i);
    search(i - s, j + s, k);
    s = min(c - k, i);
    search(i - s, j, k + s);
  }
  if (j != 0) {
    s = min(a - i, j);
    search(i + s, j - s, k);
    s = min(c - k, j);
    search(i, j - s, k + s);
  }
  if (k != 0) {
    s = min(k, a - i);
    search(i + s, j , k - s);
    s = min(k, b - j);
    search(i, j + s, k - s);
  }
}

int main() {
  int i;
  freopen("milk3.in", "r", stdin);
  freopen("milk3.out", "w", stdout);
  scanf("%d%d%d", &a, &b, &c);
  search(0, 0, c);
  for (i = 0; i <= c; i++) {
    if (r[i]) {
      printf("%d%c", i, i == c ? '\n' : ' ');
    }
  }
  return 0;
}
