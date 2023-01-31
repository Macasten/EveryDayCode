/**
 * @file <FILE_NAME>.cpp
 * @author Filipe Goncalves (filipe.r.l.goncalves@gmail.com)
 * @brief Test of pointers to function;
 * @version 0.1
 * @date <DATA>
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <bits/stdc++.h>

void DefaultFunction(int input)
{
  std::cout << "Default function: " << input << std::endl;
};

class Things
{
private:
  std::function<void(int)> insideFunc;

public:
  Things();

  void setInsideFunc(std::function<void(int)> newFunction);
  void showFunctionResult(int input, std::function<void(int)> func = nullptr);
  void showFunctionWithDefault(int input, std::function<void(int)> func = DefaultFunction);
};

Things::Things() {}

void Things::setInsideFunc(std::function<void(int)> newFunction)
{
  insideFunc = newFunction;
}

void Things::showFunctionResult(int input, std::function<void(int)> func)
{
  if (func)
  {
    std::cout << "Input Function: " << std::endl;
    func(input);
  }
  else
  {
    std::cout << "Inside Function:" << std::endl;
    insideFunc(input);
  }
}

void Things::showFunctionWithDefault(int input, std::function<void(int)> func)
{
  func(input);
};

int main()
{

  std::cout << "!!Playground!!" << std::endl;
  // Playground Start

  Things thing;
  thing.setInsideFunc([](int input)
                      { std::cout << "Set function: " << input << std::endl; });
  thing.showFunctionResult(2);
  thing.showFunctionResult(3, [](int input)
                           { std::cout << "New function: " << input << std::endl; });
  thing.showFunctionWithDefault(4);
  thing.showFunctionWithDefault(5, [](int input)
                                { std::cout << "Without default function: " << input << std::endl; });
  // Playground Ended
  return 0;
}