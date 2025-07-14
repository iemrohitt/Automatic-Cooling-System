#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);

  lcd_1.print("LOADING.");
  delay(1000); // Wait for 900 millisecond(s)
  lcd_1.print(".");
  delay(1000); // Wait for 1000 millisecond(s)
  lcd_1.print(".");
  delay(1000); // Wait for 1000 millisecond(s)
  lcd_1.print(".");
  delay(1000); // Wait for 1000 millisecond(s)
}

void loop()
{
  lcd_1.clear();
  if ((-40 + 0.488155 * (analogRead(A0) - 20)) >= 79) {
    lcd_1.clear();
    Serial.println((-40 + 0.488155 * (analogRead(A0) - 20)));
    lcd_1.print((-40 + 0.488155 * (analogRead(A0) - 20)));
    Serial.println("Fan: ON");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Fan: ON");
    lcd_1.setCursor(6, 0);
    lcd_1.print("*C");
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    if ((-40 + 0.488155 * (analogRead(A0) - 20)) >= 93) {
      lcd_1.setCursor(10, 0);
      lcd_1.print("HIGH");
      lcd_1.setCursor(10, 1);
      lcd_1.print("TEMP!");
    }
    delay(2000); // Wait for 2000 millisecond(s)
  } else {
    lcd_1.clear();
    Serial.println((-40 + 0.488155 * (analogRead(A0) - 20)));
    lcd_1.print((-40 + 0.488155 * (analogRead(A0) - 20)));
    Serial.println("Fan: OFF");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Fan: OFF");
    lcd_1.setCursor(6, 0);
    lcd_1.print("*C");
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    delay(2000); // Wait for 2000 millisecond(s)
  }
}