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

#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

#include "ProdArray.h"
#include "CustArray.h"

class UI
{
  public:
    void adminMenu(int*);		//purpose: display the admin meun
    void cashierMenu(int*);             //purpose: display the cashier menu
    void promptForInt(string, int*);    //purpose: prompt for an integer
    void promptForStr(string, string*); //purpose: prompt for a string
    void promptForFloat(string, float*);//purpose: prompt for a float
    void printError(string);		//purpose: print the error
    void printUsageError();             //purpose: print the usage error
    void printStock(ProdArray*);	//purpose: print the product array
    void printCustomers(CustArray*);    //purpose: print the customer array
    void pause();			//purpose: pause the program
    void promptForCust(int*);		//purpose: prompt the customer id
    void promptForProd(int*);		//purpose: prompt the product id
    void promptForInventory(int*);      //purpose: prompt the number of units of product
    void printTotal(float*, int*);	//purpose: print the total point and total purchase amount
    void printInfo(string);             //purpose: print the information
  private:
    int    readInt();
};

#endif
