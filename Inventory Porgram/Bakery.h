#ifndef BAKERY_H
#define BAKERY_H

#include "Product.h"

class Bakery : public Product{
  public:
    Bakery(string="Unknown", string="Unknown", int=0, float=0.0f, int=0, int=0, int=0, int=0);
    ~Bakery();
};
#endif
