/*
  ID: wind1900
  LANG: C
  TASK: friday
*/
#include <stdio.h>
int main() {
  int year, n, i, j, d;
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int r[7] = {0};
  d = 0;
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    year = 1900 + i;
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
      days[2] = 29;
    } else {
      days[2] = 28;
    }
    for (j = 1; j <= 12; j++) {
      r[d]++;
      d = (d + days[j]) % 7;
    }
  }
  for (i = 0; i < 7; i++) {
    printf("%d%c", r[i], i == 6 ? '\n' : ' ');
  }
  return 0;
}
