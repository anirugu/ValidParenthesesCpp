#include <iostream>
#include <string>
#include <stack>


using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stack;
		for (auto c : s) {
			if (c == '(' || c == '{' || c == '[') {
				stack.push(c);
			}
			else {
				if (stack.size() == 0)
					return false;
				if (c == ')' && stack.top() == '(') {
					stack.pop();
					continue;
				}
				else if (c == '}' && stack.top() == '{') {
					stack.pop();
					continue;
				}
				else if (c == ']' && stack.top() == '[') {
					stack.pop();
					continue;
				}
				else {
					return false;
				}
			}
		}
		if (stack.size() == 0)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution sol;
	auto valid1 = sol.isValid("()");
	auto valid2 = sol.isValid("()[]{}");
	auto valid3 = sol.isValid("(]");
	auto valid4 = sol.isValid("[");
}
/*

*/