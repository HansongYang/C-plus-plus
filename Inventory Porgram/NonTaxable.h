#ifndef NONTAXABLE_H
#define NONTAXABLE_H

#include "TaxationBehaviour.h"

class NonTaxable : public TaxationBehaviour{
  public:
    NonTaxable();
    virtual float  computeTax(float);  //purpose: returns the amount of tax to be paid on the product
};
#endif
