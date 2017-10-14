#include "animal.hpp"

Animal::Animal()
{

}

int Animal::getAge()
{
  return this->age;
}

int Animal::incAge()
{
  return ++(this->age);
}

void Animal::setAge(int age)
{
  this->age = age;
}

int Animal::getCost()
{
  return this->cost;
}

int Animal::toDays(int years)
{
  return years*365;
}

int Animal::toYears(int age)
{
  return age/365;
}

double Animal::getFoodCost()
{
  return this->foodCost;
}

double Animal::getPayoff()
{
  return this->payoff;
}

void Animal::clear()
{
  this->age = 0;
  this->cost = 0;
  this->payoff = 0;
  this->foodCost = 0;
}