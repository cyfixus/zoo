#include "tiger.hpp"

Tiger::Tiger()
{
  this->age = 365;
  this->cost = 10000;
  this->numBabies = tigerBabies;
  this->foodCost = baseFoodCost*5.0;
  this->payoff = cost*0.2;
}