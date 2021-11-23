/*
 ======================================================================
 Name        : WordVector.h
 Author      : Yu Shunyao
 Copyright   : The copyright of this file is reserved by the author.
 Description : 定义单词类，成员变量，成员函数
 ======================================================================
 */

#ifndef WORDVECTOR_H
#define WORDVECTOR_H

class Word
{
    public:
        char proto[51];//原单词
        int len;//单词长度
        double l;//向量模长
        double vec[26];//向量
        set(char *p);//赋值函数
        Word();//构造函数
    private:
        cal_vec();
        cal_l();
};
#endif
