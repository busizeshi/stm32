#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

void led_init(void); /*LED初始化函数声明*/

int main(void)
{
    HAL_Init();                         /*初始化HAL库*/
    sys_stm32_clock_init(RCC_PLL_MUL9); /*设置时钟,72Mhz*/
    delay_init(72);                     /*初始化延时函数*/
    led_init();                         /*初始化LED*/
    while (1)
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);   /*PB5置高*/
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_RESET); /*PE5置低*/
        delay_ms(500);                                        /*延时500ms*/
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET); /*PB5置低*/
        HAL_GPIO_WritePin(GPIOE, GPIO_PIN_5, GPIO_PIN_SET);   /*PE5置高*/
        delay_ms(500);                                        /*延时500ms*/
    }
}

/**
 * @brief  LED初始化函数
 * @param  None
 * @retval None
 */
void led_init(void)
{
    GPIO_InitTypeDef gpio_initstruct; /*GPIO_InitTypeDef结构体*/
    __HAL_RCC_GPIOB_CLK_ENABLE();     /*使能GPIOB时钟*/
    __HAL_RCC_GPIOE_CLK_ENABLE();     /*使能GPIOE时钟*/

    gpio_initstruct.Pin = GPIO_PIN_5;             /*选择PB5*/
    gpio_initstruct.Mode = GPIO_MODE_OUTPUT_PP;   /*推挽输出*/
    gpio_initstruct.Pull = GPIO_PULLUP;           /*不带上下拉*/
    gpio_initstruct.Speed = GPIO_SPEED_FREQ_HIGH; /*高速*/
    HAL_GPIO_Init(GPIOB, &gpio_initstruct);       /*初始化GPIOB*/

    gpio_initstruct.Pin = GPIO_PIN_5;       /*选择PE5*/
    HAL_GPIO_Init(GPIOE, &gpio_initstruct); /*初始化GPIOE*/
}
