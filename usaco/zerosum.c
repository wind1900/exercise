/*
  ID: wind1900
  LANG: C
  TASK: zerosum
*/
#include <stdio.h>

char ans[8], t[3] = {' ', '+', '-'};
int n;

void check() {
  char s = '+';
  int r = 0, i = 0, t = 1;
  while (i < n) {
    while (i < n - 1 && ans[i] == ' ') {
      t = t * 10 + i + 2;
      i++;
    }
    if (s == '+') {
      r += t;
    } else {
      r -= t;
    }
    s = ans[i++];
    t = i + 1;
  }
  if (r == 0) {
    for (i = 0; i < n - 1; i++) {
      printf("%d%c", i + 1, ans[i]);
    }
    printf("%d\n", n);
  }
}

void search(int l) {
  int i;
  if (l == n - 1) {
    check();
    return;
  }
  for (i = 0; i < 3; i++) {
    ans[l] = t[i];
    search(l + 1);
  }
}

int main() {
  freopen("zerosum.in", "r", stdin);
  freopen("zerosum.out", "w", stdout);
  scanf("%d", &n);
  search(0);
  return 0;
}
