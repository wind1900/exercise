/*
ID: wind1900
LANG: C
TASK: sprime
*/
#include <stdio.h>

int p[6000], pi;

int isPrime(int a) {
  int i;
  if (a == 1) return 0;
  for (i = 0; i < pi && p[i] * p[i] <= a; i++) {
    if (a % p[i] == 0) return 0;
  }
  return 1;
}

int issprime(int a) {
  while (a) {
    //if (!get(a)) return 0;
    if (!isPrime(a)) return 0;
    a = a / 10;
  }
  return 1;
}

void search(int num, int l) {
  int i, j;
  if (!l) {
    if (issprime(num)) {
      printf("%d\n", num);
    }
    return;
  }
  for (i = 1; i < 10; i+=2) {
    if (i == 5) continue;
    j = num + i * l;
    search(j, l / 10);
  }
}

int main() {
  int n, a = 1, b, i, j;
  int l[4] = {2,3,5,7};
  freopen("sprime.in", "r", stdin);
  freopen("sprime.out", "w", stdout);
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++) {
    a *= 10;
  }
  b = a * 10;
  p[pi++] = 2;
  for (i = 3; i * i <= b; i+=2) {
    if (isPrime(i)) {
      p[pi++] = i;
    }
  }
  for (i = 0; i < 4; i++) {
    search(l[i] * a, a / 10);
  }
  return 0;
}
