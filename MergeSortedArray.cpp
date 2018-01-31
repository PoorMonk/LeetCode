/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	void Merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		vector<int> nums3;
		int index1 = 0, index2 = 0;
		for (int i = 0; i < m + n; ++i)
		{
			int num1 = index1 < m ? nums1[index1] : INT_MAX;
			int num2 = index2 < n ? nums2[index2] : INT_MAX;
			if (num1 < num2)
			{
				index1++;
				nums3.push_back(num1);
			}
			else
			{
				index2++;
				nums3.push_back(num2);
			}
		}
		nums1 = nums3;
	}
};

void print(vector<int> nums)
{
	for (auto num : nums)
	{
		cout << num << " ";
	}
	cout << "\n";
}

void test()
{
	vector<int> nums1 = {1, 3, 5, 7, 9};
	vector<int> nums2 = {2, 4, 6, 8, 10};
	Solution s;
	s.Merge(nums1, nums1.size(), nums2, nums2.size());
	print(nums1);
}

int main()
{
	test();
	return 0;
}
