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
			cout << "������ת" << endl;
			continue;
		}
		s2 += s2;
		cout << s2 << endl;
		if (s2.find(s1) != string::npos) //�൱�ڵ���һ���Ӵ��жϺ���
		{
			cout << "����ת����" << endl;
		}
		else
		{
			cout << "������ת" << endl;
		}
	}


	return 0;
}