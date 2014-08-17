/*
  ID: wind1900
  LANG: C
  TASK: concom
*/
#include <stdio.h>
#include <string.h>

int queue[100], start, end;
char v[101];

void clear() {
  start = end = 0;
  memset(v, 0, sizeof(v));
}

void add(int i) {
  queue[end++] = i;
  v[i] = 1;
}

int del() {
  return queue[start++];
}

int empty() {
  return (start == end);
}

int visit(int i) {
  return v[i];
}


int main() {
  int n, i, j, k, l, c[101][101] = {0}, r[101][101] = {0};
  freopen("concom.in", "r", stdin);
  freopen("concom.out", "w", stdout);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d %d", &j, &k, &l);
    c[j][k] = l;
  }
  for (i = 1; i <= 100; i++) {
    c[i][i] = 100;
    clear();
    for (j = 1; j <= 100; j++) {
      if (c[i][j] > 50) {
	r[i][j] = c[i][j];
	add(j);
      }
    }
    while (!empty()) {
      j = del();
      for (k = 1; k <= 100; k++) {
	r[i][k] += c[j][k];
	if (r[i][k] > 50 && !visit(k)) {
	  add(k);
	}
      }
    }
  }
  for (i = 1; i <= 100; i++) {
    for (j = 1; j <= 100; j++) {
      if (i == j) continue;
      if (r[i][j] > 50) {
	printf("%d %d\n", i, j);
      }
    }
  }
  return 0;
}
