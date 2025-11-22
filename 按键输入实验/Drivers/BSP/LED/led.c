#include "./BSP/LED/led.h"

void led_init(void)
{
    GPIO_InitTypeDef gpio_init_struct; /*GPIO_InitTypeDef结构体*/
    LED0_GPIO_CLK_ENABLE();            /*使能GPIOB时钟*/
    LED1_GPIO_CLK_ENABLE();            /*使能GPIOE时钟*/

    gpio_init_struct.Pin = LED0_GPIO_PIN;             /*选择LED0引脚*/
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;      /*推挽输出*/
    gpio_init_struct.Pull = GPIO_PULLUP;              /*不带上下拉*/
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;    /*高速*/
    HAL_GPIO_Init(LED0_GPIO_PORT, &gpio_init_struct); /*初始化LED0*/

    gpio_init_struct.Pin = LED1_GPIO_PIN;             /*选择LED1引脚*/
    HAL_GPIO_Init(LED1_GPIO_PORT, &gpio_init_struct); /*初始化LED1*/

    LED0(1); /*默认关闭LED0*/
    LED1(1); /*默认关闭LED1*/
}
