/*
  ID: wind1900
  LANG: C
  TASK: preface
*/

#include <stdio.h>

int r[7] = {0};
int ixc[] = {0, 1, 2, 3, 1, 0, 1, 2, 3, 1};
int vld[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 0};

void add(int i) {
  int a, b, j;
  a = i / 1000;
  i = i % 1000;
  r[6] += a;
  for (b = 100, j = 4; j >= 0; b = b / 10, j -= 2) {
    a = i / b;
    i = i % b;
    r[j] += ixc[a];
    r[j + 1] += vld[a];
    if (a == 9) {
      r[j + 2]++;
    }
  }
}

int main() {
  int n, i;
  char c[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
  freopen("preface.in", "r", stdin);
  freopen("preface.out", "w", stdout);
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    add(i);
  }
  for (i = 0; r[i]; i++) {
    printf("%c %d\n", c[i], r[i]);
  }
  return 0;
}
