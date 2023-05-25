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

    
    //defineCompany(); 

    while(1){
    
    //int lastCompany 
    int randomNum = randomizedNumber(9500);
    int companyValue = randomCompany(randomNum);
    //struct randomizedCompany = defineCompany(randomNum); 

    // while(randomizedCompany != lastCompany){
    int num = 0;
    int prevNum = 0;
    switch (companyValue)
    {
    case 1:
        lcd_printf("Hederlige Harrys Bilar");
        while(prevNum == num){
           num = randomizedNumber(3);
        } 
        lcd_set_cursor(0,1);
        if(num == 1){
            lcd_printf("Köp bil hos Harry");
        }
        else if(num == 2){
            lcd_printf("En god bilaffär (för Harry!)");
        }
        else{
            lcd_printf("Bumblebee? you wish");
        }
        _delay_ms(1000);
        lcd_clear();
        break;
    
    case 2:
        lcd_printf("Farmor Ankas Pajer AB");
        while(prevNum == num){
           num = randomizedNumber(2);
        }
        lcd_set_cursor(0,1);
        if(num == 1){
            lcd_printf("Köp paj hos Farmor Anka");
        }
        else if(num == 2){
            lcd_printf("Skynda innan Mårten ätit alla pajer");
        }
        _delay_ms(1000);
        lcd_clear();
        break;

    case 3:
        lcd_printf("Svarte Petters Svartbyggen");
        while(prevNum == num){
           num = randomizedNumber(2);
        }
        lcd_set_cursor(0,1);
        if(num == 1){
            lcd_printf("Låt Petter bygga åt dig");
        }
        else if(num == 2){
            lcd_printf("Bygga svart? Ring Petter");
        }
        _delay_ms(1000);
        lcd_clear();
        break;
    case 4:
        lcd_printf("IOT:s REklambyrå");
        num = randomizedNumber(1);
        lcd_set_cursor(0,1);
        if(num == 1){
            lcd_printf("Synas här? IOT:s Reklambyrå");
        }
        _delay_ms(1000);
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
