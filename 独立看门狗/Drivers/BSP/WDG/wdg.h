/**
 * @file    wdg.c
 * @brief   独立看门狗驱动程序
 */
#ifndef __WDG_H
#define __WDG_H

#include "./SYSTEM/sys/sys.h"
#include "./stm32f1xx_hal_wwdg.h"

void iwdg_init(uint8_t prer, uint16_t rlr);
void iwdg_feed(void);

#endif /* __WDG_H */
