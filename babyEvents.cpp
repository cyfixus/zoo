/******************************************************************************
 * Author: Sean Foster                                         <babyEvents.cpp>
 * Date: 10/13/2017
 * Description: Zoo class random events
******************************************************************************/
#include "zoo.hpp"

void Zoo::addBabies(int babyCount, int species)
{
  for(int animal = 0; animal < babyCount; animal++)
  {
    switch(species)
    {
      case 0:
        addTiger(0, true);
        break;
      case 1:
        addPenguin(0, true);
        break;
      case 2:
        addTurtle(0, true);
        break;
    }
  }
}

bool Zoo::findParent(Animal *animals, int capacity, int species)
{
  for(int animal = 0; animal < capacity; animal++)
  {
    int age = animals[animal].toYears(animals[animal].getAge());
    if(age >= 3)
    {
      int babyCount = 0;
      switch(species)
      {
        case 0:
          babyCount = tigerBabies;
          break;
        case 1:
          babyCount = penguinBabies;
          break;
        case 2:
          babyCount = turtleBabies;
          break;
      }
      addBabies(babyCount, species);
      return true;
    }
  }
  return false;
}

bool Zoo::newBaby()
{
  switch(rand() % 3)
  {
    case 0:
      if(findParent(tigers, tigerCapacity, 0))
      {
        return true;;
      }
    case 1:
      if(findParent(penguins, penguinCapacity, 1))
      {
        return true;
      }
    case 2:
      if(findParent(turtles, turtleCapacity, 2))
      {
        return true;
      }
  }
  return false;
}