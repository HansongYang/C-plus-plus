#define STORE_H

#include "ProdList.h"
#include "Customer.h"
#include "Bakery.h"
#include "CoffeeTea.h"
#include "Meat.h"
#include "Dairy.h"
#include "MiscGoods.h"
#include <list>

class Store
{
  public:
    ~Store();
    void             addProd(Product*);  //purpose: add a product into the product array
    void             addCust(Customer*); //purpose: add a customer into the customer array
    ProdList*        getList();          //purpose: get the product array
    list<Customer*>& getCustomers();     //purpose: get the customer STL list
    Customer*        getCustomer(int);   //purpose: get a customer by index from the customer template
    Customer*        IDget(int);         //purpose: get a customer by id from the customer template
  private:
    ProdList        prodList;
    list<Customer*> custList;
};

#endif
