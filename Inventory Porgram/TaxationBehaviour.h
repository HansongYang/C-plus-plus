#ifndef TAXATIONBEHAVIOUR_H
#define TAXATIONBEHAVIOUR_H

class TaxationBehaviour{
  public:
    TaxationBehaviour();
    virtual ~TaxationBehaviour();
    virtual float computeTax(float)=0;  //purpose: returns the amount of tax to be paid on the product
};

#endif
