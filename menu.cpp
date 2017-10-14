/**************************************
 * Author: Sean Foster
 * Date: 10/10/2017
 * Description: Menu function has been adjusted to take in a string
 *              to display the options list, intro, etc.. and an int
 *              to represent the number of options, so that a valid
 *              selection can be returned within the range, rather
 *              than adjusting this file each time.
**************************************/
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
      menu(menuOptions, optionCount);
    }
  }
  return 0;
}