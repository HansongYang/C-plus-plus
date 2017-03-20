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

#ifndef CUSTARRAY_H
#define CUSTARRAY_H

#include "defs.h"
#include "Customer.h"

class CustArray
{
  public:
    CustArray();
    ~CustArray();
    void add(Customer*);  //purpose: add a new customer into the customer array.
    Customer* get(int);   //purpose: get a customer by index from the customer array.
    Customer* IDget(int); //purpose: get a customer by id from the customer array.
    int getSize();        //purpose: get the size of customer array.
  private:
    Customer* elements[MAX_ARR];
    int size;
};

#endif

