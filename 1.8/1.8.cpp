#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (s1.length() != s2.length())
		{
			cout << "不可旋转" << endl;
			continue;
		}
		s2 += s2;
		cout << s2 << endl;
		if (s2.find(s1) != string::npos) //相当于调用一次子串判断函数
		{
			cout << "可旋转而来" << endl;
		}
		else
		{
			cout << "不可旋转" << endl;
		}
	}


	return 0;
}