#include "NonPerishable.h"

NonPerishable::NonPerishable(){
}

Date NonPerishable::computeExpDate(Date manufacturedDate, int lifespan){  
  Date expiry = manufacturedDate + lifespan;
  return expiry;
}
