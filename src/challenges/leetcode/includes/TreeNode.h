#ifndef TREENODE_H
#define TREENODE_H

#include <vector>
#include <string>

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

  static void *buildTreeNode(TreeNode *root, const std::vector<std::string> &arr, int index)
  {
    if (root != nullptr)
    {
      if (2 * index + 1 < arr.size())
      {
        if (arr.at(2 * index + 1) == "null")
          root->left = nullptr;
        else
          root->left = new TreeNode(std::stoi(arr.at(2 * index + 1)));
        buildTreeNode(root->left, arr, 2 * index + 1);
      }

      if (2 * index + 2 < arr.size())
      {
        if (arr.at(2 * index + 2) == "null")
          root->right = nullptr;
        else
          root->right = new TreeNode(std::stoi(arr.at(2 * index + 2)));
        buildTreeNode(root->right, arr, 2 * index + 2);
      }
    }
  }

  static TreeNode *buildTreeNode(std::vector<std::string> arr)
  {
    if (arr.size() == 0)
      return nullptr;
    TreeNode *output = new TreeNode(std::stoi(arr.at(0)));
    buildTreeNode(output, arr, 0);
    return output;
  }
};
#endif /* TREENODE_H */