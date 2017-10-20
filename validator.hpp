/******************************************************************************
 * Author: Sean Foster                                          <validator.hpp>
 * Date: 10/13/2017
 * Description: Validator prototypes, the function uses string functions like
 *              at(), length() so I included the using directive here, I also 
 *              used the isdigit() function located in cctype
******************************************************************************/
#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP
#include <cctype>
#include <string>
#include <stdexcept>

using std::string;

bool isValidInt(string);
int getValidInt(string);
bool isValidDouble(string);
double getValidDouble(string);

#endif