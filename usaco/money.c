/*
  ID: wind1900
  LANG: C
  TASK: money
*/
#include <stdio.h>

int main() {
  int V, N, i, j, k, m[25];
  long long r[10001] = {1};
  freopen("money.in", "r", stdin);
  freopen("money.out", "w", stdout);
  scanf("%d%d", &V, &N);
  for (i = 0; i < V; i++) {
    scanf("%d", m + i);
  }
  for (i = 0; i < V; i++) {
    for (j = N; j > 0; j--) {
      for (k = m[i]; k <= j; k += m[i]) {
	r[j] += r[j - k];
      }
    }
  }
  printf("%lld\n", r[N]);
  return 0;
}
