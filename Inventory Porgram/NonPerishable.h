#ifndef NONPERISHABLE_H
#define NONPERISHABLE_H

#include "ExpirationBehaviour.h"

class NonPerishable : public ExpirationBehaviour{
  public:
    NonPerishable();
    virtual Date computeExpDate(Date, int);  //purpose: computes and sets the product’s expiry date
};
#endif
