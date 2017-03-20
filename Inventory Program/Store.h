/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef STORE_H
#define STORE_H

#include "ProdArray.h"
#include "Product.h"
#include "CustArray.h"
#include "Customer.h"

class Store
{
  public:
    void       addProd(Product*);  //purpose: add a product into the product array
    void       addCust(Customer*); //purpose: add a customer into the customer array
    ProdArray* getStock();         //purpose: get the product array
    CustArray* getCustomers();     //purpose: get the customer array
  private:
    ProdArray  stock;
    CustArray  customers;
};

#endif
