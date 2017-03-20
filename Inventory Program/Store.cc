
#include "Store.h"

ProdArray* Store::getStock()     { return &stock; }

CustArray* Store::getCustomers() { return &customers; }

void Store::addProd(Product* prod)
{
  stock.add(prod);
}

void Store::addCust(Customer* cust)
{
  customers.add(cust);
}

