#include <stdio.h>

int main() {

  int input[100000] = {0}, i, n, a, b, start, end, foundS = 0, curr, sum = 0;

  scanf("%d %d %d", &n, &a, &b);

  for (i = 0; i < n; i++) {
    scanf("%d", &input[i]);
    if (input[i] == a && foundS == 0) {
      start = i;
      foundS = 1;
      curr = a;
    } else if (input[i] == b) {
      end = i;
      break;
    } else if (input[i] == a + 1) {
      a++;
    }
  }

  if (a == b) {
    for (i = 0; i < end - start; i++) {
      if (input[start + i] == curr) {
        curr++;
      } else {
        sum += input[start + i];
      }
    }
    printf("%d\n", sum);
  } else {
    printf("%d\n", a);
  }

  return 0;
}
