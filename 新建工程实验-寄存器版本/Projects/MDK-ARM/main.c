#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"

int main(void)
{
    uint8_t t=0;
    sys_stm32_clock_init(9);    // 设置时钟,72M
    delay_init(72);             // 初始化延时函数
    usart_init(72,115200);      // 初始化串口波特率115200

    while(1)
    {
        printf("t:%d\r\n", t);        // 延时1秒
        delay_ms(1000);
        t++;
    }
}
