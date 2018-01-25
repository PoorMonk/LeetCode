/*
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			if (++digits[i] > 9)
			{
				digits[i] = 0;
			}
			else
			{
				return digits;
			}
		}
		digits[0] = 1;
		digits.push_back(0);
		return digits;
	}
};

void test()
{
	Solution s;
	vector<int> vec = { 1,3,5,7,9 };
	vector<int> res = s.plusOne(vec);
	for (auto num : res)
	{
		cout << num << " ";
	}
	cout << "\n";
}

int main()
{
	test();
	return 0;
}
