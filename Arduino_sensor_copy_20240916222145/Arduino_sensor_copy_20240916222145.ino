#include <TFT.h> // Hardware-specific library
#include <SPI.h>

#define CS   10
#define DC   9
#define RESET  8

char sensorPrintout[4];

// pin definition for the Leonardo


TFT myScreen = TFT(CS, DC, RESET);

int u = 0; // переменная для числа пребразования 0-1023
float u_in = 0.0; // переменная для напряжения
float uRef = 1.1;
int FriqMeter = 100;
String difValW = "0";
String sensorValW="0";
String sensorVal = "0";
String difVal = "0";

void setup() {
  myScreen.begin();

  myScreen.background(255, 255, 255);
  myScreen.stroke(0,0,0);
  myScreen.setTextSize(3);
  myScreen.text("VOLTAGE: ", 15, 25);
  myScreen.text("mV", 65, 85);

  pinMode(A4,INPUT);// A1 - аналоговый вход
  Serial.begin(9600);
  analogReference (INTERNAL);
}

float difU (int friqMeter)
{
  float uDif = 0.0;
  for (int i = 0; i<1000/friqMeter; i++)
  {
    u = analogRead(A4); // измерение 
    u_in = (u * uRef) / 1023; 
    uDif += u_in;
    delay (friqMeter);
  }
  uDif = uDif/(1000/friqMeter);
  return uDif;
}


void loop() {
  difValW = difVal;
  sensorValW = sensorVal;

  u = analogRead(A4); // измерение 
  u_in = (u * uRef) / 1023; // пересчет измерения в вольты 

  difVal = String(difU(FriqMeter)); // измерение
  sensorVal = String(u_in);


  myScreen.stroke(255,255,255);//закраска фоном

  sensorValW.toCharArray(sensorPrintout, 4);//рисуем в сек
  myScreen.text(sensorPrintout, 90, 55);

  difValW. toCharArray(sensorPrintout, 4);//рисуем диф
  myScreen.text(sensorPrintout, 20, 55);


  sensorVal.toCharArray(sensorPrintout, 4);//рисуем в сек
  myScreen.stroke(0,0,0);
  myScreen.setTextSize(3);
  myScreen.text(sensorPrintout, 90, 55);

  difVal.toCharArray(sensorPrintout, 4);//рисуем диф
  myScreen.stroke(0,0,0);
  myScreen.setTextSize(3);
  myScreen.text(sensorPrintout, 20, 55);


 






 // Serial.println(u_in); // вывод напряжения в serial monitor



}
