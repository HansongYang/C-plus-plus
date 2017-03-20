Preamble:
Program Author: Hansong Yang

Purpose: This is an inventory program for cashier to help customers buy products and also for administors to add and print products and customers.

Source: CustArray.cc
	Customer.cc
	InvControl.cc
	ProdArray.cc
	Product.cc
	PurchArray.cc
	Purchase.cc
	main.cc
	Store.cc
	UI.cc

Header: CustArray.h
	Customer.h
	InvControl.h
	ProdArray.h
	Product.h
	PurchArray.h
	Purchase.h
	Store.h
	UI.h
	defs.h

Compilation Command: make

Launching and Operating Instructions:

Launching Command for Admin:   ./cushop -a
Launching Command for Cashier: ./cushop -c

Operating Instructions:
You can choose admin mode or cashier mode before launching the program. After launching, for admin mode, user can follow the instructions to enter number. In the "add more inventory" feature, you can enter the product id first and then enter the number of new units. This number must be bigger than 0. Enter 0 to quit. 
For cashier mode, user can follow the instructions to enter number. In the "product purchase" feature, enter the customer id first and then enter product id for each time. If you want to quit this program, enter 0. After each purchase, all the purchase information will be printed on the screen. Enter 42 to print all the information of customers and products.

