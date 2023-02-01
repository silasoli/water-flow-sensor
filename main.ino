#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
int X, Y;
float TIME, FREQUENCY, WATER, TOTAL, LS = 0;
const int input = A0;
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(input, INPUT);
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Medidor de");
  lcd.setCursor(3, 1);
  lcd.print("Fluxo Agua");
  delay(2000);
}
void loop()
{
  X = pulseIn(input, HIGH);
  Y = pulseIn(input, LOW);
  TIME = X + Y;
  FREQUENCY = 1000000 / TIME;//Pulsos por segundo
  WATER = FREQUENCY / 7.5; //Fator de calculo é 7.5
  LS = WATER / 60; //Vazão em litros por minuto
  if (FREQUENCY >= 0)
  {
    if (isinf(FREQUENCY))
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fluxo: 0.00");
      lcd.setCursor(0, 1);
      lcd.print("Total: ");
      lcd.print( TOTAL);
      lcd.print(" Lts");
      Serial.println("Total: ");
      Serial.print(TOTAL);
      Serial.println(" Lts");
    }
    else
    {
      TOTAL = TOTAL + LS;
      Serial.println(FREQUENCY);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("FLUXO: ");
      lcd.print(WATER);
      lcd.print(" L/M");
      lcd.setCursor(0, 1);
      lcd.print("TOTAL: ");
      lcd.print( TOTAL);
      lcd.print(" Lts");
      Serial.println("FLUXO: ");
      Serial.print(WATER);
      Serial.println(" L/M");
      Serial.println("Total: ");
      Serial.print(TOTAL);
      Serial.println(" Lts");
    }
  }
  delay(1000);
}
