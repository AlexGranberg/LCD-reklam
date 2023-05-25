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
                lcd_printf("Köp bil hos Harry");
            }
            else if(num == 2){
                lcd_printf("En god bilaffär (för Harry!)");
            }
            else{
                lcd_printf("Bumblebee? you wish");
            }
            _delay_ms(2000);
            lcd_clear();
            break;
        
        case 2:
            lcd_printf("Farmor Ankas Pajer AB");
            num = randomizedNumber(2);
            lcd_set_cursor(0,1);
            if(num == 1){
                lcd_printf("Köp paj hos Farmor Anka");
            }
            else if(num == 2){
                lcd_printf("Skynda innan Mårten ätit alla pajer");
            }
            _delay_ms(2000);
            lcd_clear();
            break;

        case 3:
            lcd_printf("Svarte Petters Svartbyggen");
            num = randomizedNumber(2);
            lcd_set_cursor(0,1);
            if(num == 1){
                lcd_printf("Låt Petter bygga åt dig");
            }
            else if(num == 2){
                lcd_printf("Bygga svart? Ring Petter");
            }
            _delay_ms(2000);
            lcd_clear();
            break;
        case 4:
            lcd_printf("IOT:s REklambyrå");
            num = randomizedNumber(1);
            lcd_set_cursor(0,1);
            if(num == 1){
                lcd_printf("Synas här? IOT:s Reklambyrå");
            }
            _delay_ms(2000);
            lcd_clear();
            break;

        default:
            break;
        }
    }
    }

    return 0;
}
