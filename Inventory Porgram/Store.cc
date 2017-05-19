#include "Store.h"

Store::~Store(){
  list<Customer*>::iterator itr;
  for ( itr  = custList.begin();
        itr != custList.end();
        ++itr) {
    delete (*itr);
  } 
}

ProdList*  Store::getList()     { return &prodList; }

list<Customer*>& Store::getCustomers() { return custList; }

void Store::addProd(Product* prod)
{
  prodList.add(prod);
}

void Store::addCust(Customer* cust)
{
  custList.push_back(cust);
}


Customer* Store::getCustomer(int index)
{
  int i = 0;
  list<Customer*>::iterator itr;
  for ( itr  = custList.begin();
        itr != custList.end();
        ++itr) {
   if(index == i){
     break;
   }
   i++;
  }
  return *itr;
}

Customer* Store::IDget(int id){
  list<Customer*>::iterator itr;
  for ( itr  = custList.begin();
        itr != custList.end();
        ++itr) {
    if(id == (*itr)->getId()){
      break;
    }
  }
  return *itr;
}
