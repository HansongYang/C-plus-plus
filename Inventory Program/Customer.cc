
#include <cmath>
#include "Customer.h"

int Customer::nextCustId = 2001;

Customer::Customer(string n)
{ 
  id     = nextCustId++;
  name   = n;
  points = 0;
}

int    Customer::getId()     { return id;     }
string Customer::getName()   { return name;   }
int    Customer::getPoints() { return points; }
void   Customer::setPoints(int p) { points += p;}
PurchArray* Customer::getArray()  { return &elements;}

