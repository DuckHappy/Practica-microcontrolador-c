#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "esp_timer.h"
#include "tm1637.h"
#include "led_strip.h"

//Tag para debugger serie
static const char *TAG = "Reloj";

//Variables globales
uint8_t segundos=0;
uint8_t minutos=0;

static void IRAM_ATTR rutinaISR_IRQ (void *args)
{
    segundos=-1;
    minutos=0;
}

void app_main(void)
{
	ESP_LOGI(TAG,"Comienza...");
	//Definimos el TM1637
	const gpio_num_t pin_clk = 1;
	const gpio_num_t pin_dta = 10;
	tm1637_led_t * lcd = tm1637_init(pin_clk, pin_dta);
	tm1637_set_segment_number(lcd,0,0x0,1);
	tm1637_set_segment_number(lcd,1,0x0,1);
	tm1637_set_segment_number(lcd,2,0x0,1);
	tm1637_set_segment_number(lcd,3,0x0,1);

	while(1){
		vTaskDelay( 1000 / portTICK_PERIOD_MS);
		segundos++;
		if (segundos==60){
			segundos=0;
			minutos++;
			if (minutos==60){
				minutos=0;
			}
		}
		uint8_t low = segundos%10;
		uint8_t high = segundos/10;
		tm1637_set_segment_number(lcd,3,low,1);
		tm1637_set_segment_number(lcd,2,high,1);
		low = minutos%10;
		high = minutos/10;
		tm1637_set_segment_number(lcd,1,low,1);
		tm1637_set_segment_number(lcd,0,high,1);
	}

}
