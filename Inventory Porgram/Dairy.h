#ifndef DAIRY_H
#define DAIRY_H

#include "Product.h"

class Dairy : public Product{
  public:
    Dairy(string="Unknown", string="Unknown", int=0, float=0.0f, int=0, int=0, int=0, int=0);
    ~Dairy();
};
#endif
