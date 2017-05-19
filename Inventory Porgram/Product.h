#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;
#include "Date.h"
#include "TaxationBehaviour.h"
#include "ExpirationBehaviour.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include "Taxable.h"
#include "NonTaxable.h"

class Product
{
  public:
    Product(string="Unknown", string="Unknown", int=0, float=0.0f, int=0, int=0, int=0, int=0);
    virtual ~Product();
    int     getId();            //purpose: get the product's id
    string  getName();          //purpose: get the product's name
    string  getSize();          //purpose: get the product's size
    int     getUnits();         //purpose: get the product's units
    float   getPrice();         //purpose: get the product's price
    void    setUnits(int);      //purpose: set the units of a product
    float   computeTax();       //purpose: returns the amount of tax to be paid on the product
    void    computeExpDate();   //purpose: computes and sets the product’s expiry date 
    Date    getExpiryDate();    //purpose: get the expiry date
  protected:
    static int nextProdId;
    int        id;
    string     name;
    string     size;
    int        units;
    float      price;
    Date       manufacturedDate;
    Date       expiryDate;
    int        lifespan;
    TaxationBehaviour*   tax;
    ExpirationBehaviour* exp;
};

#endif
