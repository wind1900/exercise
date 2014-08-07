/*
ID: wind1900
LANG: C
TASK: clocks
*/
#include <stdio.h>
#include <string.h>

int c[9], cc[9];
int t[9] = {0}, ans[9], len = 30;
int m[9][5] = {{1,2,4,5},
	       {1,2,3},
	       {2,3,5,6},
	       {1,4,7},
	       {2,4,5,6,8},
	       {3,6,9},
	       {4,5,7,8},
	       {7,8,9},
	       {5,6,8,9}
};

void copy(int a[9], int b[9]) {
  int i;
  for (i = 0; i < 9; i++) {
    b[i] = a[i];
  }
}

void update() {
  int i, len1;
  for (i = 0, len1 = 0; i < 9; i++) {
    len1 += t[i];
  }
  if (len1 < len) {
    len = len1;
    copy(t, ans);
  } else if (len1 == len) {
    for (i = 0; i < len && ans[i] == t[i]; i++);
    if (ans[i] > t[i]) {
      copy(t, ans);
    }
  }
}

void check() {
  int i, j, k;
  copy(c, cc);
  if (t[0] == 0 && t[1] == 0 && t[2] == 0 && t[3] == 1 && t[4] == 1 && t[5] == 0 && t[6] == 0 && t[7] == 1 && t[8] == 1) {
    t[0] = 0;
  }
  for (i = 0; i < 9; i++) {
    for (j = 0; j < t[i]; j++) {
      for (k = 0; k < 5 && m[i][k]; k++) {
	cc[m[i][k] - 1]++;
      }
    }
  }
  for (i = 0; i < 9; i++) {
    if (cc[i] % 4 != 0) break;
  }
  if (i == 9) {
    update();
  }
}

void search(int l) {
  int i;
  if (l == 9) {
    check();
    return;
  }
  for (i = 0; i < 4; i++) {
    t[l] = i;
    search(l + 1);
  }
}

int main() {
  int i, j, k;
  freopen("clocks.in", "r", stdin);
  freopen("clocks.out", "w", stdout);
  for (i = 0; i < 9; i++) {
    scanf("%d", c + i);
    c[i] = c[i] / 3 % 4;
  }
  search(0);
  for (i = 0, k = 1; i < 9; i++) {
    for (j = 0; j < ans[i]; j++, k++) {
      printf("%d%c", i + 1, k == len ? '\n' : ' ');
    }
  }
  return 0;
}
