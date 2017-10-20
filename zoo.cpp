/******************************************************************************
 * Author: Sean Foster                                                <zoo.cpp>
 * Date: 10/13/2017
 * Description: Zoo class constructor and functions to conduct daily operations
******************************************************************************/
#include "zoo.hpp"

Zoo::Zoo()
{
  this->day = 0;
  this->bank = 22330.0;
  this->tigerCapacity = 10;
  this->turtleCapacity = 10;
  this->penguinCapacity = 10;
  this->tigerCount = 0;
  this->penguinCount = 0;
  this->turtleCount = 0;
  this->tigers = new Tiger[tigerCapacity];
  this->penguins = new Penguin[penguinCapacity];
  this->turtles = new Turtle[turtleCapacity];
  this->bonus = false;
  this->keepPlaying = true;
  clearZoo();
  zooIntro();
}

/******************************************************************************
 * zooIntro prints out an ascii zoo sign signifying the proud new ownership
 * with a little info on the available money and price of animals.
******************************************************************************/
void Zoo::zooIntro()
{
  std::cout << "\t______________________________\n"
            << "\t|   ______  ______  ______   |\n"
            << "\t|   |__  /  | __ |  | __ |   |\n"
            << "\t|    /  /_  | || |  | || |   |\n"
            << "\t|   /____|  |____|  |____|   |\n"
            << "\t|   ______________________   |\n"
            << "\t|  |                      |  |\n"
            << "\t|  |* * * NEW OWNERS * * *|  |\n"
            << "\t|//|                      |/*|\n\n"
            << "You are the proud owner of a zoo!\n You have $" << bank
            << " starting cash.... spend it wisely!\n\n"
            << "You will have the opportunity to purchase up to 2 of "
            << "each animal.\n\nTiger: $10000\tPenguin: $1000\tTurtle: $100\n";
}

/******************************************************************************
 * zooStatus gives a brief overview of what day it is and how many animals are
 * present in the zoo, as well as a print out of the bank statement
******************************************************************************/
void Zoo::zooStatus()
{
  std::cout << "\n--------------------------------------\n"
            << ">  >  >  ZOO STATUS <  <  < \n"
            << "Day: " << day;
  std::cout << "\nTigers: " << tigerCount
            << "\nPenguins: " << penguinCount
            << "\nTurtles: " << turtleCount; 
  bankStatement();
  std::cout << "\n--------------------------------------\n"; 
}

/******************************************************************************
 * purchaseDay is the first day of owning the zoo, the user is informed of the
 * max numbers of purchasable animals for the day, and purchaseAnimal is called
 * with that max number, 2.
******************************************************************************/
void Zoo::purchaseDay()
{

  std::cout << "\nWelcome to your first day as a ZOO owner!\n"
            << "You may purchase up to 2 of each animal today\n";
  purchaseAnimals(2);
}

/******************************************************************************
 * newDay prints a message to notify the user of and inc the day
******************************************************************************/
void Zoo::newDay()
{
  std::cout << "\n >  >  >  Welcome to Day " << ++day << "  <  <  <\n";
}

/******************************************************************************
 * feedAnimals gathers and prints out the info on the number of animals and 
 * total cost per food per animal, adjustBalance is then called subtracting
 * the total food cost, and the new bank total is printed.
******************************************************************************/
void Zoo::feedAnimals()
{
  std::cout << "\n--------------------------------------\n"
            << ">  >  >  Daily Food Cost <  <  < \n"
            << "Day: " << day;
  bankStatement();
  std::cout << "\nTigers: " << tigerCount 
            << "\n\tFood Cost: $" << tigerFoodCost()
            << "\nPenguins: " << penguinCount
            << "\n\tFood Cost: $" << penguinFoodCost()
            << "\nTurtles: " << turtleCount
            << "\n\tFood Cost: $" << turtleFoodCost()
            << "\nTotal Food Cost: $" << totalFoodCost();
  adjustBalance(-totalFoodCost());
  bankStatement();
  std::cout << "\n--------------------------------------\n"; 
}

/******************************************************************************
 * wantQuit is called at the end of each day, if at the end of the day the user
 * has no money (they wont be able to buy food the next day), the user is asked
 * if they want to play again, in the normal case this function asks the player
 * if they want to continue.
******************************************************************************/
void Zoo::wantQuit()
{
  if(bank <= 0)
  {
    std::cout << "\n\nSorry you ran out of money =(\n";
    zooStatus();
    keepPlaying = false;
  }
  else
  {
    char inChar;
    std::cout << "\n\nWould you like to continue? n to quit, any other key"
              << " to continue play\n";
    if(std::cin)
    {
      std::cin.ignore();
    }       
    inChar = std::cin.get();
    if(inChar == 'n' || inChar == 'N')
    {
      zooStatus();
      std::cout << "\nThank you for playing!\n";
      keepPlaying = false;
    }
  }
}

/******************************************************************************
 * game calls the purchase day function to start filling the zoo, and then the
 * daily loop begins until the bank is 0 or keepPlaying is set to false
 * newDay is called to print out the day, age animals ages the animals one day,
 * feed animals subtracts the food cost per animal from the bank, randomevent
 * causes a random event to occur, calcprofits figures out how much money was
 * made during the day and adds that total to the bank, purchaseAnimals is
 * called with a 0 to signify there is no max to the number of animals that
 * can be purchased, after the purchasing is complete the user is asked to 
 * continue or quit, if they quit the loop is exited and the zoo is deleted
******************************************************************************/
void Zoo::game()
{
  purchaseDay();
  while(bank > 0 && keepPlaying)
  {
    //new day
    newDay();
    //increase age
    ageAnimals();
    //feed
    feedAnimals();
    //random event
    randomEvent();
    //profit calc
    calcProfits();
    //new animal?
    purchaseAnimals(0);
    //keep playing?
    wantQuit();
  }
  killZoo();
}