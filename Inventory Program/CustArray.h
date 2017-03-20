#ifndef CUSTARRAY_H
#define CUSTARRAY_H

#include "defs.h"
#include "Customer.h"

class CustArray
{
  public:
    CustArray();
    ~CustArray();
    void add(Customer*);  //purpose: add a new customer into the customer array.
    Customer* get(int);   //purpose: get a customer by index from the customer array.
    Customer* IDget(int); //purpose: get a customer by id from the customer array.
    int getSize();        //purpose: get the size of customer array.
  private:
    Customer* elements[MAX_ARR];
    int size;
};

#endif

