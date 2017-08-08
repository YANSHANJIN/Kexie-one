#ifndef __JEAN_H_
#define __JEAN_H_
#include<reg51.h>   //����51��Ƭ���Ĵ��������ͷ�ļ� 
//������C����������Ƶ�궨��  
#define l_dao 262   //����l_dao���궨��Ϊ������1����Ƶ��262Hz
#define l_re 286    //����l_re���궨��Ϊ������2����Ƶ��286Hz
#define l_mi 311    //����l_mi���궨��Ϊ������3����Ƶ��311Hz
#define l_fa 349    //����l_fa���궨��Ϊ������4����Ƶ��349Hz
#define l_sao 392   //����l_sao���궨��Ϊ������5����Ƶ��392Hz
#define l_la 440    //����l_a���궨��Ϊ������6����Ƶ��440Hz
#define l_xi 494    //����l_xi���궨��Ϊ������7����Ƶ��494Hz

#define dao 523     //����dao���궨��Ϊ������1����Ƶ��523Hz
#define re 587      //����re���궨��Ϊ������2����Ƶ��587Hz
#define mi 659      //����mi���궨��Ϊ������3����Ƶ��659Hz
#define fa 698      //����fa���궨��Ϊ������4����Ƶ��698Hz
#define sao 784     //����sao���궨��Ϊ������5����Ƶ��784Hz
#define la 880      //����la���궨��Ϊ������6����Ƶ��880Hz
#define xi 987      //����xi���궨��Ϊ������7����Ƶ��523H 

#define h_dao 1046     //����h_dao���궨��Ϊ������1����Ƶ��1046Hz
#define h_re 1174      //����h_re���궨��Ϊ������2����Ƶ��1174Hz
#define h_mi 1318      //����h_mi���궨��Ϊ������3����Ƶ��1318Hz
#define h_fa 1396     //����h_fa���궨��Ϊ������4����Ƶ��1396Hz
#define h_sao 1567    //����h_sao���궨��Ϊ������5����Ƶ��1567Hz
#define h_la 1760     //����h_la���궨��Ϊ������6����Ƶ��1760Hz
#define h_xi 1975     //����h_xi���궨��Ϊ������7����Ƶ��1975Hz
sbit sound=P3^7;    //��soundλ����ΪP3.7
void music();
void electronic_organ();
#endif