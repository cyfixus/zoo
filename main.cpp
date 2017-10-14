/******************************************************************************
 * Author: Sean Foster                                               <main.cpp>
 * Date: 10/13/2017
 * Description: Prompts menu to create a new instance of ZOO TYCOON or quit.
******************************************************************************/
#include "menu.hpp"
#include "zoo.hpp"

void newZoo()
{
  Zoo zoo;
  zoo.game();
}

int main()
{
  string zooString = "\n\t\tWelcome to ZOO TYCOON.\n"  
                      "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
                      "   Type the number of your choice to proceed:\n\n"
                      "1: Play game\n2: Exit game\n";
  while(menu(zooString, 2) == 1)
  {
    newZoo();
  }

  return 0;
}