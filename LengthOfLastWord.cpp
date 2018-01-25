/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	static int lengthOfLastWord(string s)
	{
		int iCount = 0, result = 0;
		//bool bFalg = false;
		for (int i = 0; i < s.length(); ++i)
		{
			if (' ' == s[i])
			{
				
				iCount = 0;
			}
			else
			{
				iCount++;
			}
			result = iCount ? iCount : result;
		}
		
		return result;
	}
};

void test()
{
	string str = " helloworldddd ";
	cout << str << " index of space: " << Solution::lengthOfLastWord(str) << endl;
}

int main()
{
	test();
	return 0;
}
