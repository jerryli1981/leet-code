#include <iostream>
#include <vector>
#include <stack>

using std::vector; 
using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<TreeNode*> stack;
        vector<int> v;
        
        while(stack.size()>0 || root!=NULL){
            if (root!=NULL){
                stack.push_back(root);
                root = root->left;
            }else{
                if (stack.size()>0) {
                    root = stack.back();
                    stack.pop_back();
                    v.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return v;
    }

    void inorderTraversal(TreeNode *root, vector<int> &v){
        if (root == NULL) 
            return;
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
    }

};

/// Test Unit
/// {1,2,3,#,#,4,#,#,5}
/* 
 *          1
 *         / \
 *        2   3
 *           /
 *          4
 *           \
 *            5
 */

int main() {
  
  TreeNode root(1);
  TreeNode node2(2);
  TreeNode node3(3);
  TreeNode node4(4);
  TreeNode node5(5);
    
  root.left = &node2;
  root.right = &node3;
  node3.left = &node4;
  node4.right = &node5;
    
  Solution s;
  vector<int> v;
  s.inorderTraversal(&root, v);
  for (auto i : v)
    std::cout << i << " ";

  std::cout << std::endl; 
    
  return 0;
}