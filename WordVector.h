/*
 ======================================================================
 Name        : WordVector.h
 Author      : Yu Shunyao
 Copyright   : The copyright of this file is reserved by the author.
 Description : ���嵥���࣬��Ա��������Ա����
 ======================================================================
 */

#ifndef WORDVECTOR_H
#define WORDVECTOR_H

class Word
{
    public:
        char proto[51];//ԭ����
        int len;//���ʳ���
        double l;//����ģ��
        double vec[26];//����
        set(char *p);//��ֵ����
        Word();//���캯��
    private:
        cal_vec();
        cal_l();
};
#endif
