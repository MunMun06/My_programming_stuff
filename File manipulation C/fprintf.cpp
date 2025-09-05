#include <iostream>

int main() {

  FILE *fp;
  char name[10] = "Thapanun"; // std::string don't work
  int age = 18;

  fp = fopen("myfile.txt", "w");
  fprintf(fp, "%s %d\n", name, age);
  fclose(fp);

  return 0;
}
