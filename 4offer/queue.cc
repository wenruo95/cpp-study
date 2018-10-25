#include<iostream>
#include<stack>

using std::stack;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
		while(stack2.empty()) {
			while(!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
        int node = stack2.top();
        stack2.pop();
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
	Solution solution;
	solution.push(1);
	solution.push(2);
	solution.push(3);
	std::cout << solution.pop() << std::endl;
	std::cout << solution.pop() << std::endl;
	solution.push(4);
	std::cout << solution.pop() << std::endl;
	solution.push(5);
	std::cout << solution.pop() << std::endl;
	std::cout << solution.pop() << std::endl;
	/*
	solution.push(6);
	solution.push(7);
	std::cout << solution.pop() << std::endl;
	std::cout << solution.pop() << std::endl;
	std::cout << solution.pop() << std::endl;
	std::cout << solution.pop() << std::endl;
	std::cout << solution.pop() << std::endl;
	std::cout << solution.pop() << std::endl;
	*/
}
