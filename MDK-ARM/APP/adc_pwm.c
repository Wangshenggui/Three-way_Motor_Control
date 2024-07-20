#include "adc_pwm.h"
#include "adcin.h"


#define K   84/159.0


void ADC_PWM(void)
{
    uint16_t temp=0;
    if(ADC_CH1_Value>=2100)
    {
        temp = K*(ADC_CH1_Value-2100)+1100;
        if(temp>1940)
        {
            temp=1940;
        }
        TIM3->CCR3 = temp;
    }
    else if(ADC_CH1_Value<=1900)
    {
        temp = K*(1900-ADC_CH1_Value)+1100;
        if(temp>1940)
        {
            temp=1940;
        }
        TIM3->CCR2 = temp;
    }
    else
    {
        TIM3->CCR2 = 1100;
        TIM3->CCR3 = 1100;
    }
    
    if(ADC_CH2_Value>=2100)
    {
        temp = K*(ADC_CH2_Value-2100)+1100;
        if(temp>1940)
        {
            temp=1940;
        }
        TIM3->CCR1 = temp;
    }
    else if(ADC_CH2_Value<=1900)
    {
        temp = K*(1900-ADC_CH2_Value)+1100;
        if(temp>1940)
        {
            temp=1940;
        }
        TIM3->CCR1 = temp;
    }
    else
    {
        TIM3->CCR1 = 1100;
    }
}










