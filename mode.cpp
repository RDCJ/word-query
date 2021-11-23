#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include "mode.h"
#include "datadef.h"
#include "WordVector.h"
#include "Word_Methods.h"
#include "sml_algorithm.h"

void make_dic()//构造词典
{
    char s[51];
    FILE *f1;
    f1=fopen("VOC.csv","r");
    while (fgets(s,30,f1)!=NULL)
        {
            s[strlen(s)-1]='\0';
            dic[++tot].set(trans(s));
        }
    fclose(f1);
}

void get_n(int k)
{
    char s[20];
    if (k==0)
    {
        printf("1.精确查词  2.智能查词  3.退出\n");
        printf("请输入序号选择相应的模式>>");
    }
    fflush(stdin);
    gets(s);
    if (strcmp(s,"1")==0) n=1;
    else if (strcmp(s,"2")==0) n=2;
    else if (strcmp(s,"3")==0) exit(0);
    else
    {
        printf("输入有误，请输入序号选择相应的模式>>");
        get_n(1);
        return;
    }
}

void get_a_word(int k)
{
    char s[51];
    if (k==0) printf("请输入单词,或输入序号更改模式>>");
    fflush(stdin);
    gets(s);
    if (strcmp(s,"1")==0||strcmp(s,"2")==0)
    {
        if (strcmp(s,"1")==0) n=1;else n=2;
        get_a_word(0);
        return;
    }
    else if (strcmp(s,"3")==0) exit(0);
    while (judge(s)==false)
        {
            printf("输入有误，请输入单词或序号>>");
            get_a_word(1);
            return;
        }
    a_word.set(trans(s));
}

void Mode1()
{
    int p;
    for (int i=0;i<=tot;i++)
        if (strcmp(a_word.proto,dic[i].proto)==0)
        {
            printf("在词典的第%d行\n",i+1);
            return;
        }
    printf("未在词典中找到该单词。");
    printf("是否进行智能查词？ 1.是  2.否\n");
    printf("请输入序号>>");
    scanf("%d",&p);
    while (p!=1&&p!=2)
    {
        printf("请输入数字 1 或 2 >>");
        scanf("%d",&p);
    }
    if (p==1) Mode2();
}

void Mode2()
{
    int anstot=-1;//记录ans数组中单词的个数
    type_ans ans[10];//ans数组记录相似的单词
    for (int i=0;i<=tot;i++)//遍历字典
    {
        double s_m_l=sml(a_word,dic[i]);//计算相似度
        if (s_m_l>0)
        {
            if (anstot<4)//不足5个就直接记下来
            {
                ans[++anstot].num=i;
                ans[anstot].sml=s_m_l;
            }
            else//否则就替换相似度最小的词
            {
                type_ans minn;//记录相似度最小的词
                minn.sml=1000000;
                for (int j=0;j<=4;j++)//遍历答案，找出相似度最小的那个
                    if (ans[j].sml<minn.sml)
                    {
                        minn.sml=ans[j].sml;
                        minn.num=j;
                    }
                if (minn.sml<s_m_l)
                {
                    ans[minn.num].num=i;
                    ans[minn.num].sml=s_m_l;
                }
            }
        }
    }

    if (anstot>0)//判断是否有相似的单词
    {
        for (int i=0;i<=anstot-1;i++)//按相似度排序
            for (int j=i+1;j<=anstot;j++)
            if (ans[i].sml<ans[j].sml)
            {
                type_ans t;
                t=ans[i];ans[i]=ans[j];ans[j]=t;
            }

        int mm=0;
        for (int i=0;i<=anstot;i++)
            if (dic[ans[i].num].len>mm) mm=dic[ans[i].num].len;
        printf("最相似的%d个单词是:\n",anstot+1);

        for (int i=0;i<=anstot;i++)//输出答案
            {
                printf("%d.%s",i+1,dic[ans[i].num].proto);
                for (int j=1;j<=mm-dic[ans[i].num].len+2;j++) printf(" ");
                printf("%.4f\n",ans[i].sml);
            }
        printf("\n");
    }
    else printf("No Similar Word\n");
}
