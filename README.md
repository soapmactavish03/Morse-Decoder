Morse Decoder with Arduino and I2C LCD

This project implements a real-time Morse code decoder using an Arduino and a 16x2 I2C LCD. The system detects button presses to interpret dots (.) and dashes (-) as letters and words, displays decoded text on the LCD, and includes a fast-press reset feature to clear the display.

Features

Decode dots (.) and dashes (-) from button input.

Letter and word spacing automatically detected.
			
Output displayed on a 16x2 I2C LCD, scrolling for long text.

Fast-press reset: rapidly pressing the button 5–7 times clears the display.

Supports letters A–Z and numbers 0–9.

Easily extendable for punctuation or special symbols.

Components

Arduino Uno / Nano / Mega

Push button

16x2 I2C LCD

10kΩ resistor (for pull-down, if needed)

An active piezo-buzzer for sound cues

Breadboard and jumper wires

Wiring

Button:

One side → A1 (analog pin)

Other side → GND

Pull-up/down resistor if needed

I2C LCD:

GND → GND

VCC → 5V

SDA → A4 (Arduino Uno/Nano)

SCL → A5 (Arduino Uno/Nano)

Note: Adjust SDA and SCL pins for different Arduino boards.

Code Overview

Morse input detection: Uses analogRead() on a button.

Timing: Uses millis() to measure press duration (dot vs dash) and hold duration (letter/word gap).

Decoder: Converts dot/dash sequences into letters and numbers.

Display: Prints decoded text to a 16x2 I2C LCD, scrolling if longer than 16 characters.

Reset feature: Rapid repeated presses clear the display without registering extra dots.

Usage

Connect the hardware as described in the wiring section.

Upload the Arduino sketch to your board.

Press the button to input Morse code:

Short press (~<20ms): dot (.)

Long press (>200ms): dash (-)

Pause briefly between letters (~700ms) to end a letter.

Pause longer between words (~1800ms) to add space.

Libraries

LiquidCrystal_I2C
 – for I2C LCD control

Install via Arduino IDE Library Manager or manually from GitHub.

Customization

Adjust threshold for analog button reading.

Modify letter and word gap times in holdDuration if your press timing differs.

Add more Morse symbols (punctuation) by extending the SymbolDecoder() function.

Screenshots

![Morse-Decoder-Breadboard-implementation.jpg](https://github.com/user-attachments/assets/e08d36a0-9f45-465e-a59e-aee7b8926bb8)


License

This project is released under the MIT License. Feel free to use, modify, and share.

