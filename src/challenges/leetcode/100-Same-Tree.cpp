#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <utility>

#include "TreeNode.h"

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        else if( p == nullptr || q == nullptr ) return false;
        else {
        //     cout<< p-> val << " " << q->val << endl;
            if(p->val != q->val) return false;
            else{
                return !isSameTree(p->left, q->left) ? false : isSameTree(p->right, q->right);
            }
        }
    }
};

int main(){
  return 0;
}