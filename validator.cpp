/******************************************************************************
 * Author: Sean Foster                                          <validator.cpp>
 * Date: 10/13/2017
 * Description: Validates input string for int
******************************************************************************/
#include "validator.hpp"

/******************************************************************************
 * isValidInt takes in a string, and sets an iterator i to 0. this function 
 * accepts signed numbers by skipping the iterator ahead if the first 
 * character is the negative sign. each char of the string is iterated 
 * through,each char is validated as a digit, if neither, false is returned
******************************************************************************/
bool isValidInt(string checkString)
{
  int i = 0;
  if(checkString.at(i)=='-')
  {
    i++;
  }
  for(; i < (int)checkString.length(); i++)
  {
    if (!std::isdigit(checkString.at(i)))
    {
      return false;
    }
  }
  return true;
}

/******************************************************************************
 * getValidInt takes in a string, checks that its a valid int, then calls
 * std::stoi, to convert it to an int. caught exception returns -1
******************************************************************************/
int getValidInt(string checkString)
{
  int convertedInt = 0;
  if (isValidInt(checkString))
  {
    try{
      convertedInt = std::stoi(checkString, nullptr, 0);
      return convertedInt; 
    }
    catch (const std::out_of_range& oor)
    {
      return -1;
    }
  }
  return -1;
}

/******************************************************************************
 * isValidDouble takes in a string, sets a flag to track the dots in the string
 * to false, and an iterator i to 0. this function accepts signed numbers by
 * skipping the iterator ahead if the first character is the negative sign.
 * each char of the string is iterated through, first to determine if the char
 * is a dot, if so, the dotFlag is set to true, if the dot flag was already
 * set to true on a previous iteration, the function returns false. each char
 * is then validated as a digit or the dot, if neither, false is returned
******************************************************************************/
bool isValidDouble(string checkString)
{
  bool dotFlag = false;
  int i = 0;
  if(checkString.at(i)=='-')
  {
    i++;
  }
  for(; i < (int)checkString.length(); i++)
  {
    if(checkString.at(i) == '.')
    {
      if(dotFlag)
      {
        return false;
      }
      dotFlag = true;
    }
    if (!std::isdigit(checkString.at(i)) && checkString.at(i) != '.')
    {
      return false;
    }
  }
  return true;
}

/******************************************************************************
 * getValidDouble takes in a string, checks that its a valid double, then calls
 * std::stod, to convert it to a double. caught exception returns -1.0
******************************************************************************/
double getValidDouble(string checkString)
{
  double convertedDouble = 0.0;
  if (isValidDouble(checkString))
  {
    try{
      convertedDouble = std::stod(checkString, nullptr);
      return convertedDouble; 
    }
    catch (const std::out_of_range& oor)
    {
      return -1.0;
    }
  }
  return -1.0;
}