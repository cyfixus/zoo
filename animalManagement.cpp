/******************************************************************************
 * Author: Sean Foster                                   <animalManagement.cpp>
 * Date: 10/20/2017
 * Description: Zoo class functions for adding and removing zoo animals
******************************************************************************/
#include "zoo.hpp"

/******************************************************************************
 * doubleTigerCage creates an int representing twice the current array size
 * a new Tiger pointer array is created  and then emptied( all tiger values
 * set to 0), then the tigers from the original cage are copied into the
 * correpsonding positions of the new Tiger point array, once the old values 
 * are coppied the old tigers is deallocated and repointed to the newTigers
 * then tigerCapcaity is set tothe new capacity
******************************************************************************/
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
/******************************************************************************
 * doublePenguin and Turtle work the same way, I was hoping to make a more
 * versatile function, but I couldn't get it to work, so I gave up for the sake
 * of getting something working for now with hopes of addressing and putting 
 * these three functions into one.
******************************************************************************/
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


/******************************************************************************
 * purchaseAnimals takes in an int representative of the max quantity...which
 * is really only used for the initial purchase, and calls purchaseAnimal
 * for each species
******************************************************************************/
void Zoo::purchaseAnimals(int maxQuantity)
{
  purchaseAnimal(0, maxQuantity);
  purchaseAnimal(1, maxQuantity);
  purchaseAnimal(2, maxQuantity);
}

/******************************************************************************
 * purchaseAnimal takes in an int to represent the species of desired animal 
 * and maxQuantity is used to tell whether or not this is the first day of 
 * purchase in which only two of each animal may be obtained. maxQuantity is
 * also used to set the age, since animals purchased on day 1 are all 1 year
 * old and animals purchased any other day are 3 (child-bearing age). The
 * user is prompted to choose how many of each animal to purchase and the
 * user's chioce is validated and passed to the appropriate addAnimal call
******************************************************************************/
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

/******************************************************************************
 * ageAnimalsOneDay takes in a point to animals and the capacity of that 
 * species and as long as the animal is real (i used cost as the value to check
 * which is set to 0 for any animal that hasn't been added by the user
 * valid animal's ages are increased by one day.
******************************************************************************/
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


/******************************************************************************
 * ageAnimals calls ageAnimalsOneDay for each species
******************************************************************************/
void Zoo::ageAnimals()
{
  ageAnimalsOneDay(tigers, tigerCapacity);
  ageAnimalsOneDay(penguins, penguinCapacity);
  ageAnimalsOneDay(turtles, turtleCapacity);

}


/******************************************************************************
 * addAnimal adds a newly created (purchased or birthed) Animal to its
 * corresponding species array and then calls updateCounts to make sure
 * no count has gotten out of order
******************************************************************************/
void Zoo::addAnimal(Animal animal, Animal *animals, int animalIndex)
{
  animals[animalIndex] = animal;
  updateCounts();
}

/******************************************************************************
 * addTiger creates a new Tiger, sets its age to the passed age, and if its not
 * a baby, determines whether or not the player can afford to purchase the
 * tiger and goes through the process of adding the tiger, first checking to
 * see if there is enough room in the cage, doubling if necessary, and then
 * printing out a message, subtracting the cost of the tiger from the bank
 * and outputting the new bank balance, if the tiger being added is a baby, the
 * financials are skipped and the player is informed of the birth before 
 * addAnimal adds the tiger to the  tigers array. returns true if a tiger can
 * be added, false if not
******************************************************************************/
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
      // doubleCage(tigers, 0);
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


/******************************************************************************
 * addpenguin creates a new penguin, sets its age to the passed age, if its not
 * a baby, determines whether or not the player can afford to purchase the
 * penguin and conducts the process of adding the penguin, first checking to
 * see if there is enough room in the cage, doubling if necessary, and then
 * printing out a message, subtracting the cost of the penguin from the bank
 * and outputting the new bank balance, if the penguin being added is a baby,
 * financials are skipped and the player is informed of the birth before 
 * addAnimal adds the tiger to the  penguins array. returns true if penguin can
 * be added, false if not
******************************************************************************/
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
      // doubleCage(penguins, 1);
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


/******************************************************************************
 * addturtle creates a new turtle, sets its age to the passed age, if its not
 * a baby, determines whether or not the player can afford to purchase the
 * turtle and conducts the process of adding the turtle, first checking to
 * see if there is enough room in the cage, doubling if necessary, and then
 * printing out a message, subtracting the cost of the turtle from the bank
 * and outputting the new bank balance, if the turtle being added is a baby,
 * financials are skipped and the player is informed of the birth before 
 * addAnimal adds the turtle to the  turtles array. returns true if penguin can
 * be added, false if not
******************************************************************************/
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
      // doubleCage(turtles, 2);
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

/******************************************************************************
 * removeAnimal goes to the particular animal in its animals array and calls
 * clear to zero out the values and then updateCounts to take it into account
******************************************************************************/
void Zoo::removeAnimal(Animal *animals, int animalIndex)
{
  animals[animalIndex].clear();
  updateCounts();
}

/******************************************************************************
 * removeTiger gets rid of one if there are any to get rid of, a message is
 * output to signify the animal has perished and removeAnimal is called
 * returing true.
******************************************************************************/
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

/******************************************************************************
 * removePenguin gets rid of one if there are any to get rid of, a message is
 * output to signify the animal has perished and removeAnimal is called
 * returing true.
******************************************************************************/
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

/******************************************************************************
 * removeTurtle gets rid of one if there are any to get rid of, a message is
 * output to signify the animal has perished and removeAnimal is called
 * returing true.
******************************************************************************/
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

/******************************************************************************
 * emptyCage iterates through the passed in animals array calling remove animal
 * on each animal to clear its values
******************************************************************************/
void Zoo::emptyCage(Animal *animals, int capacity)
{
  for(int animal = 0; animal < capacity; animal++)
  {
    removeAnimal(animals, animal);
  }
}

/******************************************************************************
 * clearZoo calls emptyCage for each species
******************************************************************************/
void Zoo::clearZoo()
{
  emptyCage(tigers, tigerCapacity);
  emptyCage(penguins, penguinCapacity);
  emptyCage(turtles, turtleCapacity);
}

/******************************************************************************
 * killZoo deallocates the animals arrays
******************************************************************************/
void Zoo::killZoo()
{
  delete []tigers;
  delete []penguins;
  delete []turtles;
}

/******************************************************************************
 * updateCounts calls the species specific updateCounts functions
******************************************************************************/
void Zoo::updateCounts()
{
  updateTigerCount();
  updatePenguinCount();
  updateTurtleCount();
}

/******************************************************************************
 * updateTigerCount iterates through the animal's array and increments the 
 * count if any animal does't have 0'd out cost variables 
******************************************************************************/
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

/******************************************************************************
 * updatePenguinCount iterates through the animal's array and increments the 
 * count if any animal does't have 0'd out cost variables 
******************************************************************************/
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


/******************************************************************************
 * updateTurtleCount iterates through the animal's array and increments the 
 * count if any animal does't have 0'd out cost variables 
******************************************************************************/
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


/******************************************************************************
 * doubleCage was supposed to be the one function to double any cage... but I
 * can't figure out why it doesn't work all the time. I'm going to leave it
 * incase i decide to try on it again
******************************************************************************/
// void Zoo::doubleCage(Animal *animals, int species)
// {
//   int newSize = 0;
//   int capacity = 0;
//   Animal *newCage;
//   switch(species)
//   {
//     case 0:
//       newSize = tigerCapacity*2;
//       capacity = tigerCapacity;
//       tigerCapacity = newSize;
//       newCage = new Tiger[newSize];
//       break;
//     case 1:
//       newSize = penguinCapacity*2;
//       capacity = penguinCapacity;
//       penguinCapacity = newSize;
//       newCage = new Penguin[newSize];
//       break;
//     case 2:
//       newSize = turtleCapacity*2;
//       capacity = turtleCapacity;
//       turtleCapacity = newSize;
//       newCage = new Turtle[newSize];
//       break;
//   }
//   emptyCage(newCage, newSize);
//   for(int i = 0; i < capacity; i++)
//   {
//     newCage[i] = animals[i];
//   }
//   delete [] animals;
//   animals = newCage;
// }