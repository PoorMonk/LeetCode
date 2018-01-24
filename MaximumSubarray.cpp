/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int result = INT_MIN;
		int iSize = nums.size();
		if (iSize == 0) return result;
		if (iSize == 1) return nums[0];
		for (int i = 0; i < iSize; ++i)
		{
			int iSum = nums[i];
			int iMax = iSum;
			for (int j = i + 1; j < iSize; ++j)
			{
				iSum += nums[j];
				if (iMax < iSum)
				{
					iMax = iSum;
				}
			}
			if (result < iMax)
			{
				result = iMax;
			}
		}
		return result;
	}

	int maxSubArray2(vector<int>& nums)
	{
		int ans = nums[0], i, j, sum = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			sum += nums[i];
			ans = max(sum, ans);
			sum = max(sum, 0);
		}
		return ans;
	}
};

void test()
{
	vector<int> vec = { -2,1,-3,4,-1,2,1,-5,4 };
	Solution s;
	cout << "Maximum num is: " << s.maxSubArray2(vec) << endl;
}

int main()
{
	test();
	return 0;
}
