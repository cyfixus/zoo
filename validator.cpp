/******************************************************************************
 * Author: Sean Foster                                          <validator.cpp>
 * Date: 10/10/2017
 * Description: Validates input string for int
******************************************************************************/
#include "validator.hpp"

/**************************************
 * isValidInt takes a string and goes through
 * each character checking if that position
 * contains a digit, returning false if it doesn't
 **************************************/
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

/********************************************
  *  I realized Monday morning that I never went back to simplify this function
  *  to call the boolean version, instead of redoing the whole thing. 
  *  then realized that I wasn't checking for a max size before 
  *  converting to a string and when I tried crazy long numbers I would get
  *  an out of range error I referred to cplusplus.com to structure the 
  *  catch argument to handle the error.
  *  returns a valid int, or -1(...effective only if requesting unsigned int).
  ******************************************/
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