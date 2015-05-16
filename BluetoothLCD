int count = 0;
int swi = 0;
// include the library code:
#include <SoftwareSerial.h> //you need the software serial library
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
SoftwareSerial mySerial(10, 11);
void setup() {
  
  mySerial.begin(9600);
  lcd.begin(20, 4);
  lcd.print("start");
}

void loop()
{
  int count;
  boolean bool;
  if(mySerial.available()) {
    delay(200);
    lcd.clear();
    count = 0;
    bool = false; //for second line
    while (mySerial.available() > 0) {
      if (count > 15 && bool == false ) {
        lcd.setCursor(0,1);
        bool = true;
      }
      lcd.write(mySerial.read());
      count++;
    }
  }
}
