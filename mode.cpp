#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include "mode.h"
#include "datadef.h"
#include "WordVector.h"
#include "Word_Methods.h"
#include "sml_algorithm.h"

void make_dic()//����ʵ�
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
        printf("1.��ȷ���  2.���ܲ��  3.�˳�\n");
        printf("���������ѡ����Ӧ��ģʽ>>");
    }
    fflush(stdin);
    gets(s);
    if (strcmp(s,"1")==0) n=1;
    else if (strcmp(s,"2")==0) n=2;
    else if (strcmp(s,"3")==0) exit(0);
    else
    {
        printf("�����������������ѡ����Ӧ��ģʽ>>");
        get_n(1);
        return;
    }
}

void get_a_word(int k)
{
    char s[51];
    if (k==0) printf("�����뵥��,��������Ÿ���ģʽ>>");
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
            printf("�������������뵥�ʻ����>>");
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
            printf("�ڴʵ�ĵ�%d��\n",i+1);
            return;
        }
    printf("δ�ڴʵ����ҵ��õ��ʡ�");
    printf("�Ƿ�������ܲ�ʣ� 1.��  2.��\n");
    printf("���������>>");
    scanf("%d",&p);
    while (p!=1&&p!=2)
    {
        printf("���������� 1 �� 2 >>");
        scanf("%d",&p);
    }
    if (p==1) Mode2();
}

void Mode2()
{
    int anstot=-1;//��¼ans�����е��ʵĸ���
    type_ans ans[10];//ans�����¼���Ƶĵ���
    for (int i=0;i<=tot;i++)//�����ֵ�
    {
        double s_m_l=sml(a_word,dic[i]);//�������ƶ�
        if (s_m_l>0)
        {
            if (anstot<4)//����5����ֱ�Ӽ�����
            {
                ans[++anstot].num=i;
                ans[anstot].sml=s_m_l;
            }
            else//������滻���ƶ���С�Ĵ�
            {
                type_ans minn;//��¼���ƶ���С�Ĵ�
                minn.sml=1000000;
                for (int j=0;j<=4;j++)//�����𰸣��ҳ����ƶ���С���Ǹ�
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

    if (anstot>0)//�ж��Ƿ������Ƶĵ���
    {
        for (int i=0;i<=anstot-1;i++)//�����ƶ�����
            for (int j=i+1;j<=anstot;j++)
            if (ans[i].sml<ans[j].sml)
            {
                type_ans t;
                t=ans[i];ans[i]=ans[j];ans[j]=t;
            }

        int mm=0;
        for (int i=0;i<=anstot;i++)
            if (dic[ans[i].num].len>mm) mm=dic[ans[i].num].len;
        printf("�����Ƶ�%d��������:\n",anstot+1);

        for (int i=0;i<=anstot;i++)//�����
            {
                printf("%d.%s",i+1,dic[ans[i].num].proto);
                for (int j=1;j<=mm-dic[ans[i].num].len+2;j++) printf(" ");
                printf("%.4f\n",ans[i].sml);
            }
        printf("\n");
    }
    else printf("No Similar Word\n");
}
