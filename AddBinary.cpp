/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		int al = a.length(), bl = b.length();
		if (!al) return b;
		if (!bl) return a;
		int value = 0;
		string c;
		while (0 < al || 0 < bl || value)
		{
			--al, --bl;
			int ia = al >= 0 ? a[al] - '0' : 0;
			int ib = bl >= 0 ? b[bl] - '0' : 0;
			int iIndex = (ia + ib + value) % 2;
			c = to_string(iIndex) + c;
			value = (ia + ib + value) / 2;
		}
		return c;
	}
};

void test()
{
	Solution s;
	string a = "110";
	string b = "11";
	cout << a << " + " << b << " = " << s.addBinary(a, b) << endl;
}

int main()
{
	test();
	return 0;
}
