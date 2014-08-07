/*
  ID: wind1900
  LANG: C
  TASK: gift1
*/
#include <stdio.h>
#include <string.h>

int findGroup(char names[][15], char name[]) {
  int i = 0;
  while (strcmp(names[i], name) != 0) {
    i++;
  }
  return i;
}

int main() {
  FILE *fin = fopen("gift1.in", "r");
  FILE *fout = fopen("gift1.out", "w");
  int np, i, t, d;
  int money[10] = {0};
  char names[10][15];
  char name[15];
  fscanf(fin, "%d", &np);
  for (i = 0; i < np; i++) {
    fscanf(fin, "%s", names[i]);
  }
  while (fscanf(fin, "%s", name) != EOF) {
    fscanf(fin, "%d%d", &t, &d);
    if (t == 0) continue;
    money[findGroup(names, name)] -= t / d * d;
    for (i = 0; i < d; i++) {
      fscanf(fin, "%s", name);
      money[findGroup(names, name)] += t / d;
    }
  }
  for (i = 0; i < np; i++) {
    fprintf(fout, "%s %d\n", names[i], money[i]);
  }
  return 0;
}
