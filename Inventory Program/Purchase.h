#ifndef PURCHASE_H
#define PURCHASE_H

class Purchase{
  public: 
    Purchase(int=0, int=0);
    int  getId();            //purpose: get the purchase's id
    int  getnumOfUnits();    //purpose: get the purchase's number of units
    void setnumOfUnits(int); //purpose: set the purchase's number of units
  protected:
    int     id;
    int     numOfUnits;
};

#endif
