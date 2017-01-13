#include <iostream>
#include <string>

#include "A4Types.h"


using namespace std;




int main()
{
    // test your code here
    Money m1(17,3);
    std::cout << m1.getDollars() << " dollars and "
              << m1.getCents() << " cents" << std::endl;

    Money m11(0,0,0,0,0);
    unsigned int q = m11.getQuarters();   // q better be 0
    cout<<"Quarters: "<<q<<endl;
    m11.addQuarters(12);
    q = m11.getQuarters(); // q better be 12 now
    cout<<"Quarters: "<<q<<endl;

    Money m12(0,0,1,0,0);
    unsigned int d =  m12.getDimes();  // d better be 1
    cout<<"Dimes: "<< d <<endl;
    m12.addMoney( *(new Money(0,0,2,0,0)) );
    d = m12.getDimes(); // d could be 1, 2, or 3 now!  it is not specified.
    unsigned int cents = m12.getCents(); // cents better be 30 though
    cout<<"Dimes: "<< d <<" cents: "<<cents<<endl;

    Money m(0,5,12,2,301);


//m has value $5.56

cout<<m.getDollars()<<" "<<
m.getQuarters()<<" "<<
m.getDimes()<<" " <<m.getNickels()<<" "<<
m.getPennies() <<" "<<
m.getCents()<<endl;

m.leastCoins();

cout<<m.getDollars()<<" "<<
m.getQuarters()<<" "<<
m.getDimes()<<" " <<m.getNickels()<<" "<<
m.getPennies() <<" "<<
m.getCents()<<endl;

    Money paid(10, 10,2,6,8);
    Money cost(11, 5,3,3,8);
    Money* change = makeChange(cost, paid);

    if (change != NULL) {
        std::cout<< "Change = " << change->getDollars() << " dollars "<<change->getQuarters()<<" quarters "
        <<change->getDimes() <<" dimes "<< change->getNickels()<<" nickels "<<change->getPennies() << " pennies." << std::endl;
    } else {
        std::cout << "Paid < cost"<< std::endl;
    }

    return 0;
}
