/*
ID: wind1900
LANG: C
TASK: namenum
*/
#include <stdio.h>
#include <string.h>

typedef struct{
  char s[20];
  long long id;
} word;

long long sid(char s[]) {
  int i, j;
  long long r = 0;
  for (i = 0; i < strlen(s); i++) {
    switch (s[i]) {
    case 'A':
    case 'B':
    case 'C':
      j = 2;
      break;
    case 'D':
    case 'E':
    case 'F':
      j = 3;
      break;
    case 'G':
    case 'H':
    case 'I':
      j = 4;
      break;
    case 'J':
    case 'K':
    case 'L':
      j = 5;
      break;
    case 'M':
    case 'N':
    case 'O':
      j = 6;
      break;
    case 'P':
    case 'R':
    case 'S':
      j = 7;
      break;
    case 'T':
    case 'U':
    case 'V':
      j = 8;
      break;
    case 'W':
    case 'X':
    case 'Y':
      j = 9;
      break;
    default:
      return -1;
    }
    r = r * 10 + j;
  }
  return r;
}

int main() {
  word w[5000];
  char t[20];
  int wi = 0, i, none = 1;
  long long id;
  //FILE *in = fopen("namenumdict.txt", "r");
  FILE *in = fopen("dict.txt", "r");
  freopen("namenum.in", "r", stdin);
  freopen("namenum.out", "w", stdout);
  while ((fscanf(in, "%s", t)) != EOF) {
    id = sid(t);
    if (id > 0) {
      strcpy(w[wi].s, t);
      w[wi].id = id;
      wi++;
    }
  }
  scanf("%lld", &id);
  for (i = 0; i < wi; i++) {
    if (w[i].id == id) {
      printf("%s\n", w[i].s);
      none = 0;
    }
  }
  if (none) {
    printf("NONE\n");
  }
  return 0;
}
