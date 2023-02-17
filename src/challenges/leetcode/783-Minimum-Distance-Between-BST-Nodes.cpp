////////////////////////////////////////////////////////////////////////////////
// c++ libraries
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

////////////////////////////////////////////////////////////////////////////////
// Personal Helpers
////////////////////////////////////////////////////////////////////////////////

#include "Print.h"
#include "TreeNode.h"
#include "ListNode.h"

////////////////////////////////////////////////////////////////////////////////
// Solution
////////////////////////////////////////////////////////////////////////////////
class Solution
{
private:
  int test{0};

public:
  Solution() {}

  void showChallengeTitle()
  {
    std::cout << "-------------------------------------------------------------\n";
    std::cout << "!! 783. Minimum Distance Between BST Nodes !!\n";
    std::cout << "-------------------------------------------------------------\n";
  }

  void startTest()
  {
    std::cout << "---------------" << std::endl;
    std::cout << "Test #" << test << std::endl;
    std::cout << "---------------" << std::endl;
    test++;
  }

  void endTest()
  {
    std::cout << "-- TEST ENDED --" << std::endl;
  }

  template <typename T>
  void resultValidation(const T &t, const T &r)
  {
    if (t == r)
      std::cout << "SUCCEED" << std::endl;
    else
      std::cout << "FAILED" << std::endl;
  }
  // Challenge code - START

  void getData(TreeNode *root, std::set<int> &data)
  {
    if (root == nullptr)
      return;
    data.insert(root->val);
    getData(root->left, data);
    getData(root->right, data);
  }

  int minDiffInSet(std::set<int> &data)
  {
    int min = std::numeric_limits<int>::max();

    std::set<int>::iterator btr = data.begin();
    std::set<int>::iterator etr = data.begin();
    etr++;
    while (etr != data.end())
    {
      int diff{*etr - *btr};
      if (diff < min)
        min = diff;
      if (min <= 1)
        break;

      etr++;
      btr++;
    }
    return min;
  }

  int minDiffInBST(TreeNode *root)
  {
    std::set<int> data;
    getData(root, data);

    return data.size() > 1 ? minDiffInSet(data) : *data.begin();
  }
  // Challenge code - ENDED
  void runMinDiffInBST(std::vector<std::string> tree, int expected)
  {
    auto treeRoot = TreeNode::buildTreeNode(tree);
    resultValidation(minDiffInBST(treeRoot), expected);
  }
};

////////////////////////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////////////////////////
int main()
{
  Solution solution;
  solution.showChallengeTitle();
  return 0;
}