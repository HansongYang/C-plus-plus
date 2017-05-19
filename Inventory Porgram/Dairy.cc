#include "Dairy.h"

Dairy::Dairy(string n, string s, int u, float p, int y, int m, int d, int l): Product(n,s,u,p,y,m,d,l){
  exp = new Perishable;
  tax = new NonTaxable;
  computeExpDate();
}

Dairy::~Dairy(){
  delete exp;
  delete tax;
}
