/*
  ID: wind1900
  LANG: C
  TASK: prefix
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct n* np;

typedef struct n {
  char c;
  char v;
  np next;
  np child;
} node;

node root;

void add(char *s) {
  np p = &root, q = p->child, r;
  while (*s) {
    while (q && q->c != *s) {
      q = q -> next;
    }
    if (!q) {
      r = (np) malloc(sizeof(node));
      r->c = *s;
      r->v = 0;
      r->child = NULL;
      r->next = p->child;
      p->child = r;
      q = r;
    }
    p = q;
    q = q -> child;
    s++;
  }
  p->v = 1;
}

void update(char *s, char *p) {
  np q = root.child;
  while (*s) {
    while (q && q->c != *s) {
      q = q -> next;
    }
    if (!q) return;
    if (q->v) *p = 1;
    q = q -> child;
    s++;
    p++;
  }
}

int main() {
  char p[200001] = {1}, str[200001], t[11], c;
  int l = 0, i;
  freopen("prefix.in", "r", stdin);
  freopen("prefix.out", "w", stdout);
  scanf("%s", t);
  while (t[0] != '.') {
    add(t);
    scanf("%s", t);
  }
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\r') continue;
    str[l++] = c;
  }
  for (i = 0; i <= l; i++) {
    if (p[i]) {
      update(str + i, p + i + 1);
    }
  }
  for (i = l; i >= 0; i--) {
    if (p[i]) break;
  }
  printf("%d\n", i);
  return 0;
}
