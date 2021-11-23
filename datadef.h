/*
 ======================================================================
 Name        : datadef.h
 Author      : Yu Shunyao
 Copyright   : The copyright of this file is reserved by the author.
 Description : 定义全局变量
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
extern Word a_word;//记录待查询的单词
extern int tot;
extern int n;//标记所选的模式
extern Word dic[8000];//储存词典
extern double average[26];
#endif // DATADEF_H
