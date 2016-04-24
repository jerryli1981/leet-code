// compute the depth of a tree

#import <iostream>
#import <cstddef>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	int getTreeDepth(TreeNode* head){

		if(head == NULL)
			return 0;

		int leftDepth = getTreeDepth(head->left);
		int rightDepth = getTreeDepth(head->right);

		return (leftDepth > rightDepth) ? (leftDepth+1):(rightDepth+1);

	}
};

int main(){


	TreeNode* root = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);

	root->left = node2;
	root->right = node3;

	node2->left = node4;
	node2->right = node5;

	node3->right= node6;
	node5->left = node7;


	Solution s;

	std::cout << s.getTreeDepth(root) << std::endl;

}