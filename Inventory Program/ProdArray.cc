
#include <string>
#include <cstdlib>
using namespace std;

#include "ProdArray.h"

ProdArray::ProdArray()
{
  size = 0;
}

ProdArray::~ProdArray(){
  for(int i = 0 ; i < size; i++){
    delete elements[i];
  }
}

int ProdArray::getSize() { return size; }

Product* ProdArray::get(int index)
{
  if (index < 0 || index >= size)
    exit(1);
  return elements[index];
}

void ProdArray::add(Product* prod)
{
  if (size >= MAX_ARR)
    return;

  elements[size++] = prod;
}


