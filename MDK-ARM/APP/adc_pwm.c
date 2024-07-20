#include "adc_pwm.h"
#include "adcin.h"


//��ͨ�˲���
uint16_t LowPassFiltering1(uint16_t input)
{
    float output;
    static float prev_input = DefaultMedian; // ��һʱ�̵�����ֵ

    // ʵ��һ�׵�ͨ�˲��ĺ����㷨
    output = ALPHA * input + (1 - ALPHA) * prev_input;

    // ������һʱ�̵�����ֵ
    prev_input = output;

    return (uint16_t)output;
}

uint16_t LowPassFiltering2(uint16_t input)
{
    float output;
    static float prev_input = DefaultMedian; // ��һʱ�̵�����ֵ

    // ʵ��һ�׵�ͨ�˲��ĺ����㷨
    output = ALPHA * input + (1 - ALPHA) * prev_input;

    // ������һʱ�̵�����ֵ
    prev_input = output;

    return (uint16_t)output;
}

//�������
void ADC_PWM(void)
{
    uint16_t temp = 0;

    //�˲�
    ADC_CH1_Value = LowPassFiltering1(ADC_CH1_Value);
    //��������
    if (ADC_CH1_Value >= MaxInvalidStroke)
    {
        temp = K * (ADC_CH1_Value - MaxInvalidStroke) + OutputMinimum;
        TIM3->CCR3 = temp > OutputMaximum ? OutputMaximum : temp;
    }
    //��������
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










