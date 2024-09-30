#include< xc.h >

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config BOREN = OFF


#define LED_VERDE_VIAT PORTBbits.RB0
#define LED_LARANJA_VIAT PORTBbits.RB1
#define LED_VERMELHO_VIAT PORTBbits.RB2

#define LED_VERMELHO_PEAO PORTBbits.RB3
#define LED_VERDE_PEAO PORTBbits.RB4
#define BOTAO_DE_PEAO PORTDbits.RD0

void delay(int ms) {
    for (int i = 0; i < ms; i++) {
        __delay_ms(1);
    }
}

void main() {
    TRISB = 0x00;
    TRISD = 0x01;


    LED_VERDE_VIAT = 1;
    LED_LARANJA_VIAT = 0;
    LED_VERMELHO_VIAT = 0;

    LED_VERDE_PEAO = 0;
    LED_VERMELHO_PEAO = 1;

    while (1) {
        if (BOTAO_DE_PEAO == 1) {
            LED_VERDE_VIAT = 0;
            LED_LARANJA_VIAT = 1;
            delay(6000);
            LED_LARANJA_VIAT = 0;
            LED_VERMELHO_VIAT = 1;

            LED_VERMELHO_PEAO = 0;
            LED_VERDE_PEAO = 1;
            delay(30000);

            LED_VERDE_PEAO = 0;
            LED_VERMELHO_PEAO = 1;
            LED_VERMELHO_VIAT = 0;
            LED_VERDE_VIAT = 1;
        }
    }
}
