#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void lookNode(TreeNode* root, std::vector<int>& list){
    if(root == nullptr) return;
    list.push_back(root->val);
    lookNode(root->left, list);
    lookNode(root->right, list);
  }

  vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> output;
    lookNode(root, output);
    return output;
  }
};