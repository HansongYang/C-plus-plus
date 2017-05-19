#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <sstream>
using namespace std;

class Date{
  public:
    Date(int=0,int=0,int=0);
    Date& operator+=(int);              //purpose: Add numDays to this date
    Date operator+(int);               //purpose: Return a new Date object that is the sum of this and numDays
    bool operator<(Date&) const;       //purpose: Returns a boolean indicating whether this date is greater than or less than other
    int  getYear();                    //purpose: get the year
    int  getMonth();                   //purpose: get the month
    int  getDay();		       //purpose: get the day
    void setYear(int);	               //purpose: set the year
    void setMonth(int);		       //purpose: set the month
    void setDay(int);                  //purpose: set the day
    void toString(string&);            //purpose: concatenate all the date data formatted into one string
  private:
    int  year; 
    int  month;
    int  day;
};
#endif
