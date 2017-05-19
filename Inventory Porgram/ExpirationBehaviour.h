#ifndef EXPIRATIONBEHAVIOUR_H
#define EXPIRATIONBEHAVIOUR_H

#include "Date.h"

class ExpirationBehaviour{
  public:
    ExpirationBehaviour();
    virtual ~ExpirationBehaviour();
    virtual Date computeExpDate(Date, int)=0; //purpose: computes and sets the product’s expiry date
};

#endif
