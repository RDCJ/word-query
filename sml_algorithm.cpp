#include "sml_algorithm.h"
#include "WordVector.h"
#include "Word_Methods.h"
#include "datadef.h"
#include<algorithm>
#include<cmath>
using std::max;
using std::min;

double cos_sml(Word a,Word b)
{
    int t=0;
    for (int i=0;i<=25;i++) t+=sq(a.vec[i]-b.vec[i]);
    return (sq(a.l)+sq(b.l)-t)/(2*a.l*b.l);
}

double adj_cos_sml(Word a,Word b)
{
    double t=0;
    double al=0,bl=0;
    for (int i=0;i<=25;i++)
    {
        t+=sq(a.vec[i]-b.vec[i]);
        al=al+sq(a.vec[i]-average[i]);
        bl=bl+sq(b.vec[i]-average[i]);
    }
    return (al+bl-t)/(2*sqrt(al)*sqrt(bl));
}

double extended_vec_sml(Word a,Word b)
{
    int avl=0,bvl=0,t=0;
    int avec[703]={0},bvec[703]={0};
    for (int i=0;i<=25;i++)
    {
        avec[i+1]=a.vec[i];
        bvec[i+1]=b.vec[i];
    }
    int u=0;
    while (a.proto[u]<'a'||a.proto[u]>'z') u++;
    while (u<a.len-1)
    {
        int v=u+1;while (a.proto[v]<'a'||a.proto[v]>'z') v++;
        if (v>a.len-1) break;
        int x=a.proto[u]-'a',y=a.proto[v]-'a'+1;
        avec[26+(x*26)+y]++;
        u=v;
    }
    u=0;
    while (b.proto[u]<'a'||b.proto[u]>'z') u++;
    while (u<b.len-1)
    {
        int v=u+1;while (b.proto[v]<'a'||b.proto[v]>'z') v++;
        if (v>b.len-1) break;
        int x=b.proto[u]-'a',y=b.proto[v]-'a'+1;
        bvec[26+(x*26)+y]++;
        u=v;
    }
    for (int i=1;i<=702;i++)
    {
        avl+=sq(avec[i]);
        bvl+=sq(bvec[i]);
        t+=sq(avec[i]-bvec[i]);
    }
    return (avl+bvl-t)/(2*sqrt(avl)*sqrt(bvl));
}
double eu_sml(Word a,Word b)//欧几里得距离(归一化)
{
    int t=0;
    for (int i=0;i<=25;i++) t+=sq(a.vec[i]-b.vec[i]);
    return 1-t/(t+a.l+b.l);
}

double tanimoto_sml(Word a,Word b)
{
    int t=0;
    for (int i=0;i<=25;i++) t+=a.vec[i]*b.vec[i];
    return t/(a.l+b.l-t);
}

double ed_dstc_sml(Word a,Word b)
{
    int l1=a.len;
    int l2=b.len;
    int f[51][51]={0};
    for (int i=0;i<=l2-1;i++) f[0][i+1]=i+1;
    for (int i=0;i<=l1-1;i++) f[i+1][0]=i+1;
    for (int i=1;i<=l1;i++)
        for (int j=1;j<=l2;j++)
        {
            int k;
            if (a.proto[i-1]==b.proto[j-1]) k=0;else k=1;
            f[i][j]=min(min(f[i-1][j]+1,f[i][j-1]+1),f[i-1][j-1]+k);
        }
    double p=double (f[l1][l2])/max(l1,l2);
    return 1-p;
}

double sml(Word a,Word b) {return extended_vec_sml(a,b);}//由主程序直接调用，切换算法时修改这里
