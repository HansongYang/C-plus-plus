#ifndef TAXABLE_H
#define TAXABLE_H

#include "TaxationBehaviour.h"

class Taxable : public TaxationBehaviour{
  public:
    Taxable();
    virtual float computeTax(float);  //purpose: returns the amount of tax to be paid on the product
  private:
    float taxRate;
};
#endif
