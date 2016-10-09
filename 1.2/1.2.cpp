#include <iostream>
#include <cstring>
using namespace std;

void swap(char &a, char &b){
    a = a^b;
    b = a^b;
    a = a^b;   //ԭַ�����ķ���
}

void reverse2(char *s){
    int n = strlen(s);
    for(int i=0; i<n/2; ++i)
        swap(s[i], s[n-i-1]);
}

void reverse1(char *s){
    if(!s) return;
    char *p = s, *q = s;
	while (*q)
	{
		++q;
	}
    --q; //qָ���ַ����ĵ����ڶ�λ�������һ����Ч�ַ���
    while(p < q)
        swap(*p++, *q--); //���ν�����β���ַ���
}

int main(){
    char s[] = "1234567890";
    reverse1(s);
	//reverse2(s);
    cout<<s<<endl;
    return 0;
}
