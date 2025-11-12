#include <stdio.h>

int parity = 0;

void draw() {
  if (parity == 0) {
    printf("@");
    parity = 1;
  } else {
    printf("#");
    parity = 0;
  }
}

int main() {

  int r, c, i, j;

  scanf("%d", &r);
  scanf("%d", &c);

  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      draw();
    }
    printf("\n");
    parity = 0;
  }

  return 0;
}
