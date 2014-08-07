/*
ID: wind1900
LANG: C
TASK: palsquare
*/
#include <stdio.h>
#include <string.h>

void baseStr(int b, int num, char s[]) {
  int i = 0, a;
  while (num >= b) {
    a = num % b;
    num = num / b;
    if (a < 10) {
      s[i++] = '0' + a;
    } else {
      s[i++] = 'A' + a - 10;
    }
  }
  if (num < 10) {
    s[i++] = '0' + num;
  } else {
    s[i++] = 'A' + num - 10;
  }
  s[i++] = 0;
}

int isPal(char s[]) {
  int i = 0, j = strlen(s) - 1;
  while (i < j) {
    if (s[i++] != s[j--]) return 0;
  }
  return 1;
}

void reverse(char s[]) {
  int l = strlen(s), i;
  char c;
  for (i = 0; i < l / 2; i++) {
    c = s[i];
    s[i] = s[l - i - 1];
    s[l - i - 1] = c;
  }
}

int main() {
  int n, i;
  char s[20], t[20];
  freopen("palsquare.in", "r", stdin);
  freopen("palsquare.out", "w", stdout);
  scanf("%d", &n);
  for (i = 1; i <= 300; i++) {
    baseStr(n, i * i, t);
    if (isPal(t)) {
      baseStr(n, i, s);
      reverse(s);
      printf("%s %s\n", s, t);
    }
  }
  return 0;
}
