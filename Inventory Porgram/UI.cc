#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "UI.h"
using namespace std;


void UI::adminMenu(int* choice)
{
  string str;

  *choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM ADMIN MENU\n\n";
  cout<< "          1. Add new product \n\n";
  cout<< "          2. Add more inventory \n\n";
  cout<< "          3. Print inventory \n\n";
  cout<< "          4. Print customers \n\n";
  cout<< "          5. Remove Product  \n\n";
  cout<< "          6. Print Orders    \n\n";
  cout<< "          0. Exit\n\n";

  while (*choice < 0 || *choice > 6) {
    cout << "Enter your selection:  ";
    *choice = readInt();
  }
}

void UI::cashierMenu(int* choice)
{
  string str;

  *choice = -1;

  cout<< "\n\n\n                   INVENTORY MANAGEMENT SYSTEM CASHIER MENU\n\n";
  cout<< "          1. Product purchases\n\n";
  cout<< "          2. Product returns\n\n";
  cout<< "          0. Exit\n\n";

  while (*choice < 0 || *choice > 2) {
    cout << "Enter your selection:  ";
    *choice = readInt();
    if (*choice == MAGIC_NUM) return;
  }
}
void UI::printOrders(OrderArray* arr){
  cout << endl << "Orders: " << endl ;
  for(int i = 0; i < arr->getSize(); i++){
    cout << endl << "ID: " << arr->get(i)->getId() << "  ";

    cout << endl << arr->get(i)->getCustomer()->getName() << "'s orders: " << endl;
    for(int j = 0; j < arr->get(i)->getArray()->getSize(); j++){
      cout << arr->get(i)->getArray()->get(j)->getnumOfUnits() << " Units of product " << arr->get(i)->getArray()->get(j)->getId() << ", ";
    }
    cout << "total dollar amount: " << arr->get(i)->getTotalPrices() << endl;
  }
  cout << endl;
}

void UI::printStock(ProdList* list)
{
  // The stringstream class helps us convert from numeric values to string.
  // The I/O manipulation functions help us make the output look pretty.

  stringstream ss;
  string outStr;
  list->toString(outStr);

  cout << endl << "STOCK: " << endl << endl;
  cout << " ID                                 Name             Size    Qty    Price     Expiry Date" << endl;
  cout << " --                                 ----             ----    ---    -----     -----------" << endl;
  
  for (int i = 0; i < outStr.length(); i++) {
    if(outStr[i] == ','){
      cout << ss.str() << endl;
      ss.str("");
    }
    else{
      ss << outStr[i];
    }
  }
}

void UI::promptForCust(int* custId){
  cout<< "Please enter the id of the customer. Enter 0 to quit." << endl;
  *custId = readInt();

}

void UI::promptForProd(int* prodId){
  cout<< "Please enter the id of the product. Enter 0 to quit." << endl;
  *prodId  = readInt();     

}

void UI::promptForInventory(int* numOfUnits){
  cout<< "Please enter the number of new units that have arrived." << endl;
  *numOfUnits = readInt();
}

void UI::printTotal(float* totalPrices, int* totalPoints){
      cout<< "Total Purchase amount: " << *totalPrices << ", number of points earned: " << *totalPoints << "." << endl;
}

void UI::printInfo(string str){
  cout<< str << endl;
}

void UI::printCustomers(list<Customer*>& custList)
{
  cout << endl << "CUSTOMERS: " << endl << endl;
  list<Customer*>::iterator itr;
 
 for ( itr  = custList.begin();
        itr != custList.end();
        ++itr) {
    cout << (*itr)->getId() << "  " << setw(10) << (*itr)->getName() 
         << "  " << setw(4) << (*itr)->getPoints();
    cout << "   Purchased: ";
    for(int j = 0; j < (*itr)->getArray()->getSize(); j++){
      cout << "Product Id: " << (*itr)->getArray()->get(j)->getId() << ", Units: " << (*itr)->getArray()->get(j)->getnumOfUnits() << "   ";
    } 
   cout << endl;
  }
}

void UI::printError(string err)
{
  cout << endl << err << " -- press enter to continue...";
  cin.get();
}

void UI::printUsageError()
{
  cout << endl << "Usage:  cushop OPTION" << endl << endl;
  cout <<         "        where OPTION is either: " << endl;
  cout <<         "              -a  Admin menu"        << endl;
  cout <<         "              -c  Cashier menu"      << endl << endl;
}

void UI::promptForInt(string prompt, int* num)
{
  cout << prompt << ": ";
  *num = readInt();
}

void UI::promptForStr(string prompt, string* str)
{
  cout << prompt << ": ";
  getline(cin, *str);
}

void UI::promptForFloat(string prompt, float* num)
{
  string str;

  cout << prompt << ": ";
  getline(cin, str);

  stringstream ss(str);
  ss >> *num;
}

int UI::readInt()
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

void UI::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

