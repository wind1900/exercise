/*
  ID: wind1900
  LANG: C
  TASK: ttwo
*/
#include <stdio.h>

enum direction {NORTH, SOUTH, EAST, WEST};

typedef struct {
  int i, j;
  int d;
} mov;

int main() {
  mov mo[2];
  int i, j, k, l, o = 0;
  char m[11][11], c;
  mo[0].d = NORTH;
  mo[1].d = NORTH;
  freopen("ttwo.in", "r", stdin);
  freopen("ttwo.out", "w", stdout);
  for (i = 0; i < 10; i++) {
    scanf("%s", m[i]);
  }
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      switch (m[i][j]) {
      case '*':
	o++;
	break;
      case 'F':
	mo[0].i = i;
	mo[0].j = j;
	break;
      case 'C':
	mo[1].i = i;
	mo[1].j = j;
	break;
      }
    }
  }
  for (k = 0; k < 400 * 400; k++) {
    for (l = 0; l < 2; l++) {
      switch(mo[l].d) {
      case NORTH:
	if (mo[l].i == 0 || m[mo[l].i - 1][mo[l].j] == '*') {
	  mo[l].d = EAST;
	} else {
	  mo[l].i--;
	}
	break;
      case SOUTH:
	if (mo[l].i == 9 || m[mo[l].i + 1][mo[l].j] == '*') {
	  mo[l].d = WEST;
	} else {
	  mo[l].i++;
	}
	break;
      case EAST:
	if (mo[l].j == 9 || m[mo[l].i][mo[l].j + 1] == '*') {
	  mo[l].d = SOUTH;
	} else {
	  mo[l].j++;
	}
	break;
      case WEST:
	if (mo[l].j == 0 || m[mo[l].i][mo[l].j - 1] == '*') {
	  mo[l].d = NORTH;
	} else {
	  mo[l].j--;
	}
	break;
      }
    }
    if (mo[0].i == mo[1].i && mo[0].j == mo[1].j) {
      break;
    }
  }
  if (k == 400 * 400) {
    printf("0\n");
  } else {
    printf("%d\n", k + 1);
  }
  return 0;
}
