/*
 ======================================================================
 Name        : datadef.h
 Author      : Yu Shunyao
 Copyright   : The copyright of this file is reserved by the author.
 Description : ����ȫ�ֱ���
 ======================================================================
 */

#ifndef DATADEF_H
#define DATADEF_H
#include "WordVector.h"

struct type_ans
{
    int num;
    double sml;
};
extern Word a_word;//��¼����ѯ�ĵ���
extern int tot;
extern int n;//�����ѡ��ģʽ
extern Word dic[8000];//����ʵ�
extern double average[26];
#endif // DATADEF_H
