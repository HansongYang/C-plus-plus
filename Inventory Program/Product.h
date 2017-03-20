
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product
{
  public:
    Product(string="Unknown", string="Unknown", int=0, float=0.0f);
    int    getId();      //purpose: get the product's id
    string getName();    //purpose: get the product's name
    string getSize();    //purpose: get the product's size
    int    getUnits();   //purpose: get the product's units
    float  getPrice();   //purpose: get the product's price
    void   setUnits(int);//purpose: set the product's units
  protected:
    static int nextProdId;
    int        id;
    string     name;
    string     size;
    int        units;
    float      price;
};

#endif
