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
  Things();
};

std::function<std::vector<int>(int)> mul()
{
  std::vector<int> data;
  return [data](int input) mutable -> std::vector<int>
  {
    data.insert(data.end(), input);
    return data;
  };
};

Things::Things() {}

int main()
{

  std::cout << "!!Playground!!" << std::endl;
  // Playground Start
  auto func = mul();
  auto func2 = mul();
  std::cout << func(2).size() << std::endl;
  func2(6);
  std::cout << func(3).size() << std::endl;
  std::cout << func(4).size() << std::endl;
  std::cout << func(5).size() << std::endl;
  // Playground Ended
  return 0;
}