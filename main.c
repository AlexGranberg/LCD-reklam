#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "uart.h"
#include "millis.h"
#include "lcd.h"
#include <string.h>


#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

int randomizedNumber(int randomMax){
    return (rand() % randomMax)  + 1;
    }

int randomCompany(int valueIn) {
    if(valueIn < 5001) return 1;
    if(valueIn < 8001) return 2;
    if(valueIn < 9501) return 3;
    if(valueIn < 10501) return 4;
}

void custom_delay_ms(uint16_t ms) {
  for (uint16_t i = 0; i < ms; i++) {
    _delay_us(1000); // Delay 1ms
  }
}

void lcd_scroll_text(char* text, int delay_ms) {
  int len = strlen(text);

  for (int i = 0; i <= len; i++) {
    lcd_set_cursor(0, 1);
    lcd_printf("%-16s", text + i);
    custom_delay_ms(delay_ms);
  }
}

int main(){
    lcd_init();
    int num = 0;
    int prevNum = 0;

    while(1){
    int randomNum = randomizedNumber(9500);
    int companyValue = randomCompany(randomNum);
    while(prevNum != companyValue){
        prevNum = companyValue;
        switch (companyValue)
        {
        case 1:
            lcd_printf("Hederlige Harrys Bilar");
            num = randomizedNumber(3); 
            lcd_set_cursor(0,1);
            if(num == 1){
                lcd_scroll_text("Kop bil hos Harry", 500);
            }
            else if(num == 2){
                lcd_scroll_text("En god bilaffar (for Harry!)", 500);
            }
            else{
                lcd_scroll_text("Bumblebee? you wish", 500);
            }
            lcd_clear();
            break;
        
        case 2:
            lcd_printf("Absolut Vodka");
            
            num = randomizedNumber(2);
            lcd_set_cursor(0,1);
            if(num == 1){
                lcd_printf("For men who can");
                _delay_ms(2000);
                lcd_set_cursor(0,1);
                lcd_printf("                 ");
                lcd_set_cursor(0,1);
                lcd_printf("set boundaries");
            }
            else if(num == 2){
                lcd_printf("For those of you");
                _delay_ms(2000);
                lcd_set_cursor(0,1);
                lcd_printf("                 ");
                lcd_set_cursor(0,1);
                lcd_printf("who have made");
                _delay_ms(2000);
                lcd_set_cursor(0,1);
                lcd_printf("                 ");
                lcd_set_cursor(0,1);
                lcd_printf("up your mind");
            }
            _delay_ms(2000);
            lcd_clear();
            break;

        case 3:
            lcd_printf("Claes Monsson");
            num = randomizedNumber(2);
            lcd_set_cursor(0,1);
            if(num == 1){
                lcd_scroll_text("Alltid nogot i backfickan", 500);
            }
            else if(num == 2){
                lcd_scroll_text("Om flickan sjalv far valja", 500);
            }
            lcd_clear();
            break;
        case 4:
            lcd_printf("IOT:s REklambyrå");
            num = randomizedNumber(1);
            lcd_set_cursor(0,1);
            if(num == 1){
                lcd_printf("Synas här? IOT:s Reklambyrå");
            }
            _delay_ms(4000);
            lcd_clear();
            break;

        default:
            break;
        }
    }
    }

    return 0;
}
