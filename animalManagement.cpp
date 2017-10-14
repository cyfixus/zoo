/******************************************************************************
 * Author: Sean Foster                                   <animalManagement.cpp>
 * Date: 10/13/2017
 * Description: Zoo class functions for adding and removing zoo animals
******************************************************************************/
#include "zoo.hpp"

void Zoo::doubleTigerCage()
{
  int newSize = tigerCapacity*2;
  Tiger *newTigers = new Tiger[newSize];
  emptyCage(newTigers, newSize);
  for(int tiger = 0; tiger < tigerCapacity; tiger++)
  {
    newTigers[tiger] = tigers[tiger];
  }
  delete [] tigers;
  tigers = newTigers;
  tigerCapacity = newSize;
}

void Zoo::doublePenguinCage()
{
  int newSize = penguinCapacity*2;
  Penguin *newPenguins = new Penguin[newSize];
  emptyCage(newPenguins, newSize);
  for(int penguin = 0; penguin < penguinCapacity; penguin++)
  {
    newPenguins[penguin] = penguins[penguin];
  }
  delete [] penguins;
  penguins = newPenguins;
  penguinCapacity = newSize;
}

void Zoo::doubleTurtleCage()
{
  int newSize = turtleCapacity*2;
  Turtle *newTurtles = new Turtle[newSize];
  emptyCage(newTurtles, newSize);
  for(int turtle = 0; turtle < turtleCapacity; turtle++)
  {
    newTurtles[turtle] = turtles[turtle];
  }
  delete [] turtles;
  turtles = newTurtles;
  turtleCapacity = newSize;
}

void Zoo::purchaseAnimals(int maxQuantity)
{
  purchaseAnimal(0, maxQuantity);
  purchaseAnimal(1, maxQuantity);
  purchaseAnimal(2, maxQuantity);
}

void Zoo::purchaseAnimal(int animal, int maxQuantity)
{
  string userInput = "";
  int choice = 0;
  int age;
  if(maxQuantity == 2)
  {
    age = 1;
  }
  else
  {
    age = 3;
  }
  switch(animal)
  {
    case 0:
      std::cout << "How many Tigers, for $" << tigerCost 
                << " each, would you like?\n";
      break;
    case 1:
      std::cout << "How many Penguins, for $" << penguinCost 
                << " each, would you like?\n";
      break;
    case 2:
      std::cout << "How many Turtles, for $" << turtleCost 
                << " each, would you like?\n";
      break;
  }
  std::cin >> userInput;
  if(isValidInt(userInput))
  {
    choice = getValidInt(userInput);
    if(choice < 0 || (choice > maxQuantity && maxQuantity !=0))
    {
      choice = 0;
      purchaseAnimal(animal, maxQuantity);
    }
  }
  for(int i = 0; i < choice; i++)
  {
    switch(animal)
    {
      case 0:
        if(!addTiger(age, false))
        {
          choice = 0;
        }
        break;
      case 1:
        if(!addPenguin(age, false))
        {
          choice = 0;
        }
        break;
      case 2:
        if(!addTurtle(age, false))
        {
          choice = 0;
        }
        break;
    }
  }
}

void Zoo::ageAnimalsOneDay(Animal *animals, int capacity)
{
  for(int animal = 0; animal < capacity; animal++)
  {
    if(animals[animal].getCost() != 0)
    {
      animals[animal].incAge();
    }
  }
}

void Zoo::ageAnimals()
{
  ageAnimalsOneDay(tigers, tigerCapacity);
  ageAnimalsOneDay(penguins, penguinCapacity);
  ageAnimalsOneDay(turtles, turtleCapacity);

}

void Zoo::addAnimal(Animal animal, Animal *animals, int animalIndex)
{
  animals[animalIndex] = animal;
  updateCounts();
}

bool Zoo::addTiger(int age, bool baby)
{
  Tiger tiger;
  tiger.setAge(tiger.toDays(age));
  int cost = tiger.getCost();
  if((bank - cost) <= 0)
  {
    if(!baby)
    {
      std::cout << "\nSorry you don't have enough money to buy a Tiger\n"
                << "Tiger's cost: $" << tigerCost << ", you only have $"
                << bank << ".\nMaybe you can buy a Tiger tomorrow!\n";  
    }
    return false;
  }
  else
  {
    if(tigerCount >= tigerCapacity)
    {
      std::cout << "\nUpgrading Tiger Cage\n";
      doubleTigerCage();
      addTiger(age, baby);
    }
    else
    {
      if(!baby)
      {
        this->bank -= cost;
        std::cout << "\nYou purchased a tiger for $" << cost; 
        bankStatement();
      }
      else
      {
        std::cout << "\nA baby Tiger has been born!\n"; 
      }
      addAnimal(tiger, tigers, tigerCount);
    }
  }
  return true;
}

bool Zoo::addPenguin(int age, bool baby)
{
  Penguin penguin;
  penguin.setAge(penguin.toDays(age));
  int cost = penguin.getCost();
  if((bank - cost) <= 0)
  {
    if(!baby)
    {
      std::cout << "\nSorry you don't have enough money to buy a Penguin\n"
                << "Penguin's cost: $" << penguinCost << ", you only have $"
                << bank << ".\nMaybe you can buy a Penguin tomorrow!\n";
    }
    return false;
  }
  else
  {
    if(penguinCount >= penguinCapacity)
    {
      std::cout << "\nUpgrading Penguin Cage\n";
      doublePenguinCage();
      addPenguin(age, baby);
    }
    else
    {
      if(!baby)
      {
        this->bank -= cost;
        std::cout << "\nYou purchased a penguin for $" << cost; 
        bankStatement();
      }
      else
      {
        std::cout << "\nA baby Penguin has been born!\n"; 
      }
      addAnimal(penguin, penguins, penguinCount);
    }
  }
  return true;
}

bool Zoo::addTurtle(int age, bool baby)
{
  Turtle turtle;
  turtle.setAge(turtle.toDays(age));
  int cost = turtle.getCost();
  if((bank - cost) <= 0)
  {
    if(!baby)
    {
      std::cout << "\nSorry you don't have enough money to buy a Turtle\n"
                << "Turtle's cost: $" << turtleCost << ", you only have $"
                << bank << ".\nMaybe you can buy a Turtle tomorrow!\n";
    }
    return false;
  }
  else
  {
    if(turtleCount >= turtleCapacity)
    {
      std::cout << "\nUpgrading Turtle Cage\n";
      doubleTurtleCage();
      addTurtle(age, baby);
    }
    else
    {
      if(!baby)
      {
        this->bank -= cost;
        std::cout << "\nYou purchased a turtle for $" << cost;
        bankStatement();
      }
      else
      {
        std::cout << "\nA baby Turtle has been born!\n"; 
      }
      addAnimal(turtle, turtles, turtleCount); 
    }
  }
  return true;
}

void Zoo::removeAnimal(Animal *animals, int animalIndex)
{
  animals[animalIndex].clear();
  updateCounts();
}

bool Zoo::removeTiger()
{
  if(tigerCount > 0)
  {
    std::cout << "\n =(\ta tiger has perished\n";
    removeAnimal(tigers, tigerCount - 1);
    return true;
  }
  return false;
}

bool Zoo::removePenguin()
{
  if(penguinCount > 0)
  {
    std::cout << "\n =(\ta penguin has perished\n";
    removeAnimal(penguins, penguinCount - 1);
    return true;  
  }
  return false;
}

bool Zoo::removeTurtle()
{
  if(turtleCount > 0)
  {
    std::cout << "\n =(\ta turtle has perished\n";
    removeAnimal(turtles, turtleCount - 1);
    return true;
  }
  return false;
}

void Zoo::emptyCage(Animal *animals, int capacity)
{
  for(int animal = 0; animal < capacity; animal++)
  {
    removeAnimal(animals, animal);
  }
}

void Zoo::clearZoo()
{
  emptyCage(tigers, tigerCapacity);
  emptyCage(penguins, penguinCapacity);
  emptyCage(turtles, turtleCapacity);
}

void Zoo::killZoo()
{
  delete []tigers;
  delete []penguins;
  delete []turtles;
}
void Zoo::updateCounts()
{
  updateTigerCount();
  updatePenguinCount();
  updateTurtleCount();
}

void Zoo::updateTigerCount()
{
  tigerCount = 0;
  for(int tiger = 0; tiger < tigerCapacity; tiger++)
  {
    if(tigers[tiger].getCost() != 0)
    {
      tigerCount++;
    }
  }
}

void Zoo::updatePenguinCount()
{
  penguinCount = 0;
  for(int penguin = 0; penguin < penguinCapacity; penguin++)
  {
    if(penguins[penguin].getCost() != 0)
    {
      penguinCount++;
    }
  }
}

void Zoo::updateTurtleCount()
{
  turtleCount = 0;
  for(int turtle = 0; turtle < turtleCapacity; turtle++)
  {
    if(turtles[turtle].getCost() != 0)
    {
      turtleCount++;
    }
  }
}