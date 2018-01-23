/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 1:

Input: [1,3,5,6], 0
Output: 0
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int iSize = nums.size();
		int i = 0;
		for (; i < iSize; ++i)
		{
			if (target <= nums[i])
			{
				break;
			}
		}
		return i;
	}

	int searchInsert2(vector<int>& nums, int target)
	{
		/*int lo = 0, hi = nums.size() - 1;
		if(hi >= 0 && nums[hi] < target)
			return hi + 1;
		while (lo < hi)
		{
			int mid = (lo + hi) / 2;
			if (target <= nums[mid])
			{
				hi = mid;
			}
			else
			{
				lo = mid;
			}
			if (lo + 1 == hi)
			{
				if (nums[lo] < target)
				{
					return lo + 1;
				}
				else
				{
					return lo;
				}
			}
		}
		return lo;*/

		int low = 0, high = nums.size()-1;

		// Invariant: the desired index is between [low, high+1]
		while (low <= high) {
			int mid = low + (high-low)/2;

			if (nums[mid] < target)
				low = mid+1;
			else
				high = mid-1;
		}
		return low;
	}
};

void test()
{
	Solution s;
	//vector<int> vec = { 1, 5, 5, 5, 6 };
	vector<int> vec = { 1, 3, 5, 7, 9 };
	int value = 4;
	cout << "Positon: " << s.searchInsert2(vec, value) << endl;
}

int main()
{
	test();
	return 0;
}
