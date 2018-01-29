/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.


Example 1:

Input: 2
Output:  2
Explanation:  There are two ways to climb to the top.

1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output:  3
Explanation:  There are three ways to climb to the top.

1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

#include <iostream>

using namespace std;

class Solution
{
public:
	int climbStairs(int n)
	{
		if (n < 3)
		{
			return n;
		}
		//return climbStairs(n - 1) + climbStairs(n - 2);
		int sum = 0;
		int a = 1, b = 1;
		for (int i = 1; i < n; ++i)
		{
			sum = a + b;
			a = b;
			b = sum;
		}
		return sum > INT_MAX ? 0 : sum;
	}
};

void test()
{
	Solution s;
	int n = 44;
	cout << s.climbStairs(n) << endl;
}

int main()
{
	test();
	return 0;
}

