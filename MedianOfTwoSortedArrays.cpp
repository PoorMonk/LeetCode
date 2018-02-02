/*
here are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int> nums2)
	{
		int n1 = nums1.size(), n2 = nums2.size();
		int endIndex = (n1 + n2) / 2;
		int beginIndex = (n1 + n2) % 2 ? endIndex : endIndex - 1;
	
		int i = 0, j = 0, k = 0;
		int value1 = 0, value2 = 0;
		for (; k <= endIndex; k++)
		{
			int num1 = i < n1 ? nums1[i] : INT_MAX;
			int num2 = j < n2 ? nums2[j] : INT_MAX;
			int value = num1 < num2 ? nums1[i++] : nums2[j++];
			if (k == beginIndex) value1 = value;
			if (k == endIndex) value2 = value;
		}
		return (value1 + value2) / 2.0;
	}
};

void test()
{
	vector<int> vec1 = { 1, 3 };
	vector<int> vec2 = { 2};
	Solution s;
	cout << s.findMedianSortedArrays(vec1, vec2) << endl;
}

int main()
{
	test();
	return 0;
}
