#ifndef _ADC_PWM_H
#define _ADC_PWM_H

#include "main.h"
#include "adc.h"
#include "tim.h"


//85\
������������
#define K   90/159.0f

//��Ч�г���ֵ
#define MaxInvalidStroke    2100
#define MinInvalidStroke    1900

//Ĭ���м�ֵ(���Ź���ʱ)
#define DefaultMedian   2000.0f

//�����ֵ
#define OutputMaximum   1940
#define OutputMinimum   1100

//�˲�ϵ��
#define ALPHA 0.5f

uint16_t LowPassFiltering1(uint16_t input);
uint16_t LowPassFiltering2(uint16_t input);
void ADC_PWM(void);








#endif
