#include "zoo.hpp"

Zoo::Zoo()
{
  this->day = 0;
  this->bank = 100000.0;
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

void Zoo::bankStatement()
{
  std::cout << "\n\tBank: $" << bank << std::endl; 
}

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

void Zoo::purchaseDay()
{

  std::cout << "\nWelcome to your first day as a ZOO owner!\n"
            << "You may purchase up to 2 of each animal today\n";
  purchaseAnimals(2);
}

void Zoo::newDay()
{
  std::cout << "\n >  >  >  Welcome to Day " << ++day << "  <  <  <\n";
}

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

void Zoo::peacefulDay()
{
  std::cout <<"\nThankfully you had a peacefulday\n All animals are safe\n";
}

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

void Zoo::attendenceBoom()
{
  bonus = true;
  std::cout << "\n  >  >  Congratulations on record attendance!!  <  <\n"
            << "\tThe tiger exhibit earned you some extra cash today!\n";
}

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
    string userInput = "";
    std::cout << "\n\nWould you like to continue? n to quit, any other key"
              << " to continue play\n";
    std::cin >> userInput;
    if(userInput == "n" || userInput == "N")
    {
      zooStatus();
      std::cout << "\nThank you for playing!\n";
      keepPlaying = false;
    }
  }
}

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