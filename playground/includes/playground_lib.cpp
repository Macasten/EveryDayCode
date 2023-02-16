#include <iostream>

#include "playground_lib.hpp"

PlaygroundObject::PlaygroundObject(){};

PlaygroundObject::~PlaygroundObject(){};

void PlaygroundObject::HelloWorld()
{
  std::cout << "Playground Object: Hello World " << std::endl;
};