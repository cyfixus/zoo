/******************************************************************************
 * Author: Sean Foster                                             <turtle.hpp>
 * Date: 10/13/2017
 * Description: Turtle declaration
******************************************************************************/
#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "animal.hpp"

class Turtle : public Animal
{
  public:
    Turtle();
    Turtle(int);
};

#endif