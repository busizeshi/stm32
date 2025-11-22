#include "./BSP/BEEP/beep.h"

void beep_init(void)
{
    GPIO_InitTypeDef gpio_init_struct; /*GPIO_InitTypeDef结构体*/
    BEEP_GPIO_CLK_ENABLE();            /*使能BEEP对应的GPIO时钟*/

    gpio_init_struct.Pin = BEEP_GPIO_PIN;             /*选择PB8*/
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;      /*推挽*/
    gpio_init_struct.Pull = GPIO_PULLUP;              /*上拉*/
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;    /*高速*/
    HAL_GPIO_Init(BEEP_GPIO_PORT, &gpio_init_struct); /*初始化GPIO*/

    BEEP(0); /*初始化关闭BEEP*/
}
