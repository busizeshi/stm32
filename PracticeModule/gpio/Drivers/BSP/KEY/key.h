#ifndef _KEY_H_
#define _KEY_H_

#include "./SYSTEM/sys/sys.h"

#define KEY_GPIO_PORT GPIOE
#define KEY_GPIO_PIN GPIO_PIN_4
#define KEY_GPIO_CLK_ENABLE() __HAL_RCC_GPIOE_CLK_ENABLE()

// 读取输出值
#define Key_Read() HAL_GPIO_ReadPin(KEY_GPIO_PORT, KEY_GPIO_PIN)

void key_init(void);

uint8_t key_scan(uint8_t mode);

#endif
