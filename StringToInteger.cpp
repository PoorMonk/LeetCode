/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input 
cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input 
requirements up front.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	int myAtoi(string str)
	{
		long long result = 0;
		bool isNorP = true;
		bool bFlag = false;
		bool getNum = false;
		for (int i = 0; i < str.length(); ++i)
		{
			if ('9' < str[i] || str[i] < '0')
			{
				if (!getNum)
				{
					if (str[i] == ' ')
					{
						if (bFlag)
						{
							return 0;
						}
						continue;
					}
					else if (str[i] == '-')
					{
						if (bFlag) return 0;
						bFlag = true;
						isNorP = false;
					}
					else if (str[i] == '+')
					{
						if (bFlag) return 0;
						bFlag = true;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					break;
				}
			}
			else
			{
				getNum = true;
				result = result * 10 + str[i] - '0';
				if (result > INT_MAX) break;
			}												
		}
		return isNorP ? (result > INT_MAX ? INT_MAX : result) : (-result < INT_MIN ? INT_MIN : -result);
	}
};

void test()
{
	string str = "  -123";
	Solution s;
	cout << s.myAtoi(str) << endl;
}

int main()
{
	test();
	return 0;
}
