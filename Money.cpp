// ---------------------------------------------------------------------------
// In this .cpp file you will provide the source code for all
// functions, constructors and method specified in A4Tyope,h that are not yet defined.
// You are allowed to write helper functions but are not allowed to change the
// class definitions.
//
// Student Name:   Hansong Yang  <your full name as it appears in cuLearn>
// Student Number:  101001223 <your student number>
//
// References:  Hinek, J. "Lectures Notes for COMP1406B - Introduction to Computer Science II" [PDF documents].
//Retrieved from cuLearn: https://www.carleton.ca/culearn/ (Winter 2016).     <consult the plagiarism policy for instruction>
//
// ---------------------------------------------------------------------------



#include "A4Types.h"
#include <iostream>


// Note: When defining method behaviour in C++ class
//       in a different location than the actual class
//       definition (.h file) we need to specify not only the
//       name of the function but also which class it belongs to.
//       We use Return_Type Class_Name::Method_Name to do this.


Money::Money(){
    // Initializes all the objects with zero money.
    numDollars = 0;
    numQuarters = 0;
    numDimes = 0;
    numNickels = 0;
    numPennies = 0;
}

Money::Money(unsigned int dollars, unsigned int cents){
    // Money constructor (two arguments)
    numDollars = dollars;
    numPennies = cents;
    numQuarters = 0;
    numDimes = 0;
    numNickels = 0;
}

Money::Money(unsigned int dd, unsigned int q, unsigned int d, unsigned int n, unsigned int p){
    // Money constructor (five arguments)
    numDollars = dd;
    numQuarters = q;
    numDimes = d;
    numNickels = n;
    numPennies = p;
}

// getters provided for you
// Note that we still need to specify which class the
// methods belong to.
unsigned int Money::getDollars(){  return numDollars;}
unsigned int Money::getQuarters(){ return numQuarters;}
unsigned int Money::getDimes(){    return numDimes;}
unsigned int Money::getNickels(){  return numNickels;}
unsigned int Money::getPennies(){  return numPennies;}

unsigned int Money::getCents(){

  int cents = 0;
//Convert quarters, dimes and nickels to pennies and add them up.
    cents += 25 * numQuarters;
    cents += 10 * numDimes;
    cents += 5 * numNickels;
    cents += numPennies;

 return cents;
}

//Add the value of input money object m to the current object.
void Money::addMoney(Money m){
    numDollars += m.numDollars;
    numQuarters += m.numQuarters;
    numNickels += m.numNickels;
    numDimes += m.numDimes;
    numPennies += m.numPennies;
}

void Money::addDollars(unsigned int d){
     numDollars += d;
}

void Money::addQuarters(unsigned int q){
    numQuarters += q;
}

void Money::addDimes(unsigned int d){
    numDimes += d;
}

void Money::addNickels(unsigned int n){
    numNickels += n;
}

void Money::addPennies(unsigned int p){
    numPennies += p;
}

void Money::addCents(unsigned int c){
    numPennies += c;
}

void Money::leastCoins(){
    //First, convert the pennies to Dollars.
    while(numPennies >= 100){
        numDollars++;
        numPennies -= 100;
    }
    //Then, convert the pennies to Quarters.
    while(numPennies >= 25){
        numQuarters++;
        numPennies -= 25;
    }
    //Subsequently, convert the pennies to Dimes.
    while(numPennies >= 10){
        numDimes++;
        numPennies -= 10;
    }
    //Convert the pennies to Nickels.
    while(numPennies >= 5){
        numNickels++;
        numPennies -= 5;
    }

    //Convert Nickels to dollars.
     while(numNickels >= 20){
        numDollars++;
        numNickels -= 20;
    }
    //Subsequently, convert the nickels to quarters.
    while(numNickels >= 5){
        numQuarters++;
        numNickels -= 5;
    }

    //Convert the Nickels to Dimes.
    while(numNickels >= 2){
        numDimes++;
        numNickels -= 2;
    }

    //Convert the Dimes to dollars.
    while(numDimes >= 10){
        numDollars++;
        numDimes -= 10;
    }
    //Convert the dimes to Quarters and nickles.
    while(numDimes >= 3){
        numQuarters++;
        numDimes -=3;
        numNickels++;
    }
    //Subsequently, convert the Dimes and nickels to quarters.
    while(numDimes >= 2 && numNickels >= 1){
        numQuarters++;
        numDimes -= 2;
        numNickels--;
    }

    //In case there are extra nickels, so convert the Nickels to Dimes.
    while(numNickels >= 2){
        numDimes++;
        numNickels -= 2;
    }
    //In case there are extra dimes and nickels, so convert them to quarters.
    while(numDimes >= 2 && numNickels >= 1){
        numQuarters++;
        numDimes -= 2;
        numNickels--;
    }
    //Finally, convert the quarters to dollars..
    while(numQuarters >= 4){
        numDollars++;
        numQuarters -= 4;
    }
}

unsigned int Money::numberOfCoins(){
     int coins = 0;
     //Add all the coins.
     coins = numQuarters + numDimes + numNickels + numPennies;

    return coins;
}


//
// Functions using Money objects for Exercise 4
//

Money* makeChange(Money& cost,  Money& paid){
//The paid are bigger than cost.
    if(paid.getDollars() > cost.getDollars()){
        if(paid.getCents() >= cost.getCents()){
            Money* change = new Money();
            //Add changes to the new object change.
            change->addDollars(paid.getDollars() - cost.getDollars());
            change->addCents(paid.getCents() - cost.getCents());
            change->leastCoins();

            return change;
        }
        else{
            //If the paid cents are not bigger than the cost cents.
            int price = paid.getCents() - cost.getCents();
            int extraCents = (paid.getDollars() - cost.getDollars()) * 100;

            if(extraCents >= price * (-1)){

                Money* change = new Money();
                price = (paid.getDollars() - cost.getDollars()) * 100 + price;
            //Add changes to the new object change.
                change->addCents(price);
                change->leastCoins();

            return change;
        }
            else{
                return NULL;
            }
        }
    }
    //The paid's dollars are equal to the cost's dollars.
    else if(paid.getDollars() == cost.getDollars()){
        if (paid.getCents() >= cost.getCents()){
            Money* change = new Money();

            //Add changes to the new object change.
            change->addDollars(paid.getDollars() - cost.getDollars());
            change->addCents(paid.getCents() - cost.getCents());
            change->leastCoins();

            return change;
        }
    }
    //The paid's dollars are smaller than the cost's dollars.
    else if(paid.getDollars() < cost.getDollars()){
            //If there are some extra cents, then add them to the dollars.
        if((paid.getCents() - cost.getCents()) > (cost.getDollars() - paid.getDollars()) * 100){
             Money* change = new Money();
            int extraCents = paid.getCents() - cost.getCents();
               //Add changes to the new object change.
             change->addCents(extraCents - (cost.getDollars() - paid.getDollars()) * 100);
             change->leastCoins();
             return change;
        }
    }
    return NULL;
}

Money* makeChangeNpPennies(Money& cost, Money& paid){
//Check the last digit of pennies of the ocst and the paid.
    int Pennies = cost.getPennies() % 10;
    int cash = paid.getPennies() % 10;
    //Change the last digit of the price.
    int price = (cost.getCents() - Pennies);

    //First, if the last digit of cost is 1 or 2, then change it to 0.
    if(Pennies == 1 || Pennies == 2){
            Pennies = 0;
    }
    //If the last digit of cost is 6 or 7, then change it to 5.
    else if(Pennies == 6 || Pennies == 7){
            Pennies = 5;
    }
    //If the last digits are not equal.
    else if(Pennies != cash){
        //Round the price up.
        if(Pennies == 3 || Pennies == 4){
                Pennies = 5;
        }
        else if(Pennies == 8 || Pennies == 9){
                Pennies = 10;
        }
    }
    else{
        //The last digits of cost and paid are equal or the prices are rounded down.
       if(paid.getDollars() > cost.getDollars()){
            if(paid.getCents() >= cost.getCents()){
                Money* change = new Money();
                //Add changes to the new object change.
                change->addDollars(paid.getDollars() - cost.getDollars());
                change->addCents(paid.getCents() - cost.getCents());
                change->leastCoins();

            return change;
        }
            else{
                if((paid.getDollars() - cost.getDollars()) * 100 >= (paid.getCents() - cost.getCents()) * (-1)){
                    Money* change = new Money();
                    //Add changes to the new object change.
                    change->addCents(paid.getCents() - cost.getCents() + (paid.getDollars() - cost.getDollars()) * 100);
                    change->leastCoins();

                return change;
                }
                else {
                    return NULL;
                }
            }
        }
        else if(paid.getDollars() == cost.getDollars()){
                if(paid.getCents() >= cost.getCents()){
                    Money* change = new Money();
                    //Add changes to the new object change.
                    change->addDollars(paid.getDollars() - cost.getDollars());
                    change->addCents(paid.getCents() - cost.getCents());
                    change->leastCoins();
                    return change;
                }
            }
        else if(paid.getDollars() < cost.getDollars()){
            if((paid.getCents() - cost.getCents()) > (cost.getDollars() - paid.getDollars()) * 100){
             Money* change = new Money();

             int extraCents = paid.getCents() - cost.getCents();
             //Add changes to the new object change.
             change->addCents(extraCents - (cost.getDollars() - paid.getDollars()) * 100);
             change->leastCoins();
             return change;
                }
            }
            return NULL;
        }


    //The prices are rounded up.
    price += Pennies;

    if(paid.getDollars() > cost.getDollars()){
        if(paid.getCents() >= price){
            //Calculate the cents.
            price = paid.getCents() - price;
            //Calculate the dollars.
            int dollars = paid.getDollars() - cost.getDollars();

            Money* change = new Money();
            //Add changes to the new object change.
            change->addDollars(dollars);
            change->addCents(price);
            change->leastCoins();

            return change;
        }
        else{
            price = paid.getCents() - price;
            if(((paid.getDollars() - cost.getDollars()) * 100) >= price * (-1)){

                price = (paid.getDollars() - cost.getDollars()) * 100 + price;
                Money* change = new Money();
              //Add changes to the new object change.
                change->addCents(price);
                change->leastCoins();

            return change;
            }
            else{
                return NULL;
            }
        }
    }
    else if(paid.getDollars() == cost.getDollars()){
        if (paid.getCents() >= price){

            price = paid.getCents() - price;

            Money* change = new Money();
            //Add changes to the new object change.
            change->addCents(price);
            change->leastCoins();

            return change;
        }
    }
    else if(paid.getDollars() < cost.getDollars()){
             if((paid.getCents() - price) > (cost.getDollars() - paid.getDollars()) * 100){
                Money* change = new Money();
                int extraCents = paid.getCents() - price;
               //Add changes to the new object change.
                change->addCents(extraCents - (cost.getDollars() - paid.getDollars()) * 100);
                change->leastCoins();
             return change;
            }
        }
    return NULL;
}
