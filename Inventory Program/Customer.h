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

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

#include "Product.h"
#include "PurchArray.h"

class Customer
{
  public:
    Customer(string="Unknown");
    int    getId();         //purpose: get the customer's id
    string getName();       //purpose: get the customer's name
    int    getPoints();     //purpose: get the customer's loyalty points
    void   setPoints(int);  //purpose: set the customer's loyalty points
    PurchArray* getArray(); //purpose: get the purchase array
  protected:
    static int nextCustId;
    int        id;
    string     name;
    int        points;
  private:
    PurchArray elements;
};

#endif
