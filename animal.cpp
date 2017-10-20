/******************************************************************************
 * Author: Sean Foster                                             <animal.cpp>
 * Date: 10/13/2017
 * Description: Animal definition
******************************************************************************/
#include "animal.hpp"

Animal::Animal()
{

}

/******************************************************************************
 * intAge is called on a new day to increase each animals age
******************************************************************************/
int Animal::incAge()
{
  return ++(this->age);
}

/******************************************************************************
 * toDays converts an int representing years to an int representing days.
******************************************************************************/
int Animal::toDays(int years)
{
  return years*365;
}

/******************************************************************************
 * toYears takes an int in days and returns the age in years
******************************************************************************/
int Animal::toYears(int age)
{
  return age/365;
}

/******************************************************************************
 * clear sets all the values to zero, this helps keep track of the real animals
 * and those that are just Animal objects filling in the allocated memory
******************************************************************************/
void Animal::clear()
{
  this->age = 0;
  this->cost = 0;
  this->payoff = 0;
  this->foodCost = 0;
}

/******************************************************************************
 * setters and getters for age and getter for cost, foodCost and payoff, all of
 * which are set in the specicies specific classes
******************************************************************************/
void Animal::setAge(int age)
{
  this->age = age;
}

int Animal::getAge()
{
  return this->age;
}

int Animal::getCost()
{
  return this->cost;
}

double Animal::getFoodCost()
{
  return this->foodCost;
}

double Animal::getPayoff()
{
  return this->payoff;
}