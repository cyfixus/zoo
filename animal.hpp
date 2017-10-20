/******************************************************************************
 * Author: Sean Foster                                             <animal.hpp>
 * Date: 10/13/2017
 * Description: Animal declaration, constants defined
******************************************************************************/
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define baseFoodCost 10
#define tigerCost 10000
#define penguinCost 1000
#define turtleCost 100
#define tigerBabies 1
#define penguinBabies 5
#define turtleBabies 10

class Animal
{

  protected: 
    int age;
    int cost;
    int numBabies;
    double foodCost;
    double payoff; 

  public:
    Animal();
    int getAge();
    int incAge();
    void setAge(int);
    int getCost();
    int toDays(int);
    int toYears(int);
    double getFoodCost();
    double getPayoff();
    void clear();
};

#endif