#include "Word_Methods.h"
#include<cstring>

double sq(double y){return y*y;}

bool judge(char *s)//判段读入的字符串是不是一个英文单词
{
    int ll=strlen(s);bool flag=false;
    if (ll==0) return false;
    for (int i=0;i<=ll-1;i++)
        if (s[i]<'A'||s[i]>'z'||(s[i]>'Z'&&s[i]<'a'))
        {
           if (s[i]!='\''&&s[i]!='-') return false;
        }
        else flag=true;
    return flag;
}

char *trans(char *s)//转换成小写
{
    for (int i=0;i<=strlen(s)-1;i++)
        if (s[i]>='A'&&s[i]<='Z') s[i]=s[i]+32;
    return s;
}
