#ifndef A4TYPES_H_INCLUDED
#define A4TYPES_H_INCLUDED

#include <string>


//
// Money Class
//
class Money{
  private:
    unsigned int numDollars;    // number of dollars
    unsigned int numQuarters;   // number of quarters (25 cents)
    unsigned int numDimes;      // number of dimes (10 cents)
    unsigned int numNickels;    // number of nickels (5 cents)
    unsigned int numPennies;    // number of pennies (1 cents)

  public:
     // constructors for the class
     // Exercise 1 is to implement these
     Money();
     Money(unsigned int dollars, unsigned int cents);
     Money(unsigned int dd, unsigned int q, unsigned int d, unsigned int n, unsigned int p);

     // getter functions
     // these are provided for you
     unsigned int getDollars();
     unsigned int getQuarters();
     unsigned int getDimes();
     unsigned int getNickels();
     unsigned int getPennies();

     // you need to implement this getter in Exercise 2
     unsigned int getCents();

     // setter functions
     // you need to implement each of these in Exercise 2
     void addMoney(Money);
     void addDollars(unsigned int);
     void addQuarters(unsigned int);
     void addDimes(unsigned int);
     void addNickels(unsigned int);
     void addPennies(unsigned int);
     void addCents(unsigned int);

     // other methods for Exercise 3
     void leastCoins();               // Exercise 3
     unsigned int numberOfCoins();    // Exercise 3

};


//
// Functions using Money objects for Exercise 4
//

Money* makeChange(Money& cost, Money& paid);
Money* makeChangeNpPennies(Money& cost, Money& paid);



#endif // A4TYPES_H_INCLUDED
