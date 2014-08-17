/*
  ID: wind1900
  LANG: C
  TASK: lamps
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  The light pattern repeats every six lamps...
 */

int n, c;
int on[100], off[100], oni = 0, offi = 0;
char ans[8][13], ai = 0;

int get(char l[], int i) {
  int a, b;
  a = i / 8;
  b = 7 - i % 8;
  return (l[a] & (1 << b));
}

void trans(char l[], int b) {
  int i, j, len = n / 8 + 1;
  int b4[3] = {0x92, 0x49, 0x24};
  if (b & 1) {
    for (i = 0; i < len; i++) {
      l[i] = l[i] ^ 0xFF;
    }
  }
  if (b & 2) {
    for (i = 0; i < len; i++) {
      l[i] = l[i] ^ 0xAA;
    }
  }
  if (b & 4) {
    for (i = 0; i < len; i++) {
      l[i] = l[i] ^ 0x55;
    }
  }
  if (b & 8) {
    for (i = 0, j = 0; i < len; i++) {
      l[i] = l[i] ^ b4[j];
      j++;
      if (j == 3) j = 0;
    }
  }
}

int valid(char l[], int b) {
  int s = 0, i;
  for (i = 1; i < 16; i = i << 1) {
    if (b & i) s++;
  }
  if (s > c || ((c - s) & 1)) return 0;
  for (i = 0; i < oni; i++) {
    if (!get(l, on[i] - 1)) return 0;
  }
  for (i = 0; i < offi; i++) {
    if (get(l, off[i] - 1)) return 0;
  }
  return 1;
}

int cmp(const void* a, const void* b) {
  char *i, *j;
  int k, ii, jj;
  i = (char*) a;
  j = (char*) b;
  for (k = 0; k < n; k++) {
    ii = get(i, k);
    jj = get(j, k);
    if (ii && !jj) return 1;
    if (!ii && jj) return -1;
  }
}

int main() {
  char l[13];
  int i, j;
  freopen("lamps.in", "r", stdin);
  freopen("lamps.out", "w", stdout);
  scanf("%d%d", &n, &c);
  scanf("%d", &i);
  while (i != -1) {
    on[oni++] = i;
    scanf("%d", &i);
  }
  scanf("%d", &i);
  while (i != -1) {
    off[offi++] = i;
    scanf("%d", &i);
  }
  for (i = 0; i < 16; i++) {
    memset(l, 0xFF, sizeof(l));
    trans(l, i);
    if (valid(l, i)) {
      strcpy(ans[ai], l);
      ai++;
    }
  }
  if (ai == 0) {
    printf("IMPOSSIBLE\n");
    return 0;
  }
  qsort(ans, ai, sizeof(ans[0]), cmp);
  for (i = 0; i < ai; i++) {
    for (j = 0; j < n; j++) {
      printf("%c", get(ans[i], j) ? '1' : '0');
    }
    printf("\n");
  }
  return 0;
}
