OBJ = main.o InvControl.o Store.o Product.o UI.o ProdArray.o PurchArray.o Purchase.o Customer.o ProdList.o Order.o OrderServer.o OrderArray.o Perishable.o NonPerishable.o Taxable.o NonTaxable.o Dairy.o CoffeeTea.o Bakery.o Meat.o MiscGoods.o Date.o ExpirationBehaviour.o TaxationBehaviour.o

cushop:	$(OBJ)
	g++ -o cushop $(OBJ)

main.o:	main.cc 
	g++ -c main.cc

InvControl.o:	InvControl.cc InvControl.h Store.h OrderServer.h
	g++ -c InvControl.cc

UI.o:	UI.cc UI.h 
	g++ -c UI.cc

Store.o:	Store.cc Store.h 
	g++ -c Store.cc

Product.o:	Product.cc Product.h
	g++ -c Product.cc

ProdArray.o:	ProdArray.cc ProdArray.h Product.h defs.h
	g++ -c ProdArray.cc

PurchArray.o:   PurchArray.cc PurchArray.h Purchase.h defs.h
	g++ -c PurchArray.cc

Purchase.o:     Purchase.cc Purchase.h
	g++ -c Purchase.cc

Customer.o:	Customer.cc Customer.h PurchArray.h
	g++ -c Customer.cc

ProdList.o:	ProdList.cc ProdList.h Product.h
	g++ -c ProdList.cc

Order.o:       Order.cc Order.h Customer.h PurchArray.h
	g++ -c Order.cc

OrderServer.o: OrderServer.h OrderServer.cc OrderArray.h defs.h
	g++ -c OrderServer.cc

OrderArray.o: OrderArray.h OrderArray.cc Order.h defs.h
	g++ -c OrderArray.cc

Perishable.o: Perishable.cc Perishable.h
	g++ -c Perishable.cc

NonPerishable.o: NonPerishable.h NonPerishable.cc
	g++ -c NonPerishable.cc

Taxable.o: Taxable.cc Taxable.h
	g++ -c Taxable.cc

NonTaxable.o: NonTaxable.cc NonTaxable.h 
	g++ -c NonTaxable.cc

Dairy.o: Dairy.cc Dairy.h
	g++ -c Dairy.cc

CoffeeTea.o: CoffeeTea.h CoffeeTea.cc
	g++ -c CoffeeTea.cc

Bakery.o: Bakery.cc Bakery.h
	g++ -c Bakery.cc

Meat.o: Meat.cc Meat.h
	g++ -c Meat.cc

MiscGoods.o: MiscGoods.cc MiscGoods.h
	g++ -c MiscGoods.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

ExpirationBehaviour.o: ExpirationBehaviour.cc ExpirationBehaviour.h
	g++ -c ExpirationBehaviour.cc

TaxationBehaviour.o: TaxationBehaviour.cc TaxationBehaviour.h
	g++ -c TaxationBehaviour.cc

clean:
	rm -f $(OBJ) cushop
