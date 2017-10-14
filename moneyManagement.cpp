#include "zoo.hpp"

void Zoo::calcProfits()
{
  int profit = totalPayoff();
  std::cout << "\n--------------------------------------\n"
            << ">  >  >  End of Day Report <  <  < \n"
            << "Day: " << day;
  bankStatement();
  std::cout << "\nTigers: " << tigerCount 
            << "\tprofit: $" << tigerPayoff()
            << "\nPenguins: " << penguinCount 
            << "\tprofit: $" << penguinPayoff()
            << "\nTurtles: " << turtleCount 
            << "\tprofit: $" << turtlePayoff();
  if(bonus)
  {
    profit += tigerBonus();
    std::cout <<"\n\nTiger Bonus: $" << tigerBonus();
    bonus = false;
  }
  std::cout << "\n\nTotal Profit: $" <<  profit;
  adjustBalance(profit);
  bankStatement();
  std::cout << "\n--------------------------------------\n"; 
}

void Zoo::adjustBalance(double change)
{
  bank += change;
}

double Zoo::tigerBonus()
{
  double bonusValue = 0;
  for(int tiger = 0; tiger < tigerCapacity; tiger++)
  {
    if(tigers[tiger].getCost() != 0)
    {
      bonusValue += (rand() % 500 + 250);
    }
  }
  return bonusValue;
}

double Zoo::totalPayoff()
{
  double profit = tigerPayoff() + penguinPayoff() + turtlePayoff();
  return profit;
}

double Zoo::tigerPayoff()
{
  double profit = 0;
  for(int tiger = 0; tiger < tigerCapacity; tiger++)
  {
    profit += tigers[tiger].getPayoff();
  }
  return profit;
}

double Zoo::penguinPayoff()
{
  double profit = 0;
  for(int penguin = 0; penguin < penguinCapacity; penguin++)
  {
    profit += penguins[penguin].getPayoff();
  }
  return profit;
}

double Zoo::turtlePayoff()
{
  double profit = 0;
  for(int turtle = 0; turtle < turtleCapacity; turtle++)
  {
    profit += turtles[turtle].getPayoff();
  }
  return profit;
}

double Zoo::totalFoodCost()
{
  double cost = tigerFoodCost() + penguinFoodCost() + turtleFoodCost();
  return cost;
}

double Zoo::tigerFoodCost()
{
  double cost = 0;
  for(int tiger = 0; tiger < tigerCapacity; tiger++)
  {
    cost += tigers[tiger].getFoodCost();
  }
  return cost;
}

double Zoo::penguinFoodCost()
{
  double cost = 0;
  for(int penguin = 0; penguin < penguinCapacity; penguin++)
  {
    cost += penguins[penguin].getFoodCost();
  }
  return cost;
}

double Zoo::turtleFoodCost()
{
  double cost = 0;
  for(int turtle = 0; turtle < turtleCapacity; turtle++)
  {
    cost += turtles[turtle].getFoodCost();
  }
  return cost;
}
