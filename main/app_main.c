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

//用户函数入口，相当于main函数
void app_main()
{
  char buff[20]={0};
  unsigned char t=0;

  //显示屏初始化
  Lcd_Init();

  //显示屏提示信息
  Gui_DrawFont_GBK24(15,0,RED,WHITE,(u8 *)"悦为电子");
  Gui_DrawFont_GBK16(16,34,VIOLET,WHITE,(u8 *)"深圳悦为电子");
  Gui_DrawFont_GBK16(32,50,BLUE,WHITE,(u8 *)"欢迎您");
  Gui_DrawFont_GBK16(20,70,RED,WHITE,(u8 *)"1.44彩色TFT");
  Gui_DrawFont_GBK16(6,90,VIOLET,BLACK,(u8 *)"显示屏测试程序");
  Gui_DrawFont_GBK16(0,110,BLUE,WHITE,(u8 *)"ASCII:");
  Gui_DrawFont_GBK16(64,110,BLUE,WHITE,(u8 *)"CODE:");


  t=' ';  
  while(1) 
  { 
      sprintf(buff, "%c", t);
      Gui_DrawFont_GBK16(48,110,RED,WHITE,(u8 *)buff);//显示ASCII字符    
      t++;
      if(t>'~')t=' ';

      sprintf(buff, "%d ", t);
      Gui_DrawFont_GBK16(104,110,RED,WHITE,(u8 *)buff);//显示ASCII字符的码值          
      
      vTaskDelay(50);
  }
}

