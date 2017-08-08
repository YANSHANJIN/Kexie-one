#ifndef __JEAN_H_
#define __JEAN_H_
#include<reg51.h>   //包含51单片机寄存器定义的头文件 
//以下是C调低音的音频宏定义  
#define l_dao 262   //将“l_dao”宏定义为低音“1”的频率262Hz
#define l_re 286    //将“l_re”宏定义为低音“2”的频率286Hz
#define l_mi 311    //将“l_mi”宏定义为低音“3”的频率311Hz
#define l_fa 349    //将“l_fa”宏定义为低音“4”的频率349Hz
#define l_sao 392   //将“l_sao”宏定义为低音“5”的频率392Hz
#define l_la 440    //将“l_a”宏定义为低音“6”的频率440Hz
#define l_xi 494    //将“l_xi”宏定义为低音“7”的频率494Hz

#define dao 523     //将“dao”宏定义为中音“1”的频率523Hz
#define re 587      //将“re”宏定义为中音“2”的频率587Hz
#define mi 659      //将“mi”宏定义为中音“3”的频率659Hz
#define fa 698      //将“fa”宏定义为中音“4”的频率698Hz
#define sao 784     //将“sao”宏定义为中音“5”的频率784Hz
#define la 880      //将“la”宏定义为中音“6”的频率880Hz
#define xi 987      //将“xi”宏定义为中音“7”的频率523H 

#define h_dao 1046     //将“h_dao”宏定义为高音“1”的频率1046Hz
#define h_re 1174      //将“h_re”宏定义为高音“2”的频率1174Hz
#define h_mi 1318      //将“h_mi”宏定义为高音“3”的频率1318Hz
#define h_fa 1396     //将“h_fa”宏定义为高音“4”的频率1396Hz
#define h_sao 1567    //将“h_sao”宏定义为高音“5”的频率1567Hz
#define h_la 1760     //将“h_la”宏定义为高音“6”的频率1760Hz
#define h_xi 1975     //将“h_xi”宏定义为高音“7”的频率1975Hz
sbit sound=P3^7;    //将sound位定义为P3.7
void music();
void electronic_organ();
#endif