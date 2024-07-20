#include "adcin.h"


//∂¡»°ADC÷µ
uint16_t ADC_Value[ADCNUM];
uint32_t ADC_CH1_Value, ADC_CH2_Value;


void ADC1In_Init(void)
{
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)ADC_Value, ADCNUM);
}

void GetADCValue(void)
{
    ADC_CH1_Value = ADC_CH2_Value = 0;
    for (uint16_t i = 0; i < ADCNUM; i += 2)
    {
        ADC_CH1_Value += ADC_Value[i];
        ADC_CH2_Value += ADC_Value[i + 1];
    }
    ADC_CH1_Value = ADC_CH1_Value / (ADCNUM / 2);
    ADC_CH2_Value = ADC_CH2_Value / (ADCNUM / 2);
}

