#include <iostream>
using namespace std;

class Solution
{
public:
	//第一种做法自己想多了，对于负数的除法与求模都没搞明白，走了弯路
	int reverse(int x)
	{
		//bool bFlag = true;
		long long sum = 0;
		//int temp = x;
		//x = x > 0 ? x : -x;
		while (x)
		{
			int value = x % 10;
			/*if (bFlag && !value) 
			{
				bFlag = false;
				continue;
			}*/
			sum = sum * 10 + value; //因为sum初始值为0，所以前置0自动就过滤掉了
			x /= 10;
		}
		//return temp > 0 ? sum : -sum;
		return (sum < INT_MIN || sum > INT_MAX) ? 0 : sum;
	}

	int reverse2(int x)
	{
		long long sum = 0;
		while (x)
		{
			sum = sum * 10 + x % 10;
			x /= 10;
		}
		return (sum < INT_MIN || sum > INT_MAX) ? 0 : sum;
	}
};

int main()
{
	Solution s;
	int x = -12300;
	cout << s.reverse(x) << endl;
	return 0;
}
