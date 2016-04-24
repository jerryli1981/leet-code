//Given a binary tree, output the postorder traversal. 
/* 
 *          1
 *         / \
 *        2   3
 *           /
 *          4
 *           \
 *            5
 */

#include <iostream>
#include <vector>

using std::vector;

struct TreeNode
{
	/* data */
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	void postorderTraversal(TreeNode* root, vector<int> &v){

		if (root == NULL)
			return;

		postorderTraversal(root->left, v);
		postorderTraversal(root->right, v);
		v.push_back(root->val);

	}

};


int main(){

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
  	s.postorderTraversal(&root, v);

  	for (auto i : v)
    	std::cout << i << " ";

  	std::cout << std::endl; 

  	return 0;

}