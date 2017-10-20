/******************************************************************************
 * Author: Sean Foster                                             <turtle.cpp>
 * Date: 10/13/2017
 * Description: Turtle definition, initializes variables according to species
******************************************************************************/
#include "turtle.hpp"

Turtle::Turtle()
{
  this->age = 365;
  this->cost = turtleCost;
  this->numBabies = turtleBabies;
  this->foodCost = baseFoodCost*0.5;
  this->payoff = cost*0.05;
}
