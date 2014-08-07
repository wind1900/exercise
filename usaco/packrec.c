/*
ID: wind1900
LANG: C
TASK: packrec
*/
#include <stdio.h>

typedef struct {
  int width;
  int height;
} rect;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int max(int a, int b) {
  return a > b ? a : b;
}

rect rects[4];
int r = 10000, ans[100], ai;

int cmp(const void *a, const void *b) {
  return *(int*) a - *(int*) b;
}

void update(int w, int h) {
  int i;
  if (r > w * h) {
    r = w * h;
    ai = 0;
  }
  if (r == w * h) {
    w = w < h ? w : h;
    for (i = 0; i < ai; i++) {
      if (ans[i] == w) {
	return;
      }
    }
    ans[ai++] = w;
  }
}

void check(int a[]) {
  int width, height, i;
  // case 1
  for (i = 0, width = 0, height = rects[0].height; i < 4; i++) {
    width += rects[i].width;
    height = max(height, rects[i].height);
  }
  update(width, height);

  // case 2
  width = 0;
  height = 0;
  for (i = 1; i < 4; i++) {
    height = max(height, rects[a[i]].height);
    width += rects[a[i]].width;
  }
  height += rects[a[0]].height;
  width = max(width, rects[a[0]].width);
  update(width, height);

  // case 3
  width = 0;
  height = 0;
  for (i = 1; i < 3; i++) {
    width += rects[a[i]].width;
    height = max(height, rects[a[i]].height);
  }
  height += rects[a[0]].height;
  width = max(width, rects[a[0]].width);
  height = max(height, rects[a[3]].height);
  width += rects[a[3]].width;
  update(width, height);

  // case 4
  width = max(rects[a[0]].width, rects[a[1]].width);
  height = rects[a[0]].height + rects[a[1]].height;
  for (i = 2; i < 4; i++) {
    width += rects[a[i]].width;
    height = max(height, rects[a[i]].height);
  }
  update(width, height);

  // case 6
  width = max(rects[a[0]].width + rects[a[1]].width,
	      rects[a[2]].width + rects[a[3]].width);
  height = max(rects[a[0]].height + rects[a[3]].height,
		rects[a[1]].height + rects[a[2]].height);
  if (rects[a[0]].width < rects[a[3]].width && 
      rects[a[0]].height < rects[a[1]].height) {
    width = max(width, rects[a[1]].width + rects[a[3]].width);
  }
  if (rects[a[0]].height > rects[a[1]].height && 
      rects[a[2]].width > rects[a[1]].width) {
    width = max(width, rects[a[0]].width + rects[a[2]].width);
  }
  update(width, height);
}

void search(int l, int a[]) {
  int i;
  if (l < 0) {
    check(a);
  }
  for (i = 0; i <= l; i++) {
    swap(a+i, a+l);
    search(l - 1, a);
    swap(&rects[l].width, &rects[l].height);
    search(l - 1, a);
    swap(&rects[l].width, &rects[l].height);
    swap(a+i, a+l);
  }
}

int main() {
  int i, w, h, a[4] = {0, 1, 2, 3};
  freopen("packrec.in", "r", stdin);
  freopen("packrec.out", "w", stdout);
  for (i = 0; i < 4; i++) {
    scanf("%d%d", &rects[i].width, &rects[i].height);
  }
  search(3, a);
  qsort(ans, ai, sizeof(int), cmp);
  printf("%d\n", r);
  for (i = 0; i < ai; i++) {
    printf("%d %d\n", ans[i], r / ans[i]);
  }
  return 0;
}
