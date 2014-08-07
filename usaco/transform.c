/*
ID: wind1900
LANG: C
TASK: transform
*/
#include <stdio.h>

void rotate(char s[][11], char t[][11], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      t[i][j] = s[n - j - 1][i];
    }
  }
}

void reflect(char s[][11], char t[][11], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      t[i][j] = s[i][n - j - 1];
    }
  }
}

int equal(char s[][11], char t[][11], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (s[i][j] != t[i][j]) return 0;
    }
  }
  return 1;
}

int main() {
  int n, i, r = 0;
  char s1[11][11], s2[11][11], t1[11][11], t2[11][11];
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w", stdout);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", s1[i]);
  }
  for (i = 0; i < n; i++) {
    scanf("%s", s2[i]);
  }
  rotate(s1, t1, n);
  if (equal(s2, t1, n)) r = r ? r : 1;
  rotate(t1, t2, n);
  if (equal(s2, t2, n)) r = r ? r : 2;
  rotate(t2, t1, n);
  if (equal(s2, t1, n)) r = r ? r : 3;
  reflect(s1, t1, n);
  if (equal(s2, t1, n)) r = r ? r : 4;
  rotate(t1, t2, n);
  if (equal(s2, t2, n)) r = r ? r : 5;
  rotate(t2, t1, n);
  if (equal(s2, t1, n)) r = r ? r : 5;
  rotate(t1, t2, n);
  if (equal(s2, t2, n)) r = r ? r : 5;
  if (equal(s1, s2, n)) r = r ? r : 6;
  r = r ? r : 7;
  printf("%d\n", r);
  return 0;
}
