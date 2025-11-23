#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/KEY/key.h"
#include "./BSP/BEEP/beep.h"

int main(void)
{
    HAL_Init();                         // 初始化HAL库
    sys_stm32_clock_init(RCC_PLL_MUL9); // 配置系统时钟为72MHz
    delay_init(72);                     // 初始化延时函数
    key_init();                         // 初始化按键
    beep_init();                        // 初始化蜂鸣器

    while (1)
    {
        if (key_scan(0)) // 检测到按键按下
        {
            BEEP(1); // 打开蜂鸣器
			delay_ms(1000);
        }
        else
        {
            BEEP(0); // 关闭蜂鸣器
        }
    }
}
