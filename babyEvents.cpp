/******************************************************************************
 * Author: Sean Foster                                         <babyEvents.cpp>
 * Date: 10/13/2017
 * Description: Zoo class baby-related events
******************************************************************************/
#include "zoo.hpp"

/******************************************************************************
 * addBabies takes in the number of babies to add and an int to represent which
 * specices of animal to add to and alls the class specific add the babies
******************************************************************************/
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


/******************************************************************************
 * findParent loops through whichever Animal array is passed to the function
 * determining whether or not there is an animal of age (3) to give birth.
 * if a suitableParent is found, the addBabies is alled on that species
******************************************************************************/
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

/******************************************************************************
 * newBaby randomly chooses one of the species to call findParent and 
 * subsequently new baby on.
******************************************************************************/
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