/*
  ID: wind1900
  LANG: C
  TASK: beads
*/
#include <stdio.h>
int main() {
  char s[700], c;
  int n, i, redStart, blueStart, white, r;
  int red, blue;
  freopen("beads.in", "r", stdin);
  freopen("beads.out", "w", stdout);
  scanf("%d", &n);
  scanf("%s", s);
  for (i = 0; i < n; i++) {
    s[i + n] = s[i];
  }
  red = blue = 0;
  redStart = blueStart = white = r = 0;
  for (i = 0; i < 2 * n; i++) {
    switch (s[i]) {
    case 'w':
      white++;
      redStart++;
      blueStart++;
      break;
    case 'r':
      if (blue) {
	r = r > redStart ? r : redStart;
	redStart = white;
	blue = 0;
      }
      redStart++;
      blueStart++;
      red = 1;
      white = 0;
      break;
    case 'b':
      if (red) {
	r = r > blueStart ? r : blueStart;
	blueStart = white;
	red = 0;
      }
      redStart++;
      blueStart++;
      blue = 1;
      white = 0;
      break;
    }
  }
  r = r > blueStart ? r : blueStart;
  r = r > redStart ? r : redStart;
  r = r < n ? r : n;
  printf("%d\n", r);
  return 0;
  /*char s[701], c;
    int n, i, j, k, rbi, wi, r;
    int rb[701] = {0}, w[500] = {0};
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    scanf("%d", &n);
    scanf("%s", s);
    for (i = 0; i < n; i++) {
    s[n + i] = s[i];
    }
    s[n + i] = 0;
    i = rbi = wi = 0;
    while (i < 2 * n && s[i] == 'w') i++;
    w[wi++] = i;
    while (i < 2 * n) {
    c = s[i];
    j = i;
    while (i < 2 * n && s[i] == c) i++;
    k = i;
    while (k < 2 * n) {
    while (k < 2 * n && s[k] == 'w') k++;
    if (k >= 2 * n) break;
    if (s[k] == c) {
    while (k < 2 * n && s[k] == c) k++;
    i = k;
    } else {
    break;
    }
    }
    rb[rbi++] = i - j;
    w[wi++] = k - i;
    i = k;
    }
    r = 0;
    for (i = 0; i < wi; i++) {
    j = w[i] + w[i + 1] + w[i + 2] + rb[i] + rb[i + 1];
    r = j > r ? j : r;
    }
    r = r < n ? r : n;
    printf("%d\n", r);
    return 0;*/
}
