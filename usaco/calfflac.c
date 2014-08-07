/*
  ID: wind1900
  LANG: C
  TASK: calfflac
*/
#include <stdio.h>

int isAlpha(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int left(char s[], int c) {
  int i = c - 1;
  while (i >= 0) {
    if (isAlpha(s[i]))
      return i;
    i--;
  }
  return i;
}

int right(char s[], int c, int l) {
  int i = c + 1;
  while (i < l) {
    if (isAlpha(s[i]))
      return i;
    i++;
  }
  return -1;
}

int equal(char a, char b) {
  int i, j;
  if (a >= 'A' && a <= 'Z') {
    i = a - 'A';
  } else {
    i = a - 'a';
  }
  if (b >= 'A' && b <= 'Z') {
    j = b - 'A';
  } else {
    j = b - 'a';
  }
  return i == j;
}

int main() {
  char s[20000], c;
  int i, j, k, r = 0, rl = 1, l, ii, jj, ll;
  freopen("calfflac.in", "r", stdin);
  freopen("calfflac.out", "w", stdout);
  i = 0;
  while ((c = getchar()) != EOF) {
    s[i++] = c;
  }
  s[i] = 0;
  l = i;
  for (k = 0; k < l; k++) {
    if (!isAlpha(s[k])) continue;
    i = k;
    j = k;
    ll = 1;
    ii = left(s, i);
    jj = right(s, j, l);
    while (ii >= 0 && jj >= 0 && equal(s[ii], s[jj])) {
      i = ii;
      j = jj;
      ii = left(s, i);
      jj = right(s, j, l);
      ll += 2;
    }
    if (rl < ll) {
      rl = ll;
      r = i;
    }
  }
  for (k = 0; k < l - 1; k++) {
    if (!isAlpha(s[k])) continue;
    i = k;
    j = right(s, i, l);
    if (j < 0 || !equal(s[i], s[j])) continue;
    ll = 2;
    ii = left(s, i);
    jj = right(s, j, l);
    while (ii >= 0 && jj >= 0 && equal(s[ii], s[jj])) {
      i = ii;
      j = jj;
      ii = left(s, i);
      jj = right(s, j, l);
      ll += 2;
    }
    if (rl < ll) {
      rl = ll;
      r = i;
    }
  }
  printf("%d\n", rl);
  for (i = r; rl; i++) {
    if (isAlpha(s[i])) {
      rl--;
    }
    putchar(s[i]);
  }
  putchar('\n');
  return 0;
}
