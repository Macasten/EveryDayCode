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

class Things
{
public:
  int data{0};
  Things(){};

  void set(int i)
  {
    static bool once = [this](int value)
    {
      std::cout << "set" << std::endl;
      this->data = value;
      return true;
    }(i);
  };

  void showData()
  {
    std::cout << "Data: " << data << std::endl;
  };
};

void foo()
{
  static bool once = []()
  {
    std::cout << "once" << std::endl;
    return true;
  }();
  std::cout << "foo" << std::endl;
}

int main()
{

  std::cout << "!!Playground!!" << std::endl;
  // Playground Start
  foo();
  foo();

  Things thing1;
  Things thing2;

  thing1.showData();
  thing2.showData();

  thing1.set(1);
  thing1.set(2);
  thing1.set(3);
  thing1.showData();
  thing2.showData();

  thing2.set(2);
  thing1.showData();
  thing2.showData();

  // Playground Ended
  return 0;
}