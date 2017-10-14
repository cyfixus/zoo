/******************************************************************************
 * Author: Sean Foster                                            <penguin.cpp>
 * Date: 10/13/2017
 * Description: Penguin definition
******************************************************************************/
#include "penguin.hpp"

Penguin::Penguin()
{
  this->age = 365;
  this->cost = 1000;
  this->numBabies = penguinBabies;
  this->foodCost = baseFoodCost*1.0;
  this->payoff = cost*0.1;
}

Penguin::Penguin(int age)
{
  Penguin();
  this->age = age;
}