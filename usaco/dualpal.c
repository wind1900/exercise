/*
ID: wind1900
LANG: C
TASK: dualpal
*/
#include <stdio.h>
#include <string.h>

void baseStr(int b, int num, char s[]) {
  int i = 0;
  while (num >= b) {
    s[i++] = '0' + num % b;
    num = num / b;
  }
  s[i++] = '0' + num;
  s[i++] = 0;
}

int isPal(char s[]) {
  int i = 0, j = strlen(s) - 1;
  while (i < j) {
    if (s[i++] != s[j--]) return 0;
  }
  return 1;
}

int main() {
  int n, s, i, t;
  char p[40];
  freopen("dualpal.in", "r", stdin);
  freopen("dualpal.out", "w", stdout);
  scanf("%d%d", &n, &s);
  while (n--) {
    while (1) {
      s++;
      t = 0;
      for (i = 2; i < 11 && t < 2; i++) {
	baseStr(i, s, p);
	if (isPal(p)) t++;
      }
      if (t >= 2) break;
    }
    printf("%d\n", s);
  }
  return 0;
}
