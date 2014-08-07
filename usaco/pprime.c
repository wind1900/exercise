/*
ID: wind1900
LANG: C
TASK: pprime
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

int v[3125001];
char p[10001] = {0};
int pn[5000], pi = 0;

int isp(int i) {
  double r = sqrt(i);
  int j = 0;
  while (j < pi && pn[j] <= r) {
    if (i % pn[j] == 0) return 0;
    j++;
  }
  return 1;
}

int get(int i) {
  int a, b;
  a = i / 32;
  b = i % 32;
  return (v[a] & (1 << b));
}

void set(int i) {
  int a, b;
  a = i / 32;
  b = i % 32;
  v[a] = v[a] | (1 << b);
}

void unset(int i) {
  int a, b;
  a = i / 32;
  b = i % 32;
  v[a] = v[a] & ~(1 << b);
}

void pset(int n, int s, int m) {
  int i, t;
  if (n > m) return;
  if (s > 8) return;
  if (n % 10) {
    //printf("set %d\n", n);
    set(n);
  }
  for (t = 1, i = 0; i <= s; i++) {
    t *= 10;
  }
  for (i = 0; i < 10; i++) {
    pset(i * t + 10 * n + i, s + 2, m);
  }
}

int main() {
  int a, b, i, j;
  freopen("pprime.in", "r", stdin);
  freopen("pprime.out", "w", stdout);
  memset(v, 0, 3125001 * sizeof(int));
  scanf("%d%d", &a, &b);
  for (i = 0; i < 10; i++) {
    pset(i, 1, b);
    pset(i * 10 + i, 2, b);
  }

  for (i = 2; i <= sqrt(b); i++) {
    if (p[i]) continue;
    pn[pi++] = i;
    for (j = i + i; j <= sqrt(b); j += i) {
      p[j] = 1;
    }
  }
  for (i = a; i <= b; i++) {
    if (get(i) && isp(i)) {
      printf("%d\n", i);
    }
  }
  return 0;
}
