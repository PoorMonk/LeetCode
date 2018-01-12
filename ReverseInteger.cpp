#include <iostream>
using namespace std;

class Solution
{
public:
	//��һ�������Լ�����ˣ����ڸ����ĳ�������ģ��û�����ף�������·
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
			sum = sum * 10 + value; //��Ϊsum��ʼֵΪ0������ǰ��0�Զ��͹��˵���
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
