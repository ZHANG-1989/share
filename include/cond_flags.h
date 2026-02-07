#pragma once

// 条件位掩码与取值定义（与 YAML 中逻辑保持一致）
#define BIT_TIME   0x01  // bit0
#define BIT_DARK   0x02  // bit1
#define BIT_FUNC   0x04  // bit2
#define BIT_PRES   0x08  // bit3
#define BIT_HUMM   0x10  // bit4
#define BIT_DRYI   0x20  // bit5
#define BIT_MOFF   0x40  // bit6

#define MASK_X1011 (BIT_PRES | BIT_FUNC | BIT_DARK | BIT_TIME)   // 0x0F
#define VAL_X1011  (BIT_PRES | BIT_DARK | BIT_TIME)             // 0x0B
#define MASK_X0XXX (BIT_PRES)                                   // 0x08
#define VAL_X0XXX  (0x00)
#define MASK_010XXX (BIT_HUMM | BIT_PRES | BIT_DRYI)            // 0x38 = 0b00111000
#define VAL_010XXX  (BIT_HUMM)                                  // 0x10 = 0b00010000

// bit7 bit6 bit5 bit4 bit3 bit2 bit1 bit0
//  |    |    |    |    |    |    |    |
//  |    |    |    |    |    |    |    └─ 时间段
//  |    |    |    |    |    |    └───── 暗环境
//  |    |    |    |    |    └────────── 功能开关
//  |    |    |    |    └─────────────── 人在
//  |    |    |    └──────────────────── 湿度传感器
//  |    |    |_________________________ 人工关闭锁
