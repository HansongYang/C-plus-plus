#include "Perishable.h"

Perishable::Perishable(){
}

Date Perishable::computeExpDate(Date manufacturedDate, int lifespan){  
  Date expiry = manufacturedDate + lifespan;  
  return expiry;
}
