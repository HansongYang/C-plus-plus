#ifndef UI_H
#define UI_H

#include <string>
using namespace std;
#include <list>

#include "ProdList.h"
#include "OrderArray.h"

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
    void printOrders(OrderArray*);      //purpose: print the order array
    void printStock(ProdList*);	        //purpose: print the product Linked List
    void printCustomers(list<Customer*>&);//purpose: print the customer STL list
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
