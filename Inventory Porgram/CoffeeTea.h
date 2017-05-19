#ifndef COFFEETEA_H
#define COFFEETEA_H

#include "Product.h" 

class CoffeeTea : public Product{
  public:
    CoffeeTea(string="Unknown", string="Unknown", int=0, float=0.0f, int=0, int=0, int=0, int=0);
    ~CoffeeTea();
};
#endif
