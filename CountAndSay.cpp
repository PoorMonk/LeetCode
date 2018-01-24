/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		if (n < 1) return "";
		string str = "1";
		for (int i = 1; i < n; ++i)
		{
			str = __say(str);
		}
		return str;
	}

private:
	string __say(string str)
	{
		string lstr;
		int iCount = 0;
		char c = str[0];
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == c)
			{
				iCount++;
			}
			else
			{
				lstr += to_string(iCount) + c;
				iCount = 1;
				c = str[i];
			}
		}
		if (iCount)
		{
			lstr += to_string(iCount) + c;
		}
		return lstr;
	}
};

void test()
{
	int n = 4;
	Solution s;
	for (int n = 1; n < 10; ++n)
	{
		cout << n << ": " << s.countAndSay(n) << endl;
	}
	
}

void test2()
{
	multimap<int, int> mmap;
	mmap.insert(make_pair(1, 3));
	mmap.insert(make_pair(2, 2));
	mmap.insert(make_pair(1, 2));
	for (map<int, int>::iterator it = mmap.begin(); it != mmap.end(); ++it)
	{
		cout << "key: " << it->first << ", value: " << it->second << endl;
	}
}

int main()
{
	test();
	return 0;
}
