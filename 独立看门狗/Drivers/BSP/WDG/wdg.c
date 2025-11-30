#include "./BSP/WDG/wdg.h"

IWDG_HandleTypeDef g_iwdg_handle; // 独立看门狗句柄

/**
 * @brief 初始化独立看门狗
 * @param prer 预分频器值
 * @param rlr 重装载值
 */
void iwdg_init(uint8_t prer,uint16_t rlr)
{
    g_iwdg_handle.Instance = IWDG;
    g_iwdg_handle.Init.Prescaler = prer; // 设置预分频器
    g_iwdg_handle.Init.Reload = rlr;     // 设置重装载值
    HAL_IWDG_Init(&g_iwdg_handle);
}

void iwdg_feed(void)
{
    HAL_IWDG_Refresh(&g_iwdg_handle); // 喂狗，重装载计数器
}
