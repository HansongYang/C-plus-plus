#include "Meat.h"

Meat::Meat(string n, string s, int u, float p, int y, int m, int d, int l): Product(n,s,u,p,y,m,d,l){
  exp = new Perishable;
  tax = new NonTaxable;
  computeExpDate();
}

Meat::~Meat(){
  delete exp;
  delete tax;
}
