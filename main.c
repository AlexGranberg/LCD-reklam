#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include "uart.h"
#include "millis.h"
#include "lcd.h"


#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 


int main(void){
    init_serial();
    millis_init();
    sei();
    lcd_init();
    lcd_enable_blinking();
    lcd_enable_cursor();
    //randomizeNumber(int randomMax);
    //defineCompany(); 

    while(1){
    //int lastCompany 
    //int randomNum = randomizeNumber();
    //struct randomizedCompany = defineCompany(randomNum); 

    // while(randomizedCompany != lastCompany){
    //    if company:
    //      num = randomizeNumber(numOfCommercial);
    //      print(commercial); 
    // 
    //}
    }

    return 0;
}
