#include <string>
#include <cstdlib>

#include "PurchArray.h"

PurchArray::PurchArray(){
  size = 0;
}

PurchArray::~PurchArray(){
  for(int i = 0; i < size; i++){
     delete elements[i];
  }
}

int PurchArray::getSize(){ return size;}

Purchase* PurchArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}

void PurchArray::add(int numOfUnits, int id)
{
  if (size >= MAX_ARR)
    return;

  bool newProd = true;
 
  for(int i = 0; i < size; i++){
    if(id == elements[i]->getId()){
      newProd = false;
      int n = elements[i]->getnumOfUnits();
      n++;
      elements[i]->setnumOfUnits(n);
      break;
    } 
  }
  if(newProd){
    Purchase* purch = new Purchase(numOfUnits, id); 
    elements[size++] = purch;
  }
}



