/*
ID: wind1900
LANG: C
TASK: milk
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int price;
  int amount;
} farmer;

int cmp(const void *a, const void *b) {
  return ((farmer*)a)->price - ((farmer*)b)->price;
}

int main() {
  farmer f[5000];
  int m, n, i, p = 0;
  freopen("milk.in", "r", stdin);
  freopen("milk.out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d%d", &f[i].price, &f[i].amount);
  }
  qsort(f, i, sizeof(farmer), cmp);
  for (i = 0; i < m; i++) {
    if (f[i].amount >= n) {
      p += n * f[i].price;
      break;
    } else {
      p += f[i].amount * f[i].price;
      n -= f[i].amount;
    }
  }
  printf("%d\n", p);
  return 0;
}
