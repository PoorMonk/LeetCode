/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.


Example:

Input: "cbbd"

Output: "bb"
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		if (s.length() <= 1) return s;
		string str;
		int iLength = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			for (int j = s.length(); j > i; --j)
			{
				string sub = s.substr(i, j);
				if (sub == getReverseStr(sub))
				{
					if (sub.length() > iLength)
					{
						str = sub;
						iLength = sub.length();
					}
					break;
				}
			}
		}
		return str;
	}

	string longestPalindrome2(string s)
	{
		//以遍历的当前字符为中点，向两边扩展比较
		if (s.length() <= 1) return s;
		int min_start = 0, max_len = 1;
		for (int i = 0; i < s.length(); )
		{
			if (s.size() - i <= max_len / 2) break;
			int j = i, k = i;
			while (k < s.length() - 1 && s[k + 1] == s[k]) ++k;
			i = k + 1;
			while (k < s.length() - 1 && j > 0 && s[k + 1] == s[j - 1])
			{
				k++;
				j--;
			}
			int new_len = k - j + 1;
			if (new_len > max_len)
			{
				min_start = j;
				max_len = new_len;
			}
		}
		return s.substr(min_start, max_len);
	}

private:
	string getReverseStr(string s)
	{
		string str;
		for (int i = s.length() - 1; i >= 0; --i)
		{
			str += s[i];
		}
		return str;
	}
};

void test()
{
	Solution s;
	string str = "babad";
	cout << s.longestPalindrome2(str) << endl;
}

int main()
{
	test();
	return 0;
}
