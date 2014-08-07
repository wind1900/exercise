/*
ID: wind1900
LANG: C
TASK: checker
*/
#include <stdio.h>

int col[13] = {0}, diag1[25] = {0}, diag2[25] = {0}, rr[13];
int n, r;

void search(int row) {
  int i;
  if (row == n) {
    r++;
    if (r <= 3) {
      for (i = 0; i < n; i++) {
	printf("%d%c", rr[i] + 1, i == n - 1 ? '\n' : ' ');
      }
    }
    return;
  }
  for (i = 0; i < n; i++) {
    if (col[i] || diag1[n - 1 - row + i] || diag2[i + row]) continue;
    rr[row] = i;
    col[i] = 1;
    diag1[n - 1 - row + i] = 1;
    diag2[i + row] = i;
    search(row + 1);
    rr[row] = 0;
    col[i] = 0;
    diag1[n - 1 - row + i] = 0;
    diag2[i + row] = 0;
  }
}

int main() {
  freopen("checker.in", "r", stdin);
  freopen("checker.out", "w", stdout);
  scanf("%d", &n);
  search(0);
  printf("%d\n", r);
  return 0;
}
