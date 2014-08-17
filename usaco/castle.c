/*
ID: wind1900
LANG: C
TASK: castle
*/
#include <stdio.h>

int m, n;
char square[50][50];
int id[50][50] = {0}, sid = 1;
int area[2501], ta;
int r = 0, ri, rj;
char rc;

void search(int i, int j) {
  if (id[i][j]) return;
  ta++;
  id[i][j] = sid;
  if ((1 & square[i][j]) == 0) {
    search(i, j - 1);
  }
  if ((2 & square[i][j]) == 0) {
    search(i - 1, j);
  }
  if ((4 & square[i][j]) == 0) {
    search(i, j + 1);
  }
  if ((8 & square[i][j]) == 0) {
    search(i + 1, j);
  }
}

void update(int x1, int y1, int x2, int y2, char c) {
  int t;
  if (x2 < 0 || x2 >= n) return;
  if (y2 < 0 || y2 >= m) return;
  if (id[x1][y1] == id[x2][y2]) return;
  t = area[id[x1][y1]] + area[id[x2][y2]];
  if (t > r) {
    r = t;
    ri = x1;
    rj = y1;
    rc = c;
  } else if (t == r) {
    if (y1 < rj || (rj == y1 && ri < x1)) {
      r = t;
      ri = x1;
      rj = y1;
      rc = c;
    }
  }
}

int main() {
  int i, j, tm;
  freopen("castle.in", "r", stdin);
  freopen("castle.out", "w", stdout);
  scanf("%d %d", &m, &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%d", &tm);
      square[i][j] = tm;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (id[i][j]) continue;
      ta = 0;
      search(i, j);
      area[sid] = ta;
      sid++;
    }
  }
  tm = 0;
  for (i = 1; i < sid; i++) {
    tm = tm > area[i] ?  tm : area[i];
  }
  printf("%d\n%d\n", sid - 1, tm);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if ((1 & square[i][j])) {
	update(i, j, i, j - 1, 'W');
      }
      if ((2 & square[i][j])) {
	update(i, j, i - 1, j, 'N');
      }
      if ((4 & square[i][j])) {
	update(i, j, i, j + 1, 'E');
      }
      if ((8 & square[i][j])) {
	update(i, j, i + 1, j, 'S');
      }
    }
  }
  printf("%d\n%d %d %c\n", r, ri + 1, rj + 1, rc);
  return 0;
}
