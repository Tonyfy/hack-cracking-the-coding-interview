# hack-cracking-the-coding-interview
hack/cracking-the-coding-interview
 
## 1.1 

Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures? 
不使用其他数据结构，判断一个字符串是否由完全不同的字符组成。

* 思路：使用bool a[256]用于指示是否出现某个字符。重复出现即为unique=false.

## 1.2 

Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null character.)

反转一个C风格的字符串，“abcd”代表5个字符，包含最后一个null字符。
 
* 思路：p,q分别指向字符串首尾，使用原址交换。
```
void swap(char &a,char &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
```

## 1.3 

Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer. NOTE: One or two additional variables are fine. An extra copy of the array is not.
FOLLOW UP
Write the test cases for this method.

不使用额外的buffer空间，去除一个字符串中的重复字符，可以额外使用少量的变量。

* 思路：使用check标记记录哪些字符出现过,在原址上对字符串进行更新，不使用额外空间。
```
void removeDuplicate5(char s[])
{
    int len = strlen(s);
    if(len < 2) return;
    int check = 0, p = 0;
    for(int i=0; i<len; ++i)
    {
        int v = (int)(s[i]-'a');
        if((check & (1<<v))==0)  //按位与=0，说明该字符未出现过。
        {
            s[p++] = s[i];
            check |= (1<<v);  //按位或操作，更新出现了哪些字符。
        }
    }
    s[p] = '\0';  //结束字符，添加结束符
}
```