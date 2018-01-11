#include <iostream>
using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of 
their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL){}
};

int getListLength(ListNode* l)
{
	if (l == NULL)
	{
		return 0;
	}
	int len = 0;
	ListNode* temp = l;
	while (temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	return len;
}

class Solution
{
public:
	//第一种自己写的(在原有的链表上修改，没有重新开辟一个链表空间)  不够精简
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int len1 = getListLength(l1);
		int len2 = getListLength(l2);

		ListNode* minL = len1 > len2 ? l2 : l1;
		ListNode* maxL = len1 > len2 ? l1 : l2;
		ListNode *temp1 = maxL, *temp2 = maxL;
		int iFlag = 0;
		for (; minL != NULL;)
		{
			int i1 = minL->val;
			int i2 = maxL->val;
			maxL->val = (i1 + i2 + iFlag) % 10;
			if (10 <= i1 + i2 + iFlag)
			{

				iFlag = 1;
			}
			else
			{
				iFlag = 0;
			}

			temp2 = maxL;
			minL = minL->next;
			maxL = maxL->next;

		}
		while (iFlag)
		{
			if (temp2->next == NULL)
			{
				temp2->next = new ListNode(iFlag);
				break;
			}
			else
			{
				temp2 = temp2->next;
				if (10 <= temp2->val + iFlag)
				{
					temp2->val = 0;
					iFlag = 1;
				}
				else
				{
					temp2->val += iFlag;
					iFlag = 0;
				}
			}

		}
		return temp1;
	}

	//第二种参考网上的
	ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2)
	{
		ListNode* first;
		ListNode* start = new ListNode(0);
		first = start;
		int offset = 0;
		while (l1 || l2 || offset)
		{
			int value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + offset;
			offset = value / 10;
			start->next = new ListNode(value % 10);
			start = start->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return first->next;
	}
};

void deleteList(ListNode* ln)
{
	while (ln != NULL)
	{
		ListNode* t = ln;
		ln = ln->next;
		delete t;
	}
}

int main()
{
	ListNode* head1 = new ListNode(2);
	head1->next = new ListNode(4);
	head1->next->next = new ListNode(5);
	//head1->next->next->next = new ListNode(3);
	//ListNode* temp = head1;

	ListNode* head2 = new ListNode(5);
	head2->next = new ListNode(6);
	head2->next->next = new ListNode(4);
	head2->next->next->next = new ListNode(9);
	head2->next->next->next->next = new ListNode(9);

	Solution s;
	ListNode* temp = s.addTwoNumbers2(head1, head2);
	while (temp != NULL)
	{
		cout << temp->val << " ";
		temp = temp->next;

	}

	
	deleteList(head1);
	deleteList(head2);
	deleteList(temp);
}
