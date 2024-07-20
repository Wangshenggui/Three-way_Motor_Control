#ifndef _ADC_PWM_H
#define _ADC_PWM_H

#include "main.h"
#include "adc.h"
#include "tim.h"


//85\
输出和输入比例
#define K   90/159.0f

//无效行程阈值
#define MaxInvalidStroke    2100
#define MinInvalidStroke    1900

//默认中间值(油门归零时)
#define DefaultMedian   2000.0f

//输出阈值
#define OutputMaximum   1940
#define OutputMinimum   1100

//滤波系数
#define ALPHA 0.5f

uint16_t LowPassFiltering1(uint16_t input);
uint16_t LowPassFiltering2(uint16_t input);
void ADC_PWM(void);








#endif
