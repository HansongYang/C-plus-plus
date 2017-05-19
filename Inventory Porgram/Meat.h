#ifndef MEAT_H
#define MEAT_H

#include "Product.h"

class Meat : public Product{
  public:
    Meat(string="Unknown", string="Unknown", int=0, float=0.0f, int=0, int=0, int=0, int=0);
    ~Meat();
};
#endif
