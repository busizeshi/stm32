#ifndef _BEEP_H_
#define _BEEP_H_

#include "./SYSTEM/sys/sys.h"

// 定义外设引脚
#define BEEP_GPIO_PORT GPIOB
#define BEEP_GPIO_PIN GPIO_PIN_8

// 定义外设开启时钟
#define BEEP_GPIO_CLK_ENABLE()        \
    do                                \
    {                                 \
        __HAL_RCC_GPIOB_CLK_ENABLE(); \
    } while (0)

// 定义外设GPIO写入宏
#define BEEP(x)                                                               \
    do                                                                        \
    {                                                                         \
        if (x)                                                                \
            HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN, GPIO_PIN_SET);   \
        else                                                                  \
            HAL_GPIO_WritePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN, GPIO_PIN_RESET); \
    } while (0)

#define BEEP_TOGGLE()                                      \
    do                                                     \
    {                                                      \
        HAL_GPIO_TogglePin(BEEP_GPIO_PORT, BEEP_GPIO_PIN); \
    } while (0)

// 外设初始化
void beep_init(void);

#endif
