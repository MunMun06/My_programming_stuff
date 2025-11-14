#include <stdio.h>
#include <string.h>

int is_vowel(char a) {
  switch (a) {
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
    return 1;
  default:
    return 0;
  }
}

int main() {

  int i, n, normal = 0, special = 0;
  char input[1001];

  scanf("%s", input);

  n = strlen(input);

  if (is_vowel(input[0]) == 1) {
    special++;
  }
  normal++;

  for (i = 1; i < n; i++) {
    if (input[i] == '_') {
      normal++;
      if (is_vowel(input[i + 1]) == 1) {
        special++;
      }
    }
  }

  printf("%d %d\n", normal, special);
  return 0;
}
