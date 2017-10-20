/******************************************************************************
 * Author: Sean Foster                                            <penguin.cpp>
 * Date: 10/13/2017
 * Description: Penguin definition, initializes variables according to species
******************************************************************************/
#include "penguin.hpp"

Penguin::Penguin()
{
  this->age = 365;
  this->cost = penguinCost;
  this->numBabies = penguinBabies;
  this->foodCost = baseFoodCost*1.0;
  this->payoff = cost*0.1;
}