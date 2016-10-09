#include <iostream>
#include <cstring>
using namespace std;

void swap(char &a, char &b){
    a = a^b;
    b = a^b;
    a = a^b;   //原址交换的方法
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
    --q; //q指向字符串的倒数第二位，即最后一个有效字符。
    while(p < q)
        swap(*p++, *q--); //依次交换首尾的字符。
}

int main(){
    char s[] = "1234567890";
    reverse1(s);
	//reverse2(s);
    cout<<s<<endl;
    return 0;
}
