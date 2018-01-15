/*
Determine whether an integer is a palindrome. Do this without extra space.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPalindrome(int x)
	{
		//负数不是回文数	
		return (0 <= x && x == reverse(x));
	}

private:
	int reverse(int x)
	{
		int y = 0;
		while (x)
		{
			y = y * 10 + x % 10;
			x = x / 10;
		}
		return y;
	}
};

int main()
{
	Solution s;
	if (s.isPalindrome(2147447412))
	{
		cout << "True..." << endl;
	}
	else
	{
		cout << "False..." << endl;
	}
	
	return 0;
}
