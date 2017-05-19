#ifndef ORDERSERVER_H
#define ORDERSERVER_H

#include "OrderArray.h"
#include "defs.h"

class OrderServer{
  public: 
    OrderServer();
    ~OrderServer();
    void update(Order*);        //purpose: adds a new order to the order server’s collection
    void retrieve(OrderArray&); //purpose: retrieve all the orders and print to the screen
  private:
    OrderArray elements;
};
#endif
