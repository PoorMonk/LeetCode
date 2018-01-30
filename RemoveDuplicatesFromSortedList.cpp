/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (!head) return NULL;
		ListNode* cNode = head->next;
		ListNode* temp = cNode ? cNode->next : NULL;
		while (temp)
		{
			if (cNode->val == temp->val)
			{
				ListNode* lnode = temp;
				cNode->next = lnode->next;
				delete lnode;
				temp = cNode->next;
			}
			else
			{
				cNode = temp;
				temp = temp->next;
			}
		}
		return head;
	}
};

void print(ListNode* head)
{
	ListNode* tmp = head->next;
	while (tmp)
	{
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << "\n";
}

void rmList(ListNode* head)
{
	ListNode* temp = head->next;
	while (temp)
	{
		ListNode* node = temp;
		temp = temp->next;
		delete node;
	}
}

void test()
{
	ListNode *head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(1);
	//head->next->next->next = new ListNode(2);
	//head->next->next->next->next = new ListNode(3);
	//head->next->next->next->next->next = new ListNode(3);
	print(head);
	Solution s;
	ListNode* result = s.deleteDuplicates(head);
	print(result);
	rmList(result);
}

int main()
{
	test();
	return 0;
}
