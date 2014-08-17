/*
ID: wind1900
LANG: C
TASK: holstein
*/
#include <stdio.h>

int v, g, need[25], vit[15][25];
int r = 16, ans[15] = {0}, tans[15] = {0}, test[25] = {0};

int valid() {
  int i;
  for (i = 0; i < v; i++) {
    if (test[i] < need[i]) return 0;
  }
  return 1;
}

void search(int l, int c) {
  int i;
  if (valid()) {
    if (c < r) {
      r = c;
      for (i = 0; i < g; i++) {
	ans[i] = tans[i];
      }
    }
    return;
  }
  if (l >= g) return;
  tans[l] = 1;
  for (i = 0; i < v; i++) {
    test[i] += vit[l][i];
  }
  search(l + 1, c + 1);  
  tans[l] = 0;
  for (i = 0; i < v; i++) {
    test[i] -= vit[l][i];
  }
  search(l + 1, c);
}

int main() {
  int i, j;
  freopen("holstein.in", "r", stdin);
  freopen("holstein.out", "w", stdout);
  scanf("%d", &v);
  for (i = 0; i < v; i++) {
    scanf("%d", need+i);
  }
  scanf("%d", &g);
  for (i = 0; i < g; i++) {
    for (j = 0; j < v; j++) {
      scanf("%d", &vit[i][j]);
    }
  }
  search(0, 0);
  printf("%d ", r);
  for (i = 0, j = 1; i < g; i++) {
    if (ans[i]) {
      printf("%d%c", i + 1, j == r ? '\n' : ' ');
      j++;
    }
  }
  return 0;
}
