/******************************************************************************
 * Author: Sean Foster                                              <tiger.cpp>
 * Date: 10/13/2017
 * Description: Tiger definition, initializes variables according to species
******************************************************************************/
#include "tiger.hpp"

Tiger::Tiger()
{
  this->age = 365;
  this->cost = tigerCost;
  this->numBabies = tigerBabies;
  this->foodCost = baseFoodCost*5.0;
  this->payoff = cost*0.2;
}