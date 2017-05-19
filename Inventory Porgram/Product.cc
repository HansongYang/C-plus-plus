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

#include "Product.h"

int Product::nextProdId = 5001;

Product::Product(string n, string s, int u, float p, int y, int m, int d, int l)
{ 
  id    = nextProdId++;
  name  = n;
  size  = s;
  units = (u >= 0) ? u : 0;
  price = (p >= 0) ? p : 0;
  manufacturedDate.setYear(y);
  manufacturedDate.setMonth(m);
  manufacturedDate.setDay(d);
  lifespan = l;
  exp = NULL;
  tax = NULL;
}

Product::~Product(){
}

int    Product::getId()        { return id;    }
string Product::getName()      { return name;  }
string Product::getSize()      { return size;  }
int    Product::getUnits()     { return units; }
float  Product::getPrice()     { return price; }
void   Product::setUnits(int u){ units = u;} 
Date   Product::getExpiryDate(){ return expiryDate;}

void   Product::computeExpDate(){
  expiryDate = exp->computeExpDate(manufacturedDate, lifespan);
}

float  Product::computeTax(){
  float t = tax->computeTax(price);
  return t;
}
