/******************************************************************************
 * Author: Sean Foster                                            <penguin.hpp>
 * Date: 10/13/2017
 * Description: Penguin declaration
******************************************************************************/
#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "animal.hpp"

class Penguin : public Animal
{
  public:
    Penguin();
    Penguin(int);
};

#endif