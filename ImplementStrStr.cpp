/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		if (haystack == "" || needle == "" || haystack.size() < needle.size())
		{
			return -1;
		}
		int i= 0;
		for (; i < haystack.size(); ++i)
		{
			bool bFlag = false;
			if (haystack[i] == needle[0])
			{
				bFlag = true;
				for (int j = 1, k = i + 1; j < needle.size(); ++j, ++k)
				{
					if (haystack[k] != needle[j])
					{
						bFlag = false;
						break;
					}
				}
			}
			if (bFlag)
			{
				return i;
			}
		}
		return -1;
	}
};

void Test()
{
	Solution s;
	string haystack = "hello";
	string needle = "ll";
	cout << s.strStr(haystack, needle) << endl;
}

int main()
{
	Test();
	return 0;
}
