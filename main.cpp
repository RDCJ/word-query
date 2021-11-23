/*
 ======================================================================
 Name        : main.cpp
 Author      : Yu Shunyao
 Copyright   : The copyright of this file is reserved by the author.
 Description : 单词查询：主程序文件
 ======================================================================
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include "mode.h"
#include "datadef.h"

int main()
{
    make_dic();
    get_n(0);
    while (n==1||n==2)
    {
        get_a_word(0);
        switch (n)
        {
            case 1:
                Mode1();
                break;
            case 2:
                Mode2();
                break;
        }
    }
    return 0;
}
