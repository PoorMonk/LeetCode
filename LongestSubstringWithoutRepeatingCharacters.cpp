/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	static int lengthOfLongestSubstring(string s)
	{
		int iLength = 1;
		if (s == "") return 0;
 		int curLength = 1, beginIndex = 0;
		for (int i = 1; i < s.length(); ++i)
		{
			bool bflag = true;
			for (int j = beginIndex; j < i; ++j)
			{
				if (s[j] == s[i])
				{
					beginIndex = j + 1;
					curLength = i - j;
					bflag = false;
					break;
				}
			}
			if (bflag) curLength++;
			iLength = iLength > curLength ? iLength : curLength;
		}
		return iLength;
	}
};

void test()
{
	string s = "pwwkew";
	cout << "length: " << Solution::lengthOfLongestSubstring(s) << endl;
}

int main()
{
	test();
	return 0;
}
