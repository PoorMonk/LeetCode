/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> sc;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
			{
				sc.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
			{
				char c;
				c = (s[i] == ')') ? '(' : ' ';
				c = (s[i] == ']') ? '[' : ' ';
				c = (s[i] == '}') ? '{' : ' ';
				if (!sc.empty() && c == sc.top())
				{
					sc.pop();
				}
				else
				{
					return false;
				}
			}
		}
		if (sc.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	Solution s;
	string str = "()";
	if (s.isValid(str))
	{
		cout << "Valid..." << endl;
	}
	else
	{
		cout << "Invalid..." << endl;
	}
}
