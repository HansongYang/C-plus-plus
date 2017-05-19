#ifndef ORDER_H
#define ORDER_H

#include "Customer.h"
#include "PurchArray.h"

class Order{
  public:
    Order();
    int  getId();		 //purpose: get the order's id
    float  getTotalPrices();     //purpose: get the total prices of that order
    void setTotalPrices(float);  //purpose: set the total prices of that order
    void setCustomer(Customer*); //purpose: set the customer
    PurchArray* getArray();      //purpose: get the purchase array
    Customer*   getCustomer();   //purpose: get the customer
  protected:
    static int nextOrderId;
    int        id;
    float      totalPrices;
  private:
    Customer   *cust;
    PurchArray purcharray;
};
#endif
