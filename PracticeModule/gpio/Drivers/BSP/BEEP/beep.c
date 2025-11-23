#include "./BSP/BEEP/beep.h"

// 外设初始化
void beep_init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // 使能外设时钟
    BEEP_GPIO_CLK_ENABLE();

    // 配置GPIO引脚
    GPIO_InitStruct.Pin = BEEP_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;   // 推挽输出
    GPIO_InitStruct.Pull = GPIO_PULLUP;           // 上拉
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH; // 高速

    HAL_GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStruct);

    // 初始化时关闭蜂鸣器
    BEEP(0);
}
