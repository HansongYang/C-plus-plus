#include "MiscGoods.h"

MiscGoods::MiscGoods(string n, string s, int u, float p, int y, int m, int d, int l): Product(n,s,u,p,y,m,d,l){
  exp = new NonPerishable;
  tax = new NonTaxable;
  computeExpDate();
}

MiscGoods::~MiscGoods(){
  delete exp;
  delete tax;
}
