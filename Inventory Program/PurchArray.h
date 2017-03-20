#ifndef PURCHARRAY_H
#define PURCHARRAY_H

#include "Purchase.h"
#include "defs.h"

class PurchArray{
  public:
    PurchArray();
    ~PurchArray();
    void add(int, int); //purpose: add a purchase into the purchase array
    Purchase* get(int); //purpose: get a purchase from the purchase array 
    int getSize();      //purpose: get the size of the purchase array
  private:
    Purchase* elements[MAX_ARR];
    int size;
};

#endif
