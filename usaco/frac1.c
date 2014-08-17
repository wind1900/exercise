/*
ID: wind1900
LANG: C
TASK: frac1
*/

/*
  A super fast solution.
  Start from 0/1 and 1/1, use (lambda a1, b1, a2, b2: a1+a2/b1+b2) to generate middle value recursively.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a;
  int b;
} frac;

int fi = 0;
frac f[8000];

int valid(int a, int b) {
  int c = a % b;
  while (c) {
    a = b;
    b = c;
    c = a % b;
  }
  return (b == 1);
}

int cmp(const void *a, const void *b) {
  frac *f1, *f2;
  f1 = (frac*) a;
  f2 = (frac*) b;
  return (f1->a * f2->b) - (f2->a * f1->b);
}

int main() {
  int n, i, j;
  freopen("frac1.in", "r", stdin);
  freopen("frac1.out", "w", stdout);
  scanf("%d", &n);
  f[0].a = 0;
  f[0].b = 1;
  f[1].a = 1;
  f[1].b = 1;
  fi = 2;
  for (i = 2; i <= n; i++) {
    for (j = 1; j < i; j++) {
      if (valid(j, i)) {
	f[fi].a = j;
	f[fi].b = i;
	fi++;
      }
    }
  }
  qsort(f, fi, sizeof(frac), cmp);
  for (i = 0; i < fi; i++) {
    printf("%d/%d\n", f[i].a, f[i].b);
  }
  return 0;
}
