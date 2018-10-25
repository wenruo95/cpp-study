#include<iostream>
#include<stdlib.h>
#include<stdio.h>
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

typedef struct _ListNode {
	int val;
	struct _ListNode *next;
} ListNode;

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *head = NULL, *tail = NULL;
        ListNode *key1 = pHead1, *key2 = pHead2;
        while(key1 != NULL && key2 != NULL) {
            if (key1->val > key2->val) {
                if (head == NULL) {
                    head = key2; tail = key2;
                } else {
                    tail->next = key2;
                    tail = key2;
                }
                key2 = key2->next;
            } else {
                if (head == NULL) {
                    head = key1; tail = key1;
                } else {
                    tail->next = key1;
                    tail = key1;
                }
                key1 = key1->next;
            }
        }
        if (head == NULL) {
            head = (key1 == NULL) ? key2 : key1;
        } else {
            tail->next = (key1 == NULL) ? key2 : key1;
        }
        return head;
    }
};

int main(void) {
	ListNode *list1_head, *list1_tail;

	ListNode *node1 = (ListNode *) malloc(sizeof(ListNode));
	node1->val = 3;
	node1->next = NULL;

	ListNode *node2 = (ListNode *) malloc(sizeof(ListNode));
	node2->val = 5;
	node2->next = NULL;

	ListNode *node3 = (ListNode *) malloc(sizeof(ListNode));
	node3->val = 8;
	node3->next = NULL;

	ListNode *node4 = (ListNode *) malloc(sizeof(ListNode));
	node4->val = 2;
	node4->next = NULL;

	ListNode *node5 = (ListNode *) malloc(sizeof(ListNode));
	node5->val = 5;
	node5->next = NULL;

	ListNode *node6 = (ListNode *) malloc(sizeof(ListNode));
	node6->val = 7;
	node6->next = NULL;

	node1->next = node2;
	node2->next = node3;

	node4->next = node5;
	node5->next = node6;

	Solution solution;

	ListNode *result = solution.Merge(node1, node4);
	while(result != NULL) {
		std::cout << result->val << std::endl;
		result = result->next;
	}


}



