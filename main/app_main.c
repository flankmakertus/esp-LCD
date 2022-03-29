#include <stdio.h>
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "esp_err.h"
#include "nvs_flash.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/ledc.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "string.h"
#include "Lcd.h"

//�û�������ڣ��൱��main����
void app_main()
{
  char buff[20]={0};
  unsigned char t=0;

  //��ʾ����ʼ��
  Lcd_Init();

  //��ʾ����ʾ��Ϣ
  Gui_DrawFont_GBK24(15,0,RED,WHITE,(u8 *)"��Ϊ����");
  Gui_DrawFont_GBK16(16,34,VIOLET,WHITE,(u8 *)"������Ϊ����");
  Gui_DrawFont_GBK16(32,50,BLUE,WHITE,(u8 *)"��ӭ��");
  Gui_DrawFont_GBK16(20,70,RED,WHITE,(u8 *)"1.44��ɫTFT");
  Gui_DrawFont_GBK16(6,90,VIOLET,BLACK,(u8 *)"��ʾ�����Գ���");
  Gui_DrawFont_GBK16(0,110,BLUE,WHITE,(u8 *)"ASCII:");
  Gui_DrawFont_GBK16(64,110,BLUE,WHITE,(u8 *)"CODE:");


  t=' ';  
  while(1) 
  { 
      sprintf(buff, "%c", t);
      Gui_DrawFont_GBK16(48,110,RED,WHITE,(u8 *)buff);//��ʾASCII�ַ�    
      t++;
      if(t>'~')t=' ';

      sprintf(buff, "%d ", t);
      Gui_DrawFont_GBK16(104,110,RED,WHITE,(u8 *)buff);//��ʾASCII�ַ�����ֵ          
      
      vTaskDelay(50);
  }
}

