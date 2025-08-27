# Morse Decoder with Arduino and I2C LCD

A real-time Morse code decoder using an Arduino and a 16x2 I2C LCD. Decode dots (.) and dashes (-) from a button, display letters and words, and reset the display with rapid presses.

## 🌟 Features

Decode dots (.) and dashes (-) into letters and numbers.
Automatic letter and word spacing detection.
Output displayed on a 16x2 I2C LCD, with scrolling for long text.
Fast-press reset: Press the button 5–7 times quickly to clear display.
Supports letters A–Z and numbers 0–9.
Easily extendable for punctuation or special symbols.

## 📦 Components

Arduino Uno / Nano / Mega
Push button
16x2 I2C LCD (HD44780 with I2C backpack)
10kΩ resistor (pull-down if needed)
Breadboard and jumper wires
Active Buzzer for sound cues

## 🔌 Wiring

Button:
One side → A1 (analog pin)
Other side → GND
Pull-up/down resistor if needed
I2C LCD:
GND → GND
VCC → 5V
SDA → A4 (Arduino Uno/Nano)
SCL → A5 (Arduino Uno/Nano)
Adjust SDA/SCL for different boards.

## 🗂 Folder Structure
MorseDecoder/
├─ src/
│  └─ MorseDecoder.ino      # Arduino sketch
├─ README.md                # Project README
├─ LICENSE                  # MIT License
└─ libraries/               # Optional local libraries

## 💻 Code Overview

Button input: Uses analogRead() to detect dots and dashes.
Timing: millis() measures press duration (dot/dash) and hold duration (letter/word gap).
Decoder: Converts Morse sequences into letters and numbers.
Display: Shows decoded text on 16x2 I2C LCD with scrolling for long messages.
Reset: Rapid repeated presses clear the display without registering extra dots.

## ⚙️ Usage

Connect hardware as described.
Open MorseDecoder.ino in Arduino IDE.
Select correct board and port, then Upload.
Press the button to input Morse code:
Short press (<200ms) → dot (.)
Long press (>200ms) → dash (-)
Pause briefly (~600ms) to end a letter.
Pause longer (~1400ms) to add a word space.

## 📚 Libraries

LiquidCrystal_I2C
Install via Arduino IDE Library Manager or manually.

## 🔧 Customization

Adjust threshold for analog button reading.
Modify letter and word gap durations if timing differs.
Extend SymbolDecoder() for punctuation or extra symbols.

## 🖼 Screenshots

![Morse-Breadboard-Implementation](https://github.com/user-attachments/assets/41908d69-9ace-4342-977a-18428ca4d1c3)

## ⚠ Tips for Best Performance

Button press timing: Keep dots short (<200ms) and dashes longer (>200ms).
Avoid bouncing: Add a small debounce delay if needed.
Adjust gap times for your speed of input.

## 📜 License

This project is licensed under the MIT License.
