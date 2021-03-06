// lcd.h

// Enderešos das linhas do LCD
// linha01 = end=0x80;
// linha02 = end=0xC0;

#include <string.h>

#byte portd=0x08
#byte porte=0x09
#bit  rs = porte.2
#bit  enable = porte.1

int   x=0;
int   tam;
char  msg[80];

void comando_lcd(int caractere){
   rs=0;
   enable=1;
   portd=caractere;
   delay_ms(3);
   enable=0;
}

void escreve_lcd(int caractere){
   rs=1;
   enable=1;
   portd=caractere;
   delay_ms(3);
   enable=0;
}

void inicializa_lcd(){
   comando_lcd(0b00111100);
   comando_lcd(0b00001100);
}

void limpa_lcd(){
   comando_lcd(0b00000001);
}

void limpa_lcd_linha(){
   printf(escreve_lcd,"                  ");
}

void limpa_msg(void){
   tam=strlen(msg);
   for(x=0;x<tam;x=x+1)
   {
      msg[x]=0;
      printf("%c",msg[x]);
      delay_ms(100);
   }
   x=0;
}
