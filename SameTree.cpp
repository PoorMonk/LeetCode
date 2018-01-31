/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.


Example 1:

Input:       1         1
			/ \       / \
		   2   3     2   3

			[1,2,3],   [1,2,3]

			Output: true
Example 2:

Input:		 1         1
			/           \
			2             2

			[1,2],     [1,null,2]

			Output: false
Example 3:

Input:		 1         1
			/ \       / \
			2   1     1   2

			[1,2,1],   [1,1,2]

			Output: false
*/

#include <iostream>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

void rmTree(TreeNode* head);

class Solution
{
public:
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		if (!p && !q) return true;
		else if (p && q)
		{
			return (q->val == p->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
		}
		else return false;
	}
};

void test()
{
	TreeNode* head1 = new TreeNode(1);
	head1->left = new TreeNode(1);
	TreeNode* head2 = new TreeNode(1);
	head2->left = new TreeNode(1);
	Solution s;
	if (s.isSameTree(head1, head2))
	{
		cout << "Is same tree" << endl;;
	}
	else
	{
		cout << "not same..." << endl;
	}
	rmTree(head1);
	rmTree(head2);
}

void rmTree(TreeNode* head)
{
	if (!head) return;
	rmTree(head->left);
	rmTree(head->right);
	if (head)
	{
		delete head;
		head = nullptr;
	}
}

int main()
{
	test();
	return 0;
}
