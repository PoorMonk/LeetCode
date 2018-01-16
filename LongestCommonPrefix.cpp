/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string str;
		int index = 0;
		for (int idx = 0; strs.size() > 0; str += strs[0][idx], idx++)
		{
			for (int i = 0; i < strs.size(); i++)
			{
				if (strs[i].size() <= /*0*/idx || (0 < i && strs[i][idx] != strs[i - 1][idx])) //²»ÄÜÅÐ¶Ï×Ö´®
				{
					return str;
				}
			}
		}
		return str;
	}
};

int main()
{
	Solution s;
	vector<string> vec = { "" };
	cout << "size:" << vec[0].size() << endl;
	cout << s.longestCommonPrefix(vec) << endl;
	//vector<int> str = {1, 2, 3};
	//cout << str[-1] << endl;
	return 0;
}
