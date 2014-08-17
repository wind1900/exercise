/*
  ID: wind1900
  LANG: C
  TASK: fracdec
*/
#include <stdio.h>
#include <string.h>

int ai;

void write(char c) {
  if (ai == 76) {
    ai = 0;
    putchar('\n');
  }
  putchar(c);
  ai++;
}

int main() {
  int n, d, r, a, i, j;
  char v[100001];
  memset(v, 0, sizeof(v));
  freopen("fracdec.in", "r", stdin);
  freopen("fracdec.out", "w", stdout);
  scanf("%d%d", &n, &d);
  a = n / d;
  r = n % d;
  for (i = 10; i <= a; i *= 10);
  i /= 10;
  while (i) {
    write('0' + a / i);
    a = a % i;
    i = i / 10;
  }
  write('.');
  if (r == 0) {
    write('0');
    putchar('\n');
    return 0;
  }
  i = r;
  while (i && !v[i]) {
    v[i] = 1;
    i = i * 10;
    i = i % d;
  }
  j = i;
  i = r;
  while (i && i != j) {
    i = i * 10;
    a = i / d;
    write('0' + a);
    i = i % d;
  }
  if (i) {
    write('(');
    j = i;
    do {
      i = i * 10;
      a = i / d;
      write('0' + a);
      i = i % d;
    } while (i != j);
    write(')');
  }
  putchar('\n');
  return 0;
}
