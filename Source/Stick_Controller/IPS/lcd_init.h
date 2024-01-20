#ifndef __LCD_INIT_H
#define __LCD_INIT_H

#include "main.h"
#include "spi.h"

#define USE_HORIZONTAL 3 // ���ú�������������ʾ 0��1Ϊ���� 2��3Ϊ����

#if USE_HORIZONTAL == 0 || USE_HORIZONTAL == 1
#define LCD_W 80
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 80
#endif

//-----------------LCD�˿ڶ���----------------
#define LCD_RES_Clr() IPS_RES_GPIO_Port->BRR = IPS_RES_Pin // RES
#define LCD_RES_Set() IPS_RES_GPIO_Port->BSRR = IPS_RES_Pin

#define LCD_DC_Clr() IPS_DC_GPIO_Port->BRR = IPS_DC_Pin// DC
#define LCD_DC_Set() IPS_DC_GPIO_Port->BSRR = IPS_DC_Pin

#define LCD_CS_Clr() IPS_CS_GPIO_Port->BRR = IPS_CS_Pin // CS
#define LCD_CS_Set() IPS_CS_GPIO_Port->BSRR = IPS_CS_Pin

#define LCD_BLK_Clr() IPS_BLK_GPIO_Port->BRR = IPS_BLK_Pin // BLK
#define LCD_BLK_Set() IPS_BLK_GPIO_Port->BSRR = IPS_BLK_Pin

void LCD_Writ_Bus(uint8_t dat);                                           // ģ��SPIʱ��
void LCD_WR_DATA8(uint8_t dat);                                           // д��һ���ֽ�
void LCD_WR_DATA(uint16_t dat);                                           // д�������ֽ�
void LCD_WR_REG(uint8_t dat);                                             // д��һ��ָ��
void LCD_Address_Set(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2); // �������꺯��
void LCD_Init(void);                                                      // LCD��ʼ��
#endif
