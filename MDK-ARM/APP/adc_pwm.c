#include "adc_pwm.h"
#include "adcin.h"


//低通滤波器
uint16_t LowPassFiltering1(uint16_t input)
{
    float output;
    static float prev_input = DefaultMedian; // 上一时刻的输入值

    // 实现一阶低通滤波的核心算法
    output = ALPHA * input + (1 - ALPHA) * prev_input;

    // 更新上一时刻的输入值
    prev_input = output;

    return (uint16_t)output;
}

uint16_t LowPassFiltering2(uint16_t input)
{
    float output;
    static float prev_input = DefaultMedian; // 上一时刻的输入值

    // 实现一阶低通滤波的核心算法
    output = ALPHA * input + (1 - ALPHA) * prev_input;

    // 更新上一时刻的输入值
    prev_input = output;

    return (uint16_t)output;
}

//控制输出
void ADC_PWM(void)
{
    uint16_t temp = 0;

    //滤波
    ADC_CH1_Value = LowPassFiltering1(ADC_CH1_Value);
    //油门往上
    if (ADC_CH1_Value >= MaxInvalidStroke)
    {
        temp = K * (ADC_CH1_Value - MaxInvalidStroke) + OutputMinimum;
        TIM3->CCR3 = temp > OutputMaximum ? OutputMaximum : temp;
    }
    //油门往下
    else if (ADC_CH1_Value <= MinInvalidStroke)
    {
        temp = K * (MinInvalidStroke - ADC_CH1_Value) + OutputMinimum;
        TIM3->CCR2 = temp > OutputMaximum ? OutputMaximum : temp;
    }
    else
    {
        TIM3->CCR2 = OutputMinimum;
        TIM3->CCR3 = OutputMinimum;
    }

    ADC_CH2_Value = LowPassFiltering2(ADC_CH2_Value);
    if (ADC_CH2_Value >= MaxInvalidStroke)
    {
        temp = K * (ADC_CH2_Value - MaxInvalidStroke) + OutputMinimum;
        TIM3->CCR1 = temp > OutputMaximum ? OutputMaximum : temp;
    }
    else if (ADC_CH2_Value <= MinInvalidStroke)
    {
        temp = K * (MinInvalidStroke - ADC_CH2_Value) + OutputMinimum;
        TIM3->CCR1 = temp > OutputMaximum ? OutputMaximum : temp;
    }
    else
    {
        TIM3->CCR1 = OutputMinimum;
    }
}










