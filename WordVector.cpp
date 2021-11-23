#include "WordVector.h"
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using std::abs;
Word::Word()
{
    len=0;l=0;
    memset(vec,0,sizeof(vec));
    memset(proto,0,sizeof(proto));
}

Word::cal_vec()
{
    memset(vec,0,sizeof(vec));
    for (int i=0;i<=len-1;i++)
        if (proto[i]>='a'&&proto[i]<='z') vec[proto[i]-'a']++;
}

Word::cal_l()
{
    int t=0;
    for (int i=0;i<=25;i++) t+=vec[i]*vec[i];
    l=sqrt(t);
}

Word::set(char *s)
{
    strcpy(proto,s);
    len=strlen(s);
    cal_vec();
    cal_l();
}
