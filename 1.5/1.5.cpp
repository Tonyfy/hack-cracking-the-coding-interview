#include <iostream>
#include <cstring>
using namespace std;

char* replace1(char *c){
    if(c == NULL) return NULL;
    int len = strlen(c);
    if(len == 0) return NULL;
    int cnt = 0;
    for(int i=0; i<len; ++i)
    {
        if(c[i] == ' ')
            ++cnt;
    }
    char *cc = new char[len+2*cnt+1];
    int p = 0;
    for(int i=0; i<len; ++i)
    {
        if(c[i] == ' ')
        {
            cc[p] = '%';
            cc[p+1] = '2';
            cc[p+2] = '0';
            p += 3;
        }
        else
        {
            cc[p] = c[i];
            ++p;
        }
    }
    cc[p] = '\0';
    return cc;
}

void replace2(char *c){
    if(c == NULL) return;
    int len = strlen(c);
    if(len == 0) return;
    int cnt = 0;
    for(int i=0; i<len; ++i)
    {
        if(c[i] == ' ')
            ++cnt;
    }
    int p = len + 2*cnt;
    c[p--] = '\0';//the space must be allocated first.
    for(int i=len-1; i>=0; --i)
    {
        if(c[i] == ' ')
        {
            c[p] = '0';
            c[p-1] = '2';
            c[p-2] = '%';
            p -= 3;
        }
        else
        {
            c[p] = c[i];
            --p;
        }
    }
}

void replace0(char *c)
{
	int len = strlen(c);
	if (c == NULL)
	{
		return;
	}
	if (len == 0)
	{
		return;
	}
	//һ��ɨ�裬��¼�ո������
	int blankcount = 0;
	for (int i = 0; i < len; i++)
	{
		if (c[i] == ' ')
		{
			blankcount++;
		}
	}

	int newlen = len + 2 * blankcount;  //��֤newlen�Ĵ�С�����ᳬ�����ȷ���Ĵ�С
	c[newlen--] = '\0';
	for (int i = len - 1; i > 0; i--)
	{
		if (c[i] == ' ')
		{
			c[newlen] = '0';
			c[newlen - 1] = '2';
			c[newlen - 2] = '%';
			newlen -= 3;
		}
		else
		{
			c[newlen] = c[i];
			newlen -= 1;
		}
	}

}
int main(){
    const int len = 100;  //���ȷ�����㹻��Ŀռ�
    char c[len] = "anh jsdha da da ad q df  ";
    //cout<<replace1(c)<<endl;
   // replace2(c);
	replace0(c);
    cout<<c<<endl;
    return 0;
}
