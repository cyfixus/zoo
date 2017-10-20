/******************************************************************************
 * Author: Sean Foster                                             <events.cpp>
 * Date: 10/20/2017
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
    //tiger bonus
    attendenceBoom();
  }
  else if(eventChoice >= 29 && eventChoice <= 51)
  {
    //trys to find an animal to give birth
    if(!newBaby(false))
    {
      randomEvent();
    }
  }
  else if(eventChoice >= 52 && eventChoice <= 74)
  { 
    //kills one random animal
    if(!killAnimal())
    {
      randomEvent();
    }
  }
  else if(eventChoice >= 75 && eventChoice <= 81)
  { //wipe out a species, if you get too many tigers you'll never lose
    killSpecies();
  }
  else if(eventChoice >=82 && eventChoice <= 88)
  { //big money bonus
    zooBoom();
  }
  else if(eventChoice >= 89 && eventChoice <= 95)
  {
    //double birth
    if(!newBaby(true))
    {
      randomEvent();
    }
  }
  else if(eventChoice == 99)
  {
    std::cout <<"\n\n** YOUR ENTIRE ZOO HAS BEEN WIPED OUT BY DISEASE **\n\n";
    clearZoo();
  }
  else
  {
    //peaceful day message
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

void Zoo::zooBoom()
{
  dblBoom = true;
  std::cout << "\n  >  >  Congratulations on record attendance!!  <  <\n"
            << "\tYour exhibits earned you some extra cash today!\n";
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
