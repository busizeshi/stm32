#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"

// 外设初始化
void key_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // 使能外设时钟
    KEY_GPIO_CLK_ENABLE();

    // 配置GPIO引脚
    GPIO_InitStruct.Pin = KEY_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;       // 输入
    GPIO_InitStruct.Pull = GPIO_PULLUP;           // 上拉
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; // 高速
    HAL_GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStruct);
}

// 按键扫描函数
uint8_t key_scan(uint8_t mode)
{
    static uint8_t key_up = 1; // 按键松开标志
    if (mode)                  // 连续扫描模式
        key_up = 1;
	uint8_t tmp1=Key_Read();
    if (tmp1 == GPIO_PIN_RESET) // 按键按下
    {
        if (key_up) // 按键之前是松开的
        {
            key_up = 0;                       // 标记按键为按下状态
            delay_ms(10);                     // 消抖延时
			uint8_t tmp2=Key_Read();
            if (tmp2 == GPIO_PIN_RESET) // 再次确认按键仍然按下
                return 1;                     // 返回按键按下事件
        }
    }
    else
    {
        key_up = 1; // 按键松开
    }
    return 0; // 无按键事件
}
