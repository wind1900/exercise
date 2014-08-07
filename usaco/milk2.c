/*
ID: wind1900
LANG: C
TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>

struct t {
  int time;
  int s;
};

int compare(const void *a, const void *b) {
  struct t *aa, *bb;
  int r;
  aa = (struct t*) a;
  bb = (struct t*) b;
  r = aa->time - bb->time;
  if (r == 0) return (bb->s - aa->s);
  return r;
}

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int n, i, s, e, di = 0;
  int total = 0, idle = 0, milk = 0, start;
  struct t data[10000];
  freopen("milk2.in", "r", stdin);
  freopen("milk2.out", "w", stdout);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &s, &e);
    data[di].time = s;
    data[di++].s = 1;
    data[di].time = e;
    data[di++].s = -1;
  }
  qsort(data, di, sizeof(struct t), compare);
  for (i = 0; i < 2 * n; i++) {
    if (total == 0) start = data[i].time;
    total += data[i].s;
    if (total == 0) {
      milk = max(milk, data[i].time - start);
      if (i < 2 * n - 1) {
	idle = max(idle, data[i+1].time - data[i].time);
      }
    }
  }
  printf("%d %d\n", milk, idle);
  return 0;
}
