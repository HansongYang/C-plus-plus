#include <string>
#include <cstdlib>
#include "OrderArray.h"

OrderArray::OrderArray(){
  size = 0;
}

int OrderArray::getSize(){ return size;}

Order* OrderArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}

void OrderArray::add(Order* order){
  if (size >= MAX_ARR)
    return;
   
  elements[size++] = order;
}
