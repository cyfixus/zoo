/******************************************************************************
 * Author: Sean Foster                                               <menu.cpp>
 * Date: 10/10/2017
 * Description: Menu function displays input string as options list. 
 *              optionCount ensures a valid selection can be returned.
******************************************************************************/
#include "menu.hpp"

int menu(string menuOptions, int optionCount)
{
  string choice = "";
  int selection = 0;
  std::cout << menuOptions; 
  std::cin >> choice;
  if(isValidInt(choice))
  {
    selection = getValidInt(choice);
    if(selection > 0 && selection <= optionCount)
    {
      return selection;
    }
    else
    {
      //I kept running into issues if I pressed 0 enter, enter, then a valid
      //choice, this ignore seems to have fixed it
      if(std::cin)
      {
        std::cin.ignore();
      }    
      menu(menuOptions, optionCount);
    }
  }
  return 0;
}