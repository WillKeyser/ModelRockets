/*  Author:    Will Keyser
 *  Date:      July 10, 2013
 *  Copyright: Don't be rediculous
 *  
 *  This time, we are going to launch a rocket by waiting for the arduino to "arm" and then pressing the fire button.
 *  Feel free to modify and use this code in your arduino-based endevours!
 */

//import the HD44780 instruction set arduino library
#include <LiquidCrystal.h>

//Define our variables
const int buttonPin = 8;
const int relayPin = 6;
const int statPin = 13;
int buttonState;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;

//Attach "lcd" to the correct pins...
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Initial Setup function
void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(statPin, OUTPUT);
  
  //Initialize the LCD
  lcd.begin(8, 2);
  delay(3);
  lcd.print("ROCKETS!");
  lcd.setCursor(0, 1);
  lcd.print("********");
  lcd.setCursor(0, 0);
  delay(30000);
  
  //My fun little Arming animation
  lcd.clear();
  delay(2);
  lcd.print(" Arming ");
  lcd.setCursor(0, 1);
  lcd.print(".     ");
  delay(500);
  digitalWrite(statPin, HIGH);
  lcd.setCursor(0, 1);
  lcd.print("..    ");
  delay(500);
  digitalWrite(statPin, LOW);
  lcd.setCursor(0, 1);
  lcd.print("...   ");
  delay(500);
  digitalWrite(statPin, HIGH);
  lcd.setCursor(0, 1);
  lcd.print("....  ");
  delay(500);
  digitalWrite(statPin, LOW);
  lcd.setCursor(0, 1);
  lcd.print("..... ");
  delay(500);
  digitalWrite(statPin, HIGH);
  lcd.setCursor(0, 1);
  lcd.print("......");
  delay(500);
  digitalWrite(statPin, HIGH);
  lcd.setCursor(0, 1);
  lcd.print(".......");
  delay(500);
  digitalWrite(statPin, LOW);
  lcd.setCursor(0, 1);
  lcd.print("........");
  delay(500);
  digitalWrite(statPin, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Armed! ");
  lcd.setCursor(0, 1);
  lcd.print("++++++++");
  lcd.setCursor(0, 0);
  //Wasn't that fun? :D
}

//Our main loop
void loop() {

//All of this is our button-state check  
int reading = digitalRead(buttonPin);
  
if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the firing timer if the new button state is HIGH
      if (buttonState == HIGH) {

  //Begin the 5 second countdown
  delay(100);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Firing: ");
  lcd.setCursor(0, 1);
  lcd.print("5");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("4");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("3");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("2");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("1");
  delay(1000);
  lcd.clear();
  
  //Time for the BOOM!
  lcd.setCursor(0, 0);
  lcd.print("- BOOM -");
  digitalWrite(relayPin, HIGH);  //triggers the relay, giving the +6V to the igniter
  lcd.setCursor(0, 1);
  lcd.print("--------");
 
  }
    }
  }
    lastButtonState = reading;
  }
 
  
  
  /*  And that's it! Just reset the MCU for more rocket fun!
   *
   *  Try other means of launching like ethernet, infrared, and more!
   *  
   *  Have fun, and BE SAFE!
   */

