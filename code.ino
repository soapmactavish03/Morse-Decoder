#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = A1;  
unsigned long pressStartTime = 0;
unsigned long pressDuration = 0;
unsigned long holdStartTime = 0;
unsigned long holdDuration = 0;
String Symbol = "";
String DisplayText = "";

bool buttonPressed = false;
const int threshold = 800; // adjust based on your wiring

// Morse decoder function
char SymbolDecoder(String &x){
  if (x == ".-") return 'A';
  if (x == "-...") return 'B';
  if (x == "-.-.") return 'C';
  if (x == "-..") return 'D';
  if (x == ".") return 'E';
  if (x == "..-.") return 'F';
  if (x == "--.") return 'G';
  if (x == "....") return 'H';
  if (x == "..") return 'I';
  if (x == ".---") return 'J';
  if (x == "-.-") return 'K';
  if (x == ".-..") return 'L';
  if (x == "--") return 'M';
  if (x == "-.") return 'N';
  if (x == "---") return 'O';
  if (x == ".--.") return 'P';
  if (x == "--.-") return 'Q';
  if (x == ".-.") return 'R';
  if (x == "...") return 'S';
  if (x == "-") return 'T';
  if (x == "..-") return 'U';
  if (x == "...-") return 'V';
  if (x == ".--") return 'W';
  if (x == "-..-") return 'X';
  if (x == "-.--") return 'Y';
  if (x == "--..") return 'Z';
  if (x == "-----") return '0';
  if (x == ".----") return '1';
  if (x == "..---") return '2';
  if (x == "...--") return '3';
  if (x == "....-") return '4';
  if (x == ".....") return '5';
  if (x == "-....") return '6';
  if (x == "--...") return '7';
  if (x == "---..") return '8';
  if (x == "----.") return '9';
  return '?';
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Morse Decoder:");
}

void loop() {
  int buttonValue = analogRead(buttonPin);

  // --- BUTTON PRESSED ---
  if (buttonValue > threshold && !buttonPressed) {
    pressStartTime = millis();
    buttonPressed = true;
  }

  // --- BUTTON RELEASED ---
  if (buttonValue <= threshold && buttonPressed) {
    pressDuration = millis() - pressStartTime;

    if (pressDuration > 200) {
      Symbol += '-';
    }
    else if (pressDuration > 10) {
      Symbol += '.';
    }

    buttonPressed = false;
    holdStartTime = millis();
  }

  // --- CHECK HOLD GAP (while unpressed) ---
  if (!buttonPressed && holdStartTime > 0) {
    holdDuration = millis() - holdStartTime;

    // letter gap
    if (holdDuration > 600 && Symbol.length() > 0) {
      DisplayText += SymbolDecoder(Symbol);
      Symbol = "";
      holdStartTime = millis(); // restart timer
      updateLCD();
    }

    // word gap
    if (holdDuration > 1800) {
      DisplayText += " ";
      holdStartTime = 0;
      updateLCD();
    }
  }
}

// Update LCD with scrolling for long text
void updateLCD() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Morse Decoder:");

  lcd.setCursor(0,1);
  if(DisplayText.length() > 16){
    lcd.print(DisplayText.substring(DisplayText.length()-16));
  } else {
    lcd.print(DisplayText);
  }
}
