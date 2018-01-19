/*
Given an array and a value, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being 2.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeElement(vector<int>& nums, int val)
	{
		for (auto it  = nums.begin(); it != nums.end(); )
		{
			if (val == *it)
			{
				it = nums.erase(it);
			}
			else
			{
				++it;
			}
		}
		return nums.size();
	}
};

int main()
{
	vector<int> vec = { 3, 2, 2, 3 };
	Solution s;
	int val = 4;
	cout << "length: " << s.removeElement(vec, val) << endl;

	for (auto num : vec)
	{
		cout << num << " ";
	}
	cout << "\n";
	return 0;
}
