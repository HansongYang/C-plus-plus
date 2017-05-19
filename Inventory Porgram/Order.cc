#include "Order.h"

int Order::nextOrderId = 1001;

Order::Order(){
   id = nextOrderId++;
   totalPrices = 0;
}

int  Order::getId()                 { return id;}
float  Order::getTotalPrices()      { return totalPrices;}
void Order::setTotalPrices(float m) { totalPrices = m;}
PurchArray* Order::getArray()       { return &purcharray;}
void Order::setCustomer(Customer* c){ cust = c;}
Customer*   Order::getCustomer()    { return cust;}
