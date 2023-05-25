#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "uart.h"
#include "millis.h"
#include "lcd.h"


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

int main(){
    lcd_init();
    
    lcd_puts("Hej!!");
    _delay_ms(5000);
    
    //defineCompany(); 

    while(1){
    
    //int lastCompany 
    int randomNum = randomizedNumber(5000);
    int companyValue = randomCompany(randomNum);
    //struct randomizedCompany = defineCompany(randomNum); 

    // while(randomizedCompany != lastCompany){
    
    switch (companyValue)
    {
    case 1:
        lcd_printf("Hederlige Harrys Bilar");
        int num = randomizedNumber(3);
        lcd_set_cursor(0,1);
        if(num == 1){
            lcd_printf("Köp bil hos Harry");
        }
        else if(num == 2){
            lcd_printf("Köp bil hos Harry");
        }
        else{
            lcd_printf("Köp bil hos Harry");
        }
        _delay_ms(5000);
        lcd_clear();
        break;
    
    default:
        break;
    }

    //    if company:
    //      num = randomizeNumber(numOfCommercial);
    //      print(commercial); 
    // 
    //}
    }

    return 0;
}
