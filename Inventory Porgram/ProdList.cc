#include <iostream>
using namespace std;

#include "ProdList.h"

ProdList::ProdList() : head(0){  }

ProdList::~ProdList(){
  Node* currNode = head;
  Node* nextNode;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->prodData;
    delete currNode;
    currNode = nextNode;
  }
}

void ProdList::add(Product* prod)
{
  Node* newProd;
  Node* currNode;
  Node* prevNode;

  newProd = new Node;
  newProd->prodData = prod;
  newProd->next = NULL;
  newProd->prev = NULL;

  currNode = head;
  prevNode = NULL;

  while (currNode != NULL) {
    Date currDate = currNode->prodData->getExpiryDate();
    if (newProd->prodData->getExpiryDate() < currDate)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {
    head = newProd;
  } 
  else {
    prevNode->next = newProd;
  }
  newProd->next = currNode;
  newProd->prev = prevNode;
  if(currNode != NULL){
     currNode->prev = newProd;
  }
}

void ProdList::remove(int id)
{
  Node* currNode = head;
  Node* prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->prodData->getId() == id) 
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {
    head = currNode->next;
    head->prev = NULL;
  }
  else{
    prevNode->next = currNode->next;
    if(currNode->next != NULL){
      currNode->next->prev = prevNode;
   }
  }
  delete currNode->prodData;
  delete currNode;
}

void ProdList::reorg(int cases){
  Node* currNode = head;
  Node* prevNode = NULL;
  Node* temp     = NULL;

  while (currNode != NULL) {
    prevNode = currNode;
    currNode = currNode->next;
    if (currNode != NULL && prevNode->prodData->getUnits() > currNode->prodData->getUnits()){
      break;
    }
  }

  if(currNode != NULL){
    if(cases == 1){ //This is the case when inventory is reduced
    	temp = currNode;
    	prevNode->next = currNode->next;
    	if(currNode->next != NULL){
   	   currNode->next->prev = prevNode;
   	}
     }
     else if(cases == 2){ //This is the case when inventory is increased
        temp = prevNode;
        if(prevNode->prev != NULL){
        prevNode->prev->next = currNode;
        currNode->prev = prevNode->prev;
      }
        else{
          head = currNode;
          currNode->prev = NULL;
      }
    }
  }
  else{
    return;
  }

  currNode = head;
  prevNode = NULL;

  while(currNode != NULL){
     if(temp->prodData->getUnits() < currNode->prodData->getUnits())
       break;
     prevNode = currNode;
     currNode = currNode->next;
  }

  if(prevNode == NULL){
    head = temp;
  } 
  else{
    prevNode->next = temp;
  }
  temp->next = currNode;
  temp->prev = prevNode;
  if(currNode != NULL){
     currNode->prev = temp;
  }
}

Product* ProdList::find(int id){
  Node* currNode = head;
  Node* prevNode = NULL;

  while (currNode != NULL) {
    if (currNode->prodData->getId() == id) 
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }
  if(currNode == NULL){
    return NULL;
  }
  return currNode->prodData;
}

void ProdList::toString(string& outstr){
  outstr = "";
  string str = "";
  stringstream ss;
  Node* currNode = head;
  
  while(currNode->next != NULL){
    currNode->prodData->getExpiryDate().toString(str);
    ss << currNode->prodData->getId() << "  " << setw(40) << currNode->prodData->getName() << "  " << setw(10) << currNode->prodData->getSize() <<"  " << setw(4) << currNode->prodData->getUnits() <<  "    $" << setw(6) << fixed << setprecision(2) << currNode->prodData->getPrice() << "    " << setw(10) << str <<  ",";
    str = "";
    currNode = currNode->next;
  }

  //This is the tail
  currNode->prodData->getExpiryDate().toString(str);
  ss << currNode->prodData->getId() << "  " << setw(40) << currNode->prodData->getName() << "  " << setw(10) << currNode->prodData->getSize() <<"  " << setw(4) << currNode->prodData->getUnits() <<  "    $" << setw(6) << fixed << setprecision(2) << currNode->prodData->getPrice() << "    " << setw(10) << str << ",";

  outstr = ss.str();
}
