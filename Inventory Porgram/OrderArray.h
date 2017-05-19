#ifndef ORDERARRAY_H
#define ORDERARRAY_H

#include "Order.h"
#include "defs.h"

class OrderArray{
  public:
    OrderArray();
    void add(Order*);    //purpose: add an new order into the array
    int getSize();       //purpose: get the size of the array
    Order* get(int);     //purpose: get an order form the array
  private:
    Order* elements[MAX_ARR];
    int size;
};
#endif
