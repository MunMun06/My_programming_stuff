#include <stdio.h>
#include <string.h>

int main() {

  char input[27];
  int list[27] = {[0 ... 26] = 0}, i, mode = 0;

  scanf("%s", input);

  for (i = 0; i < strlen(input); i++) {
    int temp = (int)input[i];
    list[temp - 65]++;
  }

  for (i = 0; i < strlen(input); i++) {
    if (list[i] == 0) {
      mode = 1;
    } else if (list[i] > 1) {
      mode = 1;
    }
  }

  switch (mode) {
  case 0:
    printf("NO MISSING\n");
    break;
  case 1:
    for (i = 0; i < strlen(input); i++) {
      if (list[i] > 1) {
        printf("%c", 'A' + i);
      }
    }

    printf("\n");

    for (i = 0; i < strlen(input); i++) {
      if (list[i] == 0) {
        printf("%c", 'A' + i);
      }
    }
    printf("\n");
  }

  return 0;
}
