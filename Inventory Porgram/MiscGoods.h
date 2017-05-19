#ifndef MISCGOODS_H
#define MISCGOODS_H

#include "Product.h"

class MiscGoods : public Product{
  public:
    MiscGoods(string="Unknown", string="Unknown", int=0, float=0.0f, int=0, int=0, int=0, int=0);
    ~MiscGoods();
};
#endif
