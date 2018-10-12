#include<iostream>
//#define DEBUG 0

#ifdef DEBUG

// 判断链表是否有环
// 链表如果有环从头遍历必定会一直在环处循环


// 方法一:
// a -> b -> c -> b
// a -> b -> c -> d -> b
// a -> b -> c -> d -> e -> b
// 有环链表如果分正常遍历和二倍速遍历，那么二倍速遍历必定会碰到正常遍历的

typedef struct Node {
	int val;
	Node *next;
} Node;

bool hasCycle(Node *head) {
	if (head == NULL || head->next == NULL) {
		return false;
	}
	Node *slow = head->next;
	Node *fast = slow->next;
	while (slow != NULL || fast != NULL) {
		if (slow == fast) {
			return true;
		}
		slow = slow->next;
		if (slow != NULL) {
			fast = slow->next;
		}
	}
	return false;
}


// 方法二：std::set
// 将每个节点地址转换为long 判断每个地址是否已存在，如果已存在则链表有环
bool hasCycle(Node *head) {
	std::set<long int> st;
	while (head != NULL) {
		long l = (long) &(*head);
		if (st.find(l) != st.end()) {
			return true
		}
		st.insert(l);
	}
	return false;
}

#endif

int main() {
	int i = 10;
	int j = 20;
	long l = (long) &i;
	long k = (long) &j;
	std::cout << i << std::endl;
	std::cout << l << std::endl;
	std::cout << k << std::endl;
}

