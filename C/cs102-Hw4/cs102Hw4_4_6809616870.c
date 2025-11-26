#include <stdio.h>

struct myGoodsREc {
  int ID;
  char name[20];
  char type;
  float cost;
  float tax;
  float netPrice;
};

typedef struct myGoodsREc Goods;

float findTax(Goods a) {
  float ans;
  switch (a.type) {
  case 'A':
    ans = a.cost * 0.1;
    break;
  case 'B':
    ans = a.cost * 0.15;
    break;
  case 'C':
    ans = a.cost * 0.2;
    break;
  case 'D':
    ans = a.cost * 0.4;
    break;
  default:
    break;
  }
  return ans;
}
int main() {

  int i = 0, j;

  Goods myGoods[100];

  FILE *fp = fopen("Goods.txt", "r");
  FILE *fo = fopen("Report6809616870.txt", "w");

  if (!fp) {
    printf("Cannot open goods.txt\n");
    return 1;
  }
  if (!fo) {
    printf("Cannot open report\n");
    return 1;
  }

  while (fscanf(fp, "%d %s %c %f", &myGoods[i].ID, myGoods[i].name,
                &myGoods[i].type, &myGoods[i].cost) == 4) {

    i++;
  }

  for (j = 0; j < i; j++) {
    myGoods[j].tax = findTax(myGoods[j]);
    myGoods[j].netPrice = myGoods[j].cost + myGoods[j].tax;
  }

  fprintf(fo,
          "ID    Name              Type    Cost       Tax        NetPrice\n");
  for (j = 0; j < i; j++) {
    fprintf(fo, "%-6d%-18s%-8c%-11.2f%-11.2f%-11.2f\n", myGoods[j].ID,
            myGoods[j].name, myGoods[j].type, myGoods[j].cost, myGoods[j].tax,
            myGoods[j].netPrice);
  }

  return 0;
}
