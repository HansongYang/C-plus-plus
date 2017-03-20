

#include <string>
#include <cstdlib>
using namespace std;

#include "CustArray.h"

CustArray::CustArray()
{
  size = 0;
}

CustArray::~CustArray(){
  for(int i = 0; i < size; i++){
     delete elements[i];
   }
}

int CustArray::getSize() { return size; }

Customer* CustArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}

void CustArray::add(Customer* cust)
{
  if (size >= MAX_ARR)
    return;

  elements[size++] = cust;
}

Customer* CustArray::IDget(int id){
  for(int i = 0 ; i < size; i++){
    if(id == elements[i]->getId()){
      id = i;
      break;
    }
  }
  return elements[id];
}

