#include <iostream>
#include "Test.hpp"

static int number{0};

void show()
{
  std::cout << "Number: " << number << std::endl;
}

void increment()
{
  number++;
}