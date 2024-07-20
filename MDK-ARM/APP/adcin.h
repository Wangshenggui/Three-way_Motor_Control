#ifndef _ADCIN_H
#define _ADCIN_H


#include "main.h"
#include "adc.h"

#define ADCNUM 200
extern uint32_t ADC_CH1_Value, ADC_CH2_Value;

void ADC1In_Init(void);
void GetADCValue(void);






#endif
