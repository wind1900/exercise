/*
  ID: wind1900
  LANG: C
  TASK: cowtour
*/
#include <stdio.h>
#include <math.h>
#include <string.h>

int n;
int x[150], y[150];
double r = 200000, d[150], lon[150];
double dis[150][150];

double cdis(int i, int j) {
  return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

double max(double a, double b) {
  return a > b ? a : b;
}

void conn(int a, int b) {
  int i;
  double j;
  j = lon[a] + lon[b] + cdis(a, b);
  for (i = 0; i < n; i++) {
    j = max(j, d[i]);
  }
  if (r > j) r = j;
}

int main() {
  int i, j, k;
  double l;
  char t[151];
  freopen("cowtour.in", "r", stdin);
  freopen("cowtour.out", "w", stdout);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", x + i, y + i);
  }
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      dis[i][j] = dis[j][i] = -1;
    }
    d[i] = -1;
  }
  for (i = 0; i < n; i++) {
    scanf("%s", t);
    for (j = 0; j < n; j++) {
      if (t[j] == '1') {
	dis[i][j] = cdis(i, j);
      }
    }
    dis[i][i] = 0;
  }
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
	if (dis[i][k] >= 0 && dis[k][j] >= 0) {
	  if (dis[i][j] < 0 || dis[i][j] > dis[i][k] + dis[k][j]) {
	    dis[i][j] = dis[i][k] + dis[k][j];
	  }
	}
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      lon[i] = max(lon[i], dis[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    if (d[i] >= 0) continue;
    memset(t, 0, sizeof(t));
    l = 0;
    for (j = 0; j < n; j++) {
      if (dis[i][j] >= 0) {
	t[j] = 1;
      }
    }
    for (j = 0; j < n; j++) {
      if (!t[j]) continue;
      for (k = 0; k < n; k++) {
	if (!t[k]) continue;
	l = max(l, dis[j][k]);
      }
    }
    for (j = 0; j < n; j++) {
      if (t[j]) d[j] = l;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (dis[i][j] < 0)
	conn(i, j);
    }
  }
  printf("%.6f\n", r);
  return 0;
}
