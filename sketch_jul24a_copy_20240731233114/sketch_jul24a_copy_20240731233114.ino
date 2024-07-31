#include "TM1637.h"
// int8_t DispMSG[] = {1,2,3,4};
// #define CLK 3//pins definitions for TM1637 and can be changed to other ports       
// #define DIO 2
// TM1637 tm1637(CLK, DIO);

int u = 0; // переменная для числа пребразования 0-1023
float u_in = 0.0; // переменная для напряжения 0.0-5.0c:\Users\михаил\Desktop\Учеба\Ардуино_проджект\sketch_jul24a\examples\TM1637\TM1637.ino
float uRef = 1.1;

void setup() {
  pinMode(A1,INPUT);// A1 - аналоговый вход
  Serial.begin(9600);
  analogReference (INTERNAL);
//  tm1637.init();
//  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop() {
  u = analogRead(A1); // измерение 
  u_in = (u * uRef) / 1023; // пересчет измерения в вольты 
  Serial.println(u_in); // вывод напряжения в serial monitor

  delay(1000); // частота выполения функции 
 
  // int8_t NumTab[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  // int8_t ListDisp[4];
  // tm1637.display(0, DispMSG[0]);
  // // tm1637.display(0,ListDisp[0]);
  // tm1637.display(1,ListDisp[1]); 
  // tm1637.display(2,ListDisp[2]);
  // tm1637.display(3,ListDisp[3]);
  // delay(300);// закомиченная часть - работа с дисплеем 
}
