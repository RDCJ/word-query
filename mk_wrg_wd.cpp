#include "mk_wrg_wd.h"
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>

void mk_wrg_wd(char *s,int pst,int t)
{
    int l=strlen(s);
    //srand((unsigned int)time(0));
    if (t==1)
        s[pst]=rand()%26+97;
    else if (t==2)
    {
        char ss[51];
        for (int i=pst+1;i<=l-1;i++) ss[i+1]=s[i];
        s[pst+1]=rand()%26+97;
        s[l+1]='\0';
    }
    else
    {
        for (int i=pst;i<=l-1;i++) s[i]=s[i+1];s[l-1]='\0';
    }
}
