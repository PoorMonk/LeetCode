/*
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() <= 1)
		{
			return nums.size();
		}
		vector<int>::iterator it = nums.begin();
		for (vector<int>::iterator it2 = it + 1; it2 != nums.end(); ++it2)
		{
			if (*it == *it2)
			{
				it2 = nums.erase(it2);
				it = --it2;
			}
			else
			{
				++it;
			}
		}
		return nums.size();
	}

	//这个方法没有删除原来数组里的重复元素，只是统计了非重复元素的个数
	int removeDuplicates2(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int count = 1;
		int curr = nums[0];
		for (int i = 1; i < nums.size(); ++i)
			if (curr != nums[i])
			{
				nums[count++] = nums[i];
				curr = nums[i];
			}
		return count;
	}
};

int main()
{
	vector<int> vecN = {1, 1, 1, 2,};
	Solution s;
	cout << "length: " << s.removeDuplicates2(vecN) << endl;
	for (auto num : vecN)
	{
		cout << num << " ";
	}
	cout << "\n";
	return 0;
}


