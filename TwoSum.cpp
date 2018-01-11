#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
	//自己写的，效率偏低
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vecIndex;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			/*if (target < nums[i])   此处没有考虑到负数的情况，不能这么判断
			{
				continue;
			}*/
			for (size_t j = i + 1; j < nums.size(); ++j)
			{
				if (target == nums[i] + nums[j])
				{
					vecIndex.push_back(i);
					vecIndex.push_back(j);
					return vecIndex;
				}
			}
		}
		return vecIndex;
	}

	//参考网上的
	vector<int> twoSum2(vector<int>& nums, int target)
	{
		unordered_map<int, int> umap;
		vector<int> vecResult;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (umap.find(target - nums[i]) != umap.end())
			{
				vecResult.push_back(umap[target - nums[i]]);
				vecResult.push_back(i);
			}
			umap[nums[i]] = i;
		}
		return vecResult;
	}
};

int main()
{
	vector<int> vecInt{ 2, 7, 11, 15 };
	Solution s;
	int target = 18;
	vector<int> vecResult = s.twoSum2(vecInt, target);

	for (auto it : vecResult)
	{
		cout << it << " ";
	}
	cout << endl;
	return 0;
}
