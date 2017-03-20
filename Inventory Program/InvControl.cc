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

#include <cstdlib>
#include "InvControl.h"

InvControl::InvControl()
{
  initProducts();
  initCustomers();
}

void InvControl::launch(int argc, char* argv[])
{
  if (argc != 2) {
    view.printUsageError();
    exit(1);
  }

  string option(argv[1]);

  if (option == "-a") {		// Admin menu
    processAdmin();
  }
  else if (option == "-c") {	// Cashier menu
    processCashier();
  }
  else {
    view.printUsageError();
    exit(1);
  }
}

void InvControl::processAdmin()
{
  int    choice;
  string prodName, prodSize;
  int    prodUnits, prodId, amount;
  float  prodPrice;

  while (1) {
    choice = -1;
    view.adminMenu(&choice);
    if (choice == 1) {		// add new product
      view.promptForStr("Product name", &prodName);
      view.promptForStr("Product size", &prodSize);
      view.promptForInt("# units", &prodUnits);
      view.promptForFloat("Price", &prodPrice);
      Product* prod = new Product(prodName, prodSize, prodUnits, prodPrice);
      store.addProd(prod);
      view.pause();
    }
    else if (choice == 2) {	// add inventory
      while(1){
        view.promptForProd(&prodId);
        if(prodId == 0){ break;}
        addInventory(&store, &prodId, amount);
      }
    }
    else if (choice == 3) {	// print inventory
      view.printStock(store.getStock());
      view.pause();
    }
    else if (choice == 4) {	// print customers
      view.printCustomers(store.getCustomers());
      view.pause();
    }
    else {
      break;
    }
  }
}

void InvControl::processCashier()
{
  int choice;
  int prodId, custId, totalPoints = 0;
  float totalPrices = 0;
  bool terminate = false;
  while (1) {
    choice = -1;
    view.cashierMenu(&choice);
    if (choice == 1) {			// purchases
     while(1){
      view.promptForCust(&custId);
      if(custId == 0){ terminate = true; break;}
      if(checkCustomer(&store, &custId)){  
 	view.printError("It is not an existing customer. Please enter again.");
      	}
       else{
	  break;
 	}
      }
      if(terminate) { break;}
      while(1){
        view.promptForProd(&prodId);
        if(prodId == 0){  break;}
        if(checkProduct(&store, &prodId, &custId, &totalPrices, &totalPoints)){
          view.printError("Sorry, this product doesn't exist. Please enter again.");
         }
        }
      view.printTotal(&totalPrices, &totalPoints);
      totalPrices = 0; 
      totalPoints = 0;
    }
    else if (choice == 2) {		// return purchases
      view.printError("Feature not implemented");
    }
    else if (choice == MAGIC_NUM) {	// print inventory and customers
      view.printStock(store.getStock());
      view.printCustomers(store.getCustomers());
      view.pause();
    }
    else {
      break;
    }
  }
}

bool InvControl::checkCustomer(Store* store, int* id){
  CustArray* arr = store->getCustomers();
  bool newcust = true; 
  for(int i = 0; i < arr->getSize(); i++){
    if(arr->get(i)->getId() == *id){
      newcust = false;
      view.printInfo("This is an existing customer.");
      break;
    }
  }
  if(newcust){
    return newcust;
  }
  return false;
}

bool InvControl::checkProduct(Store* store,int* id, int* cust, float* totalPrices, int* totalPoints){
  CustArray* arr  = store->getCustomers();
  ProdArray* prod = store->getStock();
  bool newprod = true;

  for(int i = 0; i < prod->getSize(); i++){
      if(prod->get(i)->getId() == *id && prod->get(i)->getUnits() > 0){
        view.printInfo("This is an existing product and there is at least one unit of this product in stock.");
        newprod = false;           
        int units = prod->get(i)->getUnits();
        units--;
        prod->get(i)->setUnits(units);   

        arr->IDget(*cust)->setPoints(round(prod->get(i)->getPrice()));

        *totalPrices += prod->get(i)->getPrice();
        *totalPoints += round(prod->get(i)->getPrice());

	arr->IDget(*cust)->getArray()->add(1, prod->get(i)->getId()); 
	break;
     } 
     else if(prod->get(i)->getId() == *id && prod->get(i)->getUnits() <= 0){
        newprod = false;
        view.printInfo("Sorry, this product has been sold out.");
     }
   }

   if(newprod){
      return newprod;
     }
   if(arr->IDget(*cust)->getArray()->getSize() == 64){
      view.printInfo("Sorry, the array is full. You cannot purchase any product.");
      prod = 0;
   }

   view.printInfo("What is the next purchased product?");
  
  return false;
}

void InvControl::addInventory(Store* store,int* id, int amount){
  ProdArray* prod = store->getStock();
  bool valid = false;

  for(int i = 0; i < prod->getSize(); i++){
    if(prod->get(i)->getId() == *id){
      view.promptForInventory(&amount);
      if(amount < 1){
        view.printInfo("Sorry, the number of new units should be bigger than 0. Please enter again.");
      }else{
      	prod->get(i)->setUnits(amount + prod->get(i)->getUnits());
      }
      valid = true;
    }
  }
  if(!valid){
    view.printInfo("This product doesn't exist. Please enter again.");
  }
}

void InvControl::initProducts()
{
  Product* newProd;

  newProd = new Product("Sudzzy Dish Soap", "1 L", 10, 3.99f);
  store.addProd(newProd);

  newProd = new Product("Peachy Laundry Soap", "2 L", 3, 8.99f);
  store.addProd(newProd);

  newProd = new Product("Daisy's Spicy Chili", "150 g", 5, 1.29f);
  store.addProd(newProd);

  newProd = new Product("Daisy's Maple Baked Beans", "220 g", 2, 2.49f);
  store.addProd(newProd);

  newProd = new Product("Marmaduke Hot Dogs", "12-pack", 4, 4.99f);
  store.addProd(newProd);

  newProd = new Product("Garfield Hamburger Patties", "900 g", 2, 11.99f);
  store.addProd(newProd);

  newProd = new Product("Chunky Munkey Ice Cream", "2 L", 1, 2.97f);
  store.addProd(newProd);

  newProd = new Product("It's Your Bday Chocolate Cake", "500 g", 0, 12.99f);
  store.addProd(newProd);

  newProd = new Product("Happy Baker's Hot dog buns", "12-pack", 5, 3.49f);
  store.addProd(newProd);

  newProd = new Product("Happy Baker's Hamburger buns", "8-pack", 8, 3.99f);
  store.addProd(newProd);

  newProd = new Product("Moo-cow 2% milk", "1 L", 7, 2.99f);
  store.addProd(newProd);

  newProd = new Product("Moo-cow 2% milk", "4 L", 3, 4.99f);
  store.addProd(newProd);

  newProd = new Product("Moo-cow 5% coffee cream", "250 ml", 4, 1.49f);
  store.addProd(newProd);

  newProd = new Product("Good Morning Granola Cereal", "400 g", 2, 5.49f);
  store.addProd(newProd);

  newProd = new Product("Lightening Bolt Instant Coffee", "150 g", 8, 4.99f);
  store.addProd(newProd);

  newProd = new Product("Lightening Bolt Decaf Coffee", "100 g", 2, 4.99f);
  store.addProd(newProd);

  newProd = new Product("Munchies BBQ Chips", "250 g", 7, 2.99f);
  store.addProd(newProd);

  newProd = new Product("Munchies Ketchup Chips", "250 g", 3, 2.99f);
  store.addProd(newProd);

  newProd = new Product("Dogbert Salted Chips", "210 g", 4, 1.99f);
  store.addProd(newProd);

  newProd = new Product("Dogbert Sweet and Spicy Popcorn", "180 g", 5, 2.29f);
  store.addProd(newProd);
  
  newProd = new Product("Delicious Tofu", "500 g", 10, 4.38f);
  store.addProd(newProd);

  newProd = new Product("Chicken and Green Oinon Dumplings", "1000 g", 19, 6.39f);
  store.addProd(newProd);
}

void InvControl::initCustomers()
{

  Customer* cust01 = new Customer("Starbuck");
  Customer* cust02 = new Customer("Apollo");
  Customer* cust03 = new Customer("Boomer");
  Customer* cust04 = new Customer("Athena");
  Customer* cust05 = new Customer("Helo");
  Customer* cust06 = new Customer("Crashdown");
  Customer* cust07 = new Customer("Hotdog");
  Customer* cust08 = new Customer("Kat");
  Customer* cust09 = new Customer("Chuckles");
  Customer* cust10 = new Customer("Racetrack");
  Customer* cust11 = new Customer("Sherlock");
  Customer* cust12 = new Customer("John");

  store.addCust(cust01);
  store.addCust(cust02);
  store.addCust(cust03);
  store.addCust(cust04);
  store.addCust(cust05);
  store.addCust(cust06);
  store.addCust(cust07);
  store.addCust(cust08);
  store.addCust(cust09);
  store.addCust(cust10);
  store.addCust(cust11);
  store.addCust(cust12);
}

