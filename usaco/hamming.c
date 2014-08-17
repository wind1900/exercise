/*
ID: wind1900
LANG: C
TASK: hamming
*/
#include <stdio.h>

/*
  Imporve:
  numbers are sorted, search from the current highest number.
  pre-compute the hamming distance
 */

int n, b, d;
int ans[64] = {0};

int dis(int a, int b) {
  a = a ^ b;
  b = 0;
  while (a) {
    b++;
    a = a & (a - 1);
  }
  return b;
}

int valid(int a, int l) {
  int i;
  for (i = 0; i < l; i++) {
    if (dis(ans[i], a) < d) return 0;
  }
  return 1;
}

int search(int l) {
  int i;
  if (l == n) return 1;
  for (i = 0; i < (1 << b); i++) {
    if (valid(i, l)) {
      ans[l] = i;
      if (search(l + 1)) return 1;
    }
  }
  return 0;
}

int main() {
  int i;
  char c;
  freopen("hamming.in", "r", stdin);
  freopen("hamming.out", "w", stdout);
  scanf("%d%d%d", &n, &b, &d);
  search(1);
  for (i = 0; i < n; i++) {
    c = ' ';
    if (i == n - 1 || ((i + 1) % 10 == 0)) c = '\n';
    printf("%d%c", ans[i], c);
  }
  return 0;
}
