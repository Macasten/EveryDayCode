#ifndef PRINT_H
#define PRINT_H

////////////////////////////////////////////////////////////////////////////////
// c++ libraries
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

////////////////////////////////////////////////////////////////////////////////
// Personal Helpers
////////////////////////////////////////////////////////////////////////////////

#include "ListNode.h"

////////////////////////////////////////////////////////////////////////////////
// Fuctions
////////////////////////////////////////////////////////////////////////////////
void print_label(std::string label)
{
  std::cout << label << ": ";
}

template <typename T>
void print_vector(const std::vector<T> &vec, std::string label = "VECTOR")
{
  print_label(label);

  if (vec.empty())
  {
    std::cout << "EMPTY" << std::endl;
    return;
  }

  std::cout << "{\n";

  for (auto ve : vec)
  {
    std::cout << ve << std::endl;
  }

  std::cout << "}" << std::endl;
}

template <typename T>
void print_grid(const std::vector<std::vector<T>> &grid, std::string label = "GRID")
{
  print_label(label);
  if (grid.empty())
  {
    std::cout << "EMPTY" << std::endl;
    return;
  }

  std::cout << "\n{\n";
  for (const auto row : grid)
  {
    std::cout << "  {";
    for (const auto column : row)
    {
      std::cout << column << ",";
    }
    std::cout << "}\n";
  }
  std::cout << "}\n";
}

template <typename T, typename U>
void print_map(const std::map<T, U> &map, std::string label = "MAP")
{
  print_label(label);
  if (map.empty())
  {
    std::cout << "EMPTY" << std::endl;
  }

  std::cout << "\n"
            << std::endl;
  for (const auto it : map)
  {
    std::cout << "Key: " << it.first << " Value: " << it.second << std::endl;
  }
}

void print_listNode(ListNode *list, std::string label = "LIST_NODE")
{
  print_label(label);
  if (list == nullptr)
  {
    std::cout << "EMPTY" << std::endl;
  }

  std::cout << "\n";
  while (true)
  {
    std::cout << list->val;
    if (list->next == nullptr)
      break;
    std::cout << " -> ";
    list = list->next;
  }
  std::cout << std::endl;
}
#endif /* PRINT_H */