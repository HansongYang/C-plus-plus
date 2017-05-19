#include <string>
#include <cstdlib>
#include "OrderServer.h"

OrderServer::OrderServer(){ }

OrderServer::~OrderServer(){
  for(int i = 0; i < elements.getSize(); i++){
     delete elements.get(i);
  }
}

void OrderServer::update(Order* order){
    elements.add(order);
}

void OrderServer::retrieve(OrderArray& arr){
  arr = elements;
}

