// test whether a tree is balance binary tree.
//if the |left_depth - right_depth| <= 1, then the tree is balance tree.



#import <iostream>
#import <cstddef> //define NULL

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

	bool isBalanced(TreeNode* head){

		if (head == NULL)
			return true;

		int left = getTreeDepth(head->left);
		int right = getTreeDepth(head->right);

		int diff = left -right;

		if(diff > 1 || diff < -1)
			return false;

		return isBalanced(head->left) && isBalanced(head->right);
	}

	bool isBalanced(TreeNode* head, int* pDepth){
		if(head == NULL){
			*pDepth = 0;
			return true;
		}
		int left, right;
		if(isBalanced(head->left, &left) && isBalanced(head->right, &right)){
			int diff = left-right;
			if(diff <=1 || diff >= -1){
				*pDepth = 1 + (left > right ? left : right);
				return true;
			}
		}

		return false;

	}

	bool isBalanced_fast(TreeNode* head){
		int depth = 0;
		return isBalanced(head, &depth);
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
	std::cout << s.isBalanced_fast(root) << std::endl;

}