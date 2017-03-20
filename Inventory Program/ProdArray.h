#ifndef PRODARRAY_H
#define PRODARRAY_H

#include "defs.h"
#include "Product.h"

class ProdArray
{
  public:
    ProdArray();
    ~ProdArray();
    void add(Product*); //purpose: add a new product into the product array
    Product* get(int);  //purpose: get a product from the product array
    int getSize();      //purpose: get the size of the product array
  private:
    Product* elements[MAX_ARR];
    int size;
};

#endif

