#include "Bakery.h"

Bakery::Bakery(string n, string s, int u, float p, int y, int m, int d, int l): Product(n,s,u,p,y,m,d,l){
  exp = new Perishable;
  tax = new Taxable;
  computeExpDate();
} 

Bakery::~Bakery(){
  delete exp;
  delete tax;
}
