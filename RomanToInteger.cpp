/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int romanToInt(string s)
	{
		unordered_map<char, int> T = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		};
		int result = T[s.back()];
		for (/*size_t*/int i = s.length() - 2; 0 <= i; --i) //���������int,��size_tʱi<0ʱ�����
		{
			if (T[s[i]] < T[s[i+1]])
			{
				result -= T[s[i]];
			}
			else
			{
				result += T[s[i]];
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	string str = "CDXXI";
	cout << s.romanToInt(str) << endl;
	return 0;
}
