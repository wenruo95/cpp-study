#include<iostream>
#include<list>

using std::list;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode *list1,ListNode *list2) {
		ListNode *t = NULL,**tail = &t;
		int x = 0, y = 0, carry = 0;
		ListNode *temp1 = list1,*temp2 = list2;
		while(temp1 != NULL || temp2 != NULL) {
			if (temp1 != NULL) {
				x = temp1->val;
				temp1 = temp1->next;
			} else {
				x = 0;
			}
			if (temp2 != NULL) {
				y = temp2->val;
				temp2 = temp2->next;
			} else {
				y = 0;
			}
			carry += x + y;
			ListNode *node = new ListNode(carry % 10);
			*tail = node;
			tail = &(node->next);
			carry = carry / 10;
		}
		if (carry > 0) {
			ListNode *node = new ListNode(carry % 10);
			*tail = node;
		}
		return t;
	}
};

// 2->4->3
// 5->6->4
// output:7->0->8 :: 342+465 = 807
int main(void) {
	ListNode *node1 = new ListNode(2);
	ListNode *node2 = new ListNode(4);
	ListNode *node3 = new ListNode(3);
	node1->next = node2;
	node2->next = node3;

	ListNode *node4 = new ListNode(5);
	ListNode *node5 = new ListNode(6);
	ListNode *node6 = new ListNode(4);
	node4->next = node5;
	node5->next = node6;

	Solution solution;
	ListNode *node7 = solution.addTwoNumbers(node1,node4);
	ListNode *node8 = node7;
	while(node8 != NULL) {
		std::cout << node8->val << "\t";
		node8 = node8->next;
	}
	std::cout << std::endl;
}




