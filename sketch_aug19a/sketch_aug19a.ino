#include <16f877a.h>
#fuses xt, nowdty
#use delay(clock=4M)
#define use_port_lcd true
#include <lcd.c>
#use standad_oi(c)

/**
   @file main.c
   @author tulio.benedito
   @date 2024-08-19
   @brief Main function
*/
int main() {

  lcd_init();
  lcd_putc("\f");
  ldc_gotoxy(4, 1);  // Imprime a mendagem na coluna 4 e fila 1
  lcd_putc("Bem vindos");

  delay_ms(2000)
  lcd_putc("\f");
  ldc_gotoxy(3, 1);
  lcd_putc("GENUINO");

  int bandera, bandera2, bandera3; // Imprime o medidor de nivel
  bandera = 1;
  bandera2 = 1;
  bandera3 = 1;

  while (true)
  {
    if (input(PIN_C0) == 0) {
      lcd_gotoxy(3, 2);
      printf(lcd_putc, "Tanque Vazio");
    }

    if (input(PIN_C0) == 1 && bandera == 1) {          //pin C0 primeiro sensor
      lcd_gotoxy(3, 2);
      printf(lcd_putc, "Nivel Baixo");
    }

    if (input(PIN_C1) == 1 && bandera2 == 1) {        //pin C1 segundo sensor
      bandera = 2 ;
      lcd_gotoxy(3, 2);
      printf(lcd_putc, "Nivel Medio");
    }

    else {
      bandera = 1;
    }

    if (input(PIN_C2) == 1 && bandera3 == 1) {        //pin C1 terceiro sensor
      bandera = 2 ;
      bandera2 = 2 ;
      lcd_gotoxy(3, 2);
      printd(lcd_putc, "Nivel Medio");
    }
    else {
      bandera2 = 1;
    }
    delay_ms(100);
  }
};
