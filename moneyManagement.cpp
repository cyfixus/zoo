/******************************************************************************
 * Author: Sean Foster                                    <moneyManagement.cpp>
 * Date: 10/13/2017
 * Description: Zoo class functions to manage and report funds
******************************************************************************/
#include "zoo.hpp"

/******************************************************************************
 * bankStatement prints out the current bank value
******************************************************************************/
void Zoo::bankStatement()
{
  std::cout << "\n\tBank: $" << bank << std::endl; 
}


/******************************************************************************
 * calProfits prints out an end of day report, and gathers the payoff amounts
 * from each animal to print next to the number of each species. if the bonus
 * flag is set to true, the tigerbonus is calculated and added to the total
 * and the flag is set to false. the total profit is printed then added to
 * the bank and the bank  is reprinted
******************************************************************************/
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

/******************************************************************************
 * adjustBalance takes in the double change and adds it to the bank
******************************************************************************/
void Zoo::adjustBalance(double change)
{
  bank += change;
}


/******************************************************************************
 * tigerBonus calculates a bonus, from 250 - 500 per real tiger and returns
 * that total bonus
******************************************************************************/
double Zoo::tigerBonus()
{
  double bonusValue = 0.0;
  for(int tiger = 0; tiger < tigerCapacity; tiger++)
  {
    if(tigers[tiger].getCost() != 0)
    {
      bonusValue += (rand() % 500 + 250);
    }
  }
  return bonusValue;
}

/******************************************************************************
 * totalPayoff adds all the individual species payoffs and returns it
******************************************************************************/
double Zoo::totalPayoff()
{
  double profit = tigerPayoff() + penguinPayoff() + turtlePayoff();
  return profit;
}

/******************************************************************************
 * tigerPayoff calculates the animals total payoff based on the getPayOff()
 * return call
******************************************************************************/
double Zoo::tigerPayoff()
{
  double profit = 0;
  for(int tiger = 0; tiger < tigerCapacity; tiger++)
  {
    profit += tigers[tiger].getPayoff();
  }
  return profit;
}

/******************************************************************************
 * penguinPayoff calculates the animals total payoff based on the getPayOff()
 * return call
******************************************************************************/
double Zoo::penguinPayoff()
{
  double profit = 0;
  for(int penguin = 0; penguin < penguinCapacity; penguin++)
  {
    profit += penguins[penguin].getPayoff();
  }
  return profit;
}

/******************************************************************************
 * turtlePayoff calculates the animals total payoff based on the getPayOff()
 * return call
******************************************************************************/
double Zoo::turtlePayoff()
{
  double profit = 0;
  for(int turtle = 0; turtle < turtleCapacity; turtle++)
  {
    profit += turtles[turtle].getPayoff();
  }
  return profit;
}


/******************************************************************************
 * totalFoodCost returns the total of the calls to each animals foodcost
******************************************************************************/
double Zoo::totalFoodCost()
{
  double cost = tigerFoodCost() + penguinFoodCost() + turtleFoodCost();
  return cost;
}


/******************************************************************************
 * tigerFoodCost calculates animals total foodCost based on the getFoodcost()
 * return call
******************************************************************************/
double Zoo::tigerFoodCost()
{
  double cost = 0;
  for(int tiger = 0; tiger < tigerCapacity; tiger++)
  {
    cost += tigers[tiger].getFoodCost();
  }
  return cost;
}

/******************************************************************************
 * penguinFoodCost calculates animals total foodCost based on the getFoodcost()
 * return call
******************************************************************************/
double Zoo::penguinFoodCost()
{
  double cost = 0;
  for(int penguin = 0; penguin < penguinCapacity; penguin++)
  {
    cost += penguins[penguin].getFoodCost();
  }
  return cost;
}

/******************************************************************************
 * turtleFoodCost calculates animals total foodCost based on the getFoodcost()
 * return call
******************************************************************************/
double Zoo::turtleFoodCost()
{
  double cost = 0;
  for(int turtle = 0; turtle < turtleCapacity; turtle++)
  {
    cost += turtles[turtle].getFoodCost();
  }
  return cost;
}
