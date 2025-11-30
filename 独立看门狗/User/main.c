#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/WDG/wdg.h"
#include "./BSP/KEY/key.h"

int main(void)
{
    HAL_Init();               // 初始化HAL库
    sys_stm32_clock_init(RCC_PLL_MUL9); // 设置时钟,72MHz
    delay_init(72);          // 初始化延时函数
    usart_init(115200);      // 初始化串口
    led_init();              // 初始化LED
    key_init();              // 初始化按键
    delay_ms(100);          // 延时100ms
    iwdg_init(IWDG_PRESCALER_64, 625); // 初始化独立看门狗，1秒超时
    LED0(0);                  // 点亮LED0

    while(1)
    {
        if(key_scan(1) == WKUP_PRES) // 检测按键KEY0是否按下
        {
            iwdg_feed(); // 喂狗
        }

        delay_ms(10); // 延时10ms
    }
}
