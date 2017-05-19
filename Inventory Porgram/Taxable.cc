#include "Taxable.h"

Taxable::Taxable(){
  taxRate = 0.13f;
}

float Taxable::computeTax(float price){
  float tax = price * taxRate;
  return tax;
}
