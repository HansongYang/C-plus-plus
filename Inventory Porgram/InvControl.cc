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
  string prodName, prodSize, prodCate;
  int    prodUnits, prodId, amount, year, month, day, lifespan;
  float  prodPrice;
  string outstr;
  OrderArray arr;

  while (1) {
    choice = -1;
    view.adminMenu(&choice);
    if (choice == 1) {		// add new product
      view.promptForStr("Product name", &prodName);
      view.promptForStr("Product size", &prodSize);
      view.promptForInt("# units", &prodUnits);
      view.promptForFloat("Price", &prodPrice);
      view.promptForInt("Manufactured Year", &year);
      while(year > 2017 || year < 2014){
        view.printError("Sorry. It is not a valid input. Please enter again.");
        view.promptForInt("Manufactured Year", &year);
      }

      view.promptForInt("Manufactured Month", &month);
      while(month > 12 || month < 1){
        view.printError("Sorry. It is not a valid input. Please enter again.");
        view.promptForInt("Manufactured Month", &month);
      }

      view.promptForInt("Manufactured Day", &day);
      while(day > 30 || day < 1){
        view.printError("Sorry. It is not a valid input. Please enter again.");
        view.promptForInt("Manufactured Day", &day);
      }

      view.promptForStr("Product category", &prodCate);
      if(prodCate == "Bakery"){
        view.promptForInt("Lifespan", &lifespan);
      	Bakery* newBakery = new Bakery(prodName, prodSize, prodUnits, prodPrice, year, month, day, lifespan);
     	store.addProd(newBakery);
      }else if(prodCate == "CoffeeTea"){
        lifespan = 720;
        CoffeeTea* newCoffeeTea = new CoffeeTea(prodName, prodSize, prodUnits, prodPrice, year, month, day, lifespan);
        store.addProd(newCoffeeTea);
      }else if(prodCate == "Dairy"){
        view.promptForInt("Lifespan", &lifespan);
        Dairy* newDairy = new Dairy(prodName, prodSize, prodUnits, prodPrice, year, month, day, lifespan);
        store.addProd(newDairy); 
      }else if(prodCate == "Meat"){
        view.promptForInt("Lifespan", &lifespan);
        Meat* newMeat = new Meat(prodName, prodSize, prodUnits, prodPrice, year, month, day, lifespan);
        store.addProd(newMeat); 
      }else if(prodCate == "MiscGoods"){
        lifespan = 720;
        MiscGoods* newMiscGoods = new MiscGoods(prodName, prodSize, prodUnits, prodPrice, year, month, day, lifespan);
        store.addProd(newMiscGoods); 
      }else{
	view.printError("Sorry. It is not an existing product category.");
      }
    }
    else if (choice == 2) {	// add inventory
      while(1){
        view.promptForProd(&prodId);
        if(prodId == 0){ break;}
        addInventory(&store, &prodId, amount);
      }
    }
    else if (choice == 3) {	// print inventory
      view.printStock(store.getList());
      view.pause();
    }
    else if (choice == 4) {	// print customers
      view.printCustomers(store.getCustomers());
      view.pause();
    }
    else if (choice == 5){      //remove product
      while(1){
        view.promptForProd(&prodId);
        if(prodId == 0){ break;}
        removeProduct(&store, &prodId);
      }
    }
    else if (choice == 6){      //Print orders
      server.retrieve(arr);
      view.printOrders(&arr);
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
  int     prodId, custId, totalPoints = 0;
  float   totalPrices = 0;
  bool    terminate = false;
  string outstr;
  Order* order;
  OrderArray arr;

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
        order = new Order();
        break;
       }
     }
      if(terminate) { break;}
      while(1){
        order->setCustomer(store.IDget(custId));
        view.promptForProd(&prodId);
        if(prodId == 0){ 
	    if(order->getArray()->getSize() > 0){
          	  order->setTotalPrices(totalPrices); 
         	  server.update(order);
            }
            else{
        	  delete order;
            }
            break;
        }
        if(checkProduct(&store, &prodId, &custId, &totalPrices, &totalPoints, order)){
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
      view.printStock(store.getList());
      view.printCustomers(store.getCustomers());
      server.retrieve(arr); 
      view.printOrders(&arr);
      view.pause();
    }
    else {
      break;
    }
  }
}

bool InvControl::checkCustomer(Store* store, int* id){
  list<Customer*> custList = store->getCustomers();
  bool newcust = true; 

  list<Customer*>::iterator itr;
  for ( itr  = custList.begin();
        itr != custList.end();
        ++itr) {
    if((*itr)->getId() == *id){
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

bool InvControl::checkProduct(Store* store,int* id, int* cust, float* totalPrices, int* totalPoints, Order* order){
  ProdList* prod = store->getList();

  if(prod->find(*id) == NULL){
    return true;
  }
  else{
    if(prod->find(*id)->getUnits() > 0){
      view.printInfo("This is an existing product and there is at least one unit of this product in stock.");
      int units = prod->find(*id)->getUnits();
      units--;
      prod->find(*id)->setUnits(units);   

      store->IDget(*cust)->setPoints(store->IDget(*cust)->getPoints() + round(prod->find(*id)->getPrice()));

      *totalPrices += prod->find(*id)->getPrice(); 
      *totalPrices += prod->find(*id)->computeTax(); 
      *totalPoints += round(prod->find(*id)->getPrice());

      store->IDget(*cust)->getArray()->add(1, *id); 
      order->getArray()->add(1, *id);
    } 
    else{
      view.printInfo("Sorry, this product has been sold out.");
    }
   }
 
  if(store->IDget(*cust)->getArray()->getSize() == 64){
     view.printInfo("Sorry, the purchase array is full. You cannot purchase any more product.");
     prod = 0;
   }

   view.printInfo("What is the next purchased product?");
  
  return false;
}

void InvControl::addInventory(Store* store,int* id, int amount){
  ProdList* prod = store->getList();

  if(prod->find(*id) == NULL){
    view.printInfo("This product doesn't exist. Please enter again.");
  }
  else{
    view.promptForInventory(&amount);
    if(amount < 1){
      view.printInfo("Sorry, the number of new units should be bigger than 0. Please enter again.");
    }else{
        prod->find(*id)->setUnits(amount + prod->find(*id)->getUnits());
    }
  }
}

void InvControl::removeProduct(Store* store, int* id){
  ProdList* prod = store->getList();
  if(prod->find(*id) == NULL){
    view.printInfo("This product doesn't exist. Please enter again.");
  }
  else{
    prod->remove(*id);
    view.printInfo("This product has been removed successfully.");
  }
}

void InvControl::initProducts()
{
  Dairy*      newDairy;
  CoffeeTea*  newCoffeeTea;
  Bakery*     newBakery;
  Meat*       newMeat;
  MiscGoods*  newMiscGoods;
  
  newMiscGoods = new MiscGoods("Sudzzy Dish Soap", "1 L", 10, 3.99f, 2016, 9, 1, 720);
  store.addProd(newMiscGoods);

  newMiscGoods = new MiscGoods("Peachy Laundry Soap", "2 L", 3, 8.99f, 2017, 1, 4, 720);
  store.addProd(newMiscGoods);

  newMiscGoods = new MiscGoods("Daisy's Spicy Chili", "150 g", 5, 1.29f, 2016, 12, 30, 720);
  store.addProd(newMiscGoods);

  newMiscGoods = new MiscGoods("Daisy's Maple Baked Beans", "220 g", 2, 2.49f, 2017, 1, 13, 720);
  store.addProd(newMiscGoods);

  newMeat = new Meat("Marmaduke Hot Dogs", "12-pack", 4, 4.99f, 2017, 4, 19, 20);
  store.addProd(newMeat);

  newMeat = new Meat("Garfield Hamburger Patties", "900 g", 2, 11.99f, 2017, 4, 15, 15);
  store.addProd(newMeat);

  newMiscGoods = new MiscGoods("Chunky Munkey Ice Cream", "2 L", 1, 2.97f, 2016, 10, 17, 720);
  store.addProd(newMiscGoods);

  newBakery = new Bakery("It's Your Bday Chocolate Cake", "500 g", 3, 12.99f, 2017, 4, 12, 10);
  store.addProd(newBakery);

  newBakery = new Bakery("Happy Baker's Hot dog buns", "12-pack", 5, 3.49f, 2017, 4, 1, 20);
  store.addProd(newBakery);

  newBakery = new Bakery("Happy Baker's Hamburger buns", "8-pack", 8, 3.99f, 2017, 4, 5, 15);
  store.addProd(newBakery);

  newDairy = new Dairy("Moo-cow 2% milk", "1 L", 7, 2.99f, 2017, 4, 15, 17);
  store.addProd(newDairy);

  newDairy = new Dairy("Moo-cow 2% milk", "4 L", 3, 4.99f, 2017, 4, 15, 17);
  store.addProd(newDairy);

  newDairy = new Dairy("Moo-cow 5% coffee cream", "250 ml", 4, 1.49f, 2017, 4, 5, 14);
  store.addProd(newDairy);

  newBakery = new Bakery("Good Morning Granola Cereal", "400 g", 2, 5.49f, 2016, 12, 5, 180);
  store.addProd(newBakery);

  newCoffeeTea = new CoffeeTea("Lightening Bolt Instant Coffee", "150 g", 8, 4.99f, 2017, 1, 6, 720);
  store.addProd(newCoffeeTea);

  newCoffeeTea = new CoffeeTea("Lightening Bolt Decaf Coffee", "100 g", 2, 4.99f, 2016, 8, 11, 720);
  store.addProd(newCoffeeTea);

  newMiscGoods = new MiscGoods("Munchies BBQ Chips", "250 g", 7, 2.99f, 2016, 12, 18, 720);
  store.addProd(newMiscGoods);

  newMiscGoods = new MiscGoods("Munchies Ketchup Chips", "250 g", 3, 2.99f, 2016, 10, 10, 720);
  store.addProd(newMiscGoods);

  newMiscGoods = new MiscGoods("Dogbert Salted Chips", "210 g", 4, 1.99f, 2017, 2, 28, 720);
  store.addProd(newMiscGoods);

  newMiscGoods = new MiscGoods("Dogbert Sweet and Spicy Popcorn", "180 g", 5, 2.29f, 2016, 11, 15, 720);
  store.addProd(newMiscGoods);
  
  newMiscGoods = new MiscGoods("Delicious Tofu", "500 g", 10, 4.38f, 2017, 3, 3, 720);
  store.addProd(newMiscGoods);

  newMiscGoods = new MiscGoods("Chicken and Green Oinon Dumplings", "1000 g", 19, 6.39f, 2016, 10, 1, 720);
  store.addProd(newMiscGoods);
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

