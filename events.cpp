/******************************************************************************
 * Author: Sean Foster                                             <events.cpp>
 * Date: 10/13/2017
 * Description: Zoo class random events
******************************************************************************/
#include "zoo.hpp"

/******************************************************************************
 * randomEvent calls rand() to get a random number from 0 to 100, that int is
 * then checked within weighted ranges of possible random events
******************************************************************************/
void Zoo::randomEvent()
{
  const int eventChoice = rand() % 100;
  if(eventChoice >= 0 && eventChoice <= 28)
  {
    attendenceBoom();
  }
  else if(eventChoice >= 29 && eventChoice <= 51)
  {
    if(!newBaby())
    {
      randomEvent();
    }
  }
  else if(eventChoice >= 52 && eventChoice <= 74)
  {
    if(!killAnimal())
    {
      randomEvent();
    }
  }
  else if(eventChoice >= 75 && eventChoice <= 81)
  {
    killSpecies();
  }
  else
  {
    peacefulDay();
  }
  //I decided to introduce a pause after the random event
  std::cout << "\n\nPress enter to continue...\n";
  if(std::cin)
  {
    std::cin.ignore();
  }
  std::cin.get();
}

/******************************************************************************
 * peacefulDay prints a message that all was quiet that day
******************************************************************************/
void Zoo::peacefulDay()
{
  std::cout <<"\nThankfully you had a peacefulday\n All animals are safe\n";
}


/******************************************************************************
 * attendenceBoom sets the bonus boolean to true, so the tiger bonus can be
 * added to the daily total
******************************************************************************/
void Zoo::attendenceBoom()
{
  bonus = true;
  std::cout << "\n  >  >  Congratulations on record attendance!!  <  <\n"
            << "\tThe tiger exhibit earned you some extra cash today!\n";
}


/******************************************************************************
 * killAnimal chooses a random animal to kill aka call remove on
******************************************************************************/
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

/******************************************************************************
 * killSpecies takes out an entire species, I added this after realizing that
 * if you don't lose any tigers, or lose tigers too slowly, you'll never lose
******************************************************************************/
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
