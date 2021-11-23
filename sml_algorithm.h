/*
 ======================================================================
 Name        : sml_algorithm.h
 Author      : Yu Shunyao
 Copyright   : The copyright of this file is reserved by the author.
 Description : ���ƶ��㷨
 ======================================================================
 */

#ifndef SML_ALGORITHM_H
#define SML_ALGORITHM_H
#include "WordVector.h"
double cos_sml(Word a,Word b);//�������ƶ�

double adj_cos_sml(Word a,Word b);//�����������ƶ�

double extended_vec_sml(Word a,Word b);//��չ��������������ƶ�

double eu_cos_sml(Word a,Word b);//ŷ����þ������ƶ�

double tanimoto_sml(Word a,Word b);

double ed_dstc_sml(Word a,Word b);//�༭�������ƶ�

double sml(Word a,Word b);//��������ֱ�ӵ��ã��л��㷨ʱ�޸�����
#endif // SML_ALGORITHM_H
