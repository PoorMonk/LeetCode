#include <iostream>
	
using namespace std;
	
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *l3 = new ListNode(0);
        ListNode *head = l3;
        while (l1 || l2)
        {
            if (l1)
            {
                ListNode *newNode = new ListNode(l1->val);
                l3->next = newNode;
                l3 = newNode;
                l1 = l1->next;
            }
            if (l2)
            {
                ListNode *newNode = new ListNode(l2->val);
                l3->next = newNode;
                l3 = newNode;
                l2 = l2->next;
            }
        }
        return head->next;
    }
};

void print(ListNode* l)
{
    while (l)
    {
        cout << l->val << " ";
        l = l->next;
    }
    cout << "\n";
}

void freeList(ListNode* l)
{
    ListNode *head;
    while (l)
    {
        head = l;
        l = l->next;
        delete head;
    }
}

int main()
{
    Solution s;
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);


    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
	l2->next->next->next = new ListNode(5);
	l2->next->next->next->next = new ListNode(6);
    ListNode *l = s.mergeTwoLists(l1, l2);

    print(l);

    freeList(l1);
    freeList(l2);

    return 0;
}
