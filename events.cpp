/******************************************************************************
 * Author: Sean Foster                                             <events.cpp>
 * Date: 10/13/2017
 * Description: Zoo class random events
******************************************************************************/
#include "zoo.hpp"

void Zoo::randomEvent()
{
  switch(rand() % 5)
  {
    case 0:
      if(killAnimal())
      {
        break;
      }
    case 1:
      attendenceBoom();
      break;
    case 2:
      if(newBaby())
      {
        break;
      }
    case 3:
      peacefulDay();
      break;
    case 4:
    default:
      killSpecies();
      break;
  }
}

void Zoo::peacefulDay()
{
  std::cout <<"\nThankfully you had a peacefulday\n All animals are safe\n";
}


void Zoo::attendenceBoom()
{
  bonus = true;
  std::cout << "\n  >  >  Congratulations on record attendance!!  <  <\n"
            << "\tThe tiger exhibit earned you some extra cash today!\n";
}

bool Zoo::killAnimal()
{
  switch(rand() % 3)
  {
    case 0:
      if(removeTiger())
      {
        return true;
      }
    case 1:
      if(removePenguin())
      {
        return true;
      }
    case 2:
      if(removeTurtle())
      {
        return true;
      }
  }
  return false;
}

bool Zoo::killSpecies()
{
  switch(rand() % 3)
  {
    case 0:
      std::cout << "\n * * A terrible disease has killed all the tigers!\n";
      emptyCage(tigers, tigerCapacity);
      return true;
    case 1:
      std::cout << "\n * * A terrible disease has killed all the penguins!\n";
      emptyCage(penguins, penguinCapacity);
      return true;
    case 2:
      std::cout << "\n * * A terrible disease has killed all the turtles!\n";
      emptyCage(turtles, turtleCapacity);
      return true;
  }
  return false;
}
