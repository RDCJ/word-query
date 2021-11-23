/*
 ======================================================================
 Name        : sml_algorithm.h
 Author      : Yu Shunyao
 Copyright   : The copyright of this file is reserved by the author.
 Description : 相似度算法
 ======================================================================
 */

#ifndef SML_ALGORITHM_H
#define SML_ALGORITHM_H
#include "WordVector.h"
double cos_sml(Word a,Word b);//余弦相似度

double adj_cos_sml(Word a,Word b);//调整余弦相似度

double extended_vec_sml(Word a,Word b);//扩展向量后的余弦相似度

double eu_cos_sml(Word a,Word b);//欧几里得距离相似度

double tanimoto_sml(Word a,Word b);

double ed_dstc_sml(Word a,Word b);//编辑距离相似度

double sml(Word a,Word b);//由主程序直接调用，切换算法时修改这里
#endif // SML_ALGORITHM_H
