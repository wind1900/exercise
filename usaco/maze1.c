/*
  ID: wind1900
  LANG: C
  TASK: maze1
*/
#include <stdio.h>

int q[4000], qs, qe, r[4000];
int w, h;

void add(int i) {
  q[qe++] = i;
}

int del() {
  return q[qs++];
}

int empty() {
  return qs == qe;
}

int parse(int i, int j) {
  return i / 2 * w + j / 2;
}

int main() {
  char m[201][78], c;
  int i, j, k, ii, jj;
  freopen("maze1.in", "r", stdin);
  freopen("maze1.out", "w", stdout);
  scanf("%d%d", &w, &h);
  getchar();
  for (i = 0; i < 2 * h + 1; i++) {
    j = 0;
    while ((c = getchar()) != '\n') {
      m[i][j++] = c;
    }
    if (m[i][0] == ' ') {
      add(parse(i, 1));
      r[parse(i, 1)] = 1;
    }
    if (m[i][2 * w] == ' ') {
      add(parse(i, 2 * w - 1));
      r[parse(i, 2 * w - 1)] = 1;
    }
  }
  for (i = 0; i < 2 * w + 1; i++) {
    if (m[0][i] == ' ') {
      add(parse(1, i));
      r[parse(1, i)] = 1;
    }
    if (m[2 * h][i] == ' ') {
      add(parse(2 * h - 1,i));
      r[parse(2 * h - 1, i)] = 1; 
    }
  }
  while (!empty()) {
    k = del();
    j = k % w;
    i = k / w;
    ii = 2 * i + 1;
    jj = 2 * j + 1;
    if (i < h - 1 && m[ii+1][jj] != '-') {
      if (!r[(i + 1) * w + j]) {
	add((i + 1) * w + j);
	r[(i + 1) * w + j] = r[k] + 1;
      }
    }
    if (i > 0 && m[ii-1][jj] != '-') {
      if (!r[(i - 1) * w + j]) {
	add((i - 1) * w + j);
	r[(i - 1) * w + j] = r[k] + 1;
      }
    }
    if (j < w - 1 && m[ii][jj+1] != '|') {
      if (!r[i * w + j + 1]) {
	add(i * w + j + 1);
	r[i * w + j + 1] = r[k] + 1;
      }
    }
    if (j > 0 && m[ii][jj-1] != '|') {
      if (!r[i * w + j - 1]) {
	add(i * w + j - 1);
	r[i * w + j - 1] = r[k] + 1;
      }
    }
  }
  for (i = 0, k = 0; i < w * h; i++) {
    k = k > r[i] ? k : r[i];
  }
  printf("%d\n", k);
  return 0;
}
