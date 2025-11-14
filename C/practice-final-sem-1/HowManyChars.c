#include <stdio.h>
#include <string.h>

void solve(char b, char a[], int len) {
  int i, ans = 0;
  for (i = 0; i < len; i++) {
    if (a[i] == b) {
      ans++;
    }
  }
  printf("%d\n", ans);
}

int main() {

  char input[20][20], target;
  int i, n, size;

  scanf("%c %d", &target, &n);

  for (i = 0; i < n; i++) {
    scanf("%s", input[i]);
  }

  for (i = 0; i < n; i++) {
    size = strlen(input[i]);
    solve(target, input[i], size);
  }

  return 0;
}
