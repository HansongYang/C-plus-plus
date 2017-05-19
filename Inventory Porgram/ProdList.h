#ifndef PRODLIST_H
#define PRODLIST_H

#include <string>
#include <sstream>
#include <iomanip>
#include "Product.h"

class ProdList
{
  class Node 
  {
    friend class ProdList;
    private:
      Product* prodData;
      Node*    next;
      Node*    prev;
  };

  public:
    ProdList();
    ~ProdList();
    void      add(Product*);       //purpose: add a new product in the linked list
    void      remove(int);         //purpose: remove the corresponding product from in the linked list
    void      reorg(int);          //purpose: sorts the product list in ascending order of number of units
    Product*  find(int);           //purpose: use id to find a product
    void      toString(string&);   //purpose: concatenate all the product data formatted into one long string
  private:
    Node* head;
};

#endif
