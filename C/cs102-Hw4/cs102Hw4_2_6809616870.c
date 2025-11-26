#include <stdio.h>
#define MAX_STUDENTS 5
#define MAX_NAME_LENGTH 50
typedef struct {
  int id;
  char name[MAX_NAME_LENGTH];
  float score;
} Student;

void inputStudentData(Student a[MAX_STUDENTS]) {
  int i;

  for (i = 0; i < MAX_STUDENTS; i++) {
    printf("Enter student %d's ID: ", i + 1);
    scanf("%d", &a[i].id);

    printf("Enter student %d's name: ", i + 1);
    scanf("%s", a[i].name);

    printf("Enter student %d's score: ", i + 1);
    scanf("%f", &a[i].score);
  }

  printf("*******************************************************\n");
}

void printStudentData(Student a[MAX_STUDENTS]) {
  int i;

  printf("Student Data:\nID\tName\tScore:\n");

  for (i = 0; i < MAX_STUDENTS; i++) {
    printf("%d\t%s\t%.2f\n", a[i].id, a[i].name, a[i].score);
  }
  printf("*******************************************************\n");
}

void findHighestScore(Student a[MAX_STUDENTS]) {
  int i, index;
  float ans = 0;

  for (i = 0; i < MAX_STUDENTS; i++) {
    if (a[i].score > ans) {
      ans = a[i].score;
      index = i;
    }
  }
  printf("Student with the highest score:\n");
  printf("ID: %d  Name: %s  Score: %f\n", a[index].id, a[index].name,
         a[index].score);
  printf("*******************************************************\n");
}
int main() {
  Student students[MAX_STUDENTS];
  inputStudentData(students);
  printStudentData(students);
  findHighestScore(students);
  return 0;
}
