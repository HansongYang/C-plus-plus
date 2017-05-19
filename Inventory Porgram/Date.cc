#include "Date.h" 

Date::Date(int d, int m, int y){
  day = d;
  month = m;
  year = y;
}

Date& Date::operator+=(int numDays){
  if(numDays > 30){
    month += numDays / 30;
    day += numDays % 30; 
  }
  else{
    day += numDays;
  }
  if(day > 30){
    day = day - 30;
    month++;
  }
  while(month > 12){
    month -= 12;
    year++;
  }
}

Date Date::operator+(int numDays){
  Date date(day, month, year);
  date += numDays;
  return date;
}

bool Date::operator<(Date& other) const{
  if(year < other.getYear()){
    return true;
  }
  else if(year == other.getYear()){
    if(month < other.getMonth()){
      return true;
    }
    else if(month == other.getMonth()){
      if(day < other.getDay()){
        return true;
      }
      else{
        return false;
      }
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}

int Date::getYear(){
  return year;
}

int Date::getMonth(){
  return month;
}

int Date::getDay(){
  return day;
}

void Date::setYear(int y){
  year = y;
}

void Date::setMonth(int m){
  month = m;
}

void Date::setDay(int d){
  day = d;
}

void Date::toString(string& outstr){
  outstr = "";
  stringstream ss;

  if(day < 10){
    ss << "0" << day;
  }else{
    ss << day;
  }
  if(month < 10){
    ss << "/0" << month << "/" << year;
  }else{
    ss << "/" << month << "/" << year;
  }
  outstr = ss.str();
}
