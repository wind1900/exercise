/*
  ID: wind1900
  LANG: C
  TASK: ride
*/
#include <stdio.h>
int main() {
  char c1[10], c2[10];
  int i, a = 1, b = 1;
  FILE *fin = fopen("ride.in", "r");
  FILE *fout = fopen("ride.out", "w");
  fscanf(fin, "%s", c1);
  fscanf(fin, "%s", c2);
  for (i = 0; c1[i]; i++) {
    a = a * (c1[i] -'A' + 1);
    a = a % 47;
  }
  for (i = 0; c2[i]; i++) {
    b = b * (c2[i] - 'A' + 1);
    b = b % 47;
  }
  if (a == b) {
    fprintf(fout, "GO\n");
  } else {
    fprintf(fout, "STAY\n");
  }
  return 0;
}
