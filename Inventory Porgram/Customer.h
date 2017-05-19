#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

#include "Product.h"
#include "PurchArray.h"

class Customer
{
  public:
    Customer(string="Unknown");
    int    getId();         //purpose: get the customer's id
    string getName();       //purpose: get the customer's name
    int    getPoints();     //purpose: get the customer's loyalty points
    void   setPoints(int);  //purpose: set the customer's loyalty points
    PurchArray* getArray(); //purpose: get the purchase array
  protected:
    static int nextCustId;
    int        id;
    string     name;
    int        points;
  private:
    PurchArray elements;
};

#endif
