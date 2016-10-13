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

## 1.4 

Write a method to decide if two strings are anagrams or not.

判断两个字符串单词是否为字谜（仅字符顺序不一致）

* 思路：统计两个字符串的字符直方图h1[256],h2[256]。如果两个直方图一样则为字谜。

## 1.5 

Write a method to replace all spaces in a string with ‘%20’.

替换字符串中的所有空格为“%20”。

* 思路：1，一趟遍历得到空格个数N;2,计算新字符串的规模len+2*N，并从尾部开始将源字符串写入新字符串；3，注意结尾的"\0"。


## 1.7

Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0.
实现算法使得矩阵中只要某处有0，就将该行和列的所有元素都变为0

* 思路：如果迭代进行矩阵元素的更改，那么可想，最后整个矩阵变成0了。我们可以用O(MxN)的空间记录某个元素是否为0，然后再改掉对应的元素。也可以只有M+N的空间，记录某行某列是否有0。再次遍历矩阵时，若该行有零或该列有零，即改为0.

## 1.8 

Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).

只调用一次isSubstring方法，判断字符串s2是否可由s1旋转而来。

思路：
1，如果s1和s2长度不同，判否；
2，在s2后面接上s2，判断s1是否为s2的子串，若是，判是。


# 链表

## 2.1

Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
从一个无序链表中去除重复的元素，更进一步，可以不使用临时的buffer吗
* 思路：若可使用buffer，那么使用一个set集合存放出现的元素，遍历一次即可删除所有重复的。不使用buffer时，使用两个游标，两层循环完成。

