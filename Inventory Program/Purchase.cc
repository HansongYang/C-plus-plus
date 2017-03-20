#include "Purchase.h"

Purchase::Purchase(int n, int i){
  numOfUnits = n;
  id = i;
}

void Purchase::setnumOfUnits(int n) {numOfUnits = n;}
int Purchase::getId()         {return id;}
int Purchase::getnumOfUnits() {return numOfUnits;}
