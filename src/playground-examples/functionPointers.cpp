/**
 * @file fuctionPointers.cpp
 * @author Filipe Goncalves (filipe.r.l.goncalves@gmail.com)
 * @brief Test of pointers to function;
 * @version 0.1
 * @date 2023-01-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <bits/stdc++.h>

class Things
{
public:
  Things();

  static int returnFive();
  static int returnFour();

  void setReturnFunction();

  int (*returnNumber)(void);
};

Things::Things()
{
  std::cout << "Things" << std::endl;
  returnNumber = &returnFour;
}

int Things::returnFive() { return 5; }

int Things::returnFour() { return 4; }

void Things::setReturnFunction()
{

  if (returnNumber == returnFour)
  {
    returnNumber = &returnFive;
  }
  else
  {
    returnNumber = &returnFour;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Function pointers - global
////////////////////////////////////////////////////////////////////////////////

int returnOne() { return 1; }
int (*globalReturnNumber)(void) = &returnOne;

int square(int num) { return num * num; }
int (*intActionFunction)(int) = &square;

int main()
{

  std::cout << "!!Playground!!" << std::endl;
  // Playground Start

  std::cout << "Function pointer" << std::endl;

  Things thing;
  // Default must return 4
  std::cout << thing.returnNumber() << std::endl;
  // Change of function pointer
  thing.setReturnFunction();
  // Must return 5
  std::cout << thing.returnNumber() << std::endl;
  // Another change of function pointer
  thing.setReturnFunction();
  // Must return 4
  std::cout << thing.returnNumber() << std::endl;

  std::cout << globalReturnNumber() << std::endl;
  std::cout << "Should be 1" << std::endl;
  globalReturnNumber = &thing.returnFive;
  std::cout << globalReturnNumber() << std::endl;
  std::cout << "Should be 5" << std::endl;

  std::cout << "Action Function: " << intActionFunction(2) << std::endl;
  // Playground Ended
  return 0;
}