#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool isAnagram0(string s1,string s2)
{
	if (s1 == ""&&s2 == "")
	{
		return false;
	}
	if (s1.length() != s2.length())
	{
		return false;
	}

	int count1[256],count2[256];
	memset(count1, 0, sizeof(count1));
	memset(count2, 0, sizeof(count2));  //即判断两个字符串的直方图是否一样。
	int len = s1.length();
	for (int i = 0; i < len; i++)
	{
		count1[(int)s1[i]]++;
		count2[(int)s2[i]]++;
	}
	for (int i = 0; i < 256; i++)
	{
		if (count1[i] != count2[i])
		{
			return false;
		}
	}

	return true;

}
int main()
{
    string s = "aaabbb";
    string t = "ababab";
	cout << isAnagram0(s, t) << endl;;
    return 0;
}
