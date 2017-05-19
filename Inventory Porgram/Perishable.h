#ifndef PERISHABLE_H
#define PERISHABLE_H

#include "ExpirationBehaviour.h"

class Perishable : public ExpirationBehaviour{
  public:
    Perishable();
    virtual Date computeExpDate(Date, int);  //purpose: computes and sets the product’s expiry date
};
#endif
