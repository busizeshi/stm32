#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/delay/delay.h"
#include "./SYSTEM/usart/usart.h"
#include "./BSP/LED/led.h"

int main(void)
{
    HAL_Init();
    sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟为72MHz */
    delay_init(72);                     /* 初始化延时函数 */
    led_init();                         /* 初始化LED */

    while(1)
    {
        LED0(0);   /* 点亮LED0 */
        LED1(1);   /* 熄灭LED1 */
        delay_ms(500);
        LED0(1);
        LED1(0);   /* 点亮LED1 */
        delay_ms(500);
    }
}
