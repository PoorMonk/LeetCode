/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string convert(string s, int numRows)
	{
		if (numRows <= 1) return s;

		int len = s.length();
		string* str = new string[numRows];
		int row = 0, step = 1;
		for (int i = 0; i < len; ++i)
		{
			str[row].push_back(s[i]);
			if (0 == row)
				step = 1;
			else if (row == numRows - 1)
				step = -1;

			row += step;
		}

		string strResult;
		for (int i = 0; i < numRows; ++i)
		{
			strResult.append(str[i]);
		}

		delete[] str;
		return strResult;
	}
};

void test()
{
	Solution s;
	string str = "PAYPALISHIRING";
	int numRows = 3;
	cout << s.convert(str, numRows) << endl;
}

int main()
{
	test();
	return 0;
}
