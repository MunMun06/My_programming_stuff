#include <iostream>

int main() {

  FILE *fp;
  char name[10];
  int age;

  fp = fopen("myfile.txt", "r");
  fscanf(fp, "%s %d", name, &age);
  std::cout << name << " " << age;
  fclose(fp);

  return 0;
}
