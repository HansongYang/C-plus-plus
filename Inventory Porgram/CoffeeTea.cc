#include "CoffeeTea.h"

CoffeeTea::CoffeeTea(string n, string s, int u, float p, int y, int m, int d, int l): Product(n,s,u,p,y,m,d,l){
  tax = new Taxable;
  exp = new NonPerishable;
  computeExpDate();
}

CoffeeTea::~CoffeeTea(){
  delete exp;
  delete tax;
}
