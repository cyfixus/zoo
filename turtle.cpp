/******************************************************************************
 * Author: Sean Foster                                             <turtle.cpp>
 * Date: 10/13/2017
 * Description: Turtle definition
******************************************************************************/
#include "turtle.hpp"

Turtle::Turtle()
{
  this->age = 365;
  this->cost = 100;
  this->numBabies = turtleBabies;
  this->foodCost = baseFoodCost*0.5;
  this->payoff = cost*0.05;
}

Turtle::Turtle(int age)
{
  Turtle();
  this->age = age;
}