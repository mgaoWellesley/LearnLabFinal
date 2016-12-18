/*
 * Final Project Code Arduino
 * CS320 
 * By: Michelle Gao, Annie Wang, and Ruby Feng 
 * Date: 12/16/2017
 * 
 * Code has been modified from examples from: https://www.arduino.cc/en/Tutorial/Button for the button, 
 * http://bildr.org/2012/11/force-sensitive-resistor-arduino/ 
 * and https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsrfor the force sensitive resistors.
 */
 


// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

int fsrAnalogPin = 0; // FSR is connected to analog 0
int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;      // the analog reading from the FSR resistor divider
int LEDbrightness;

int fsrAnalogPin2 = 1; // FSR is connected to analog 0
int LEDpin2 = 9;      // connect Red LED to pin 11 (PWM pin)
int fsrReading2;      // the analog reading from the FSR resistor divider
int LEDbrightness2;

void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin, OUTPUT);
  pinMode(LEDpin2, OUTPUT);

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}
 
void loop(void) {
  fsrReading = analogRead(fsrAnalogPin);
  //Serial.print("Analog reading = ");
  Serial.println(fsrReading);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  analogWrite(LEDpin, LEDbrightness);
 
  delay(100);

   fsrReading2 = analogRead(fsrAnalogPin2);
  //Serial.print("Analog reading2 = ");
  Serial.println(fsrReading2);
 
  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!
  LEDbrightness2 = map(fsrReading2, 0, 1023, 0, 255);
  // LED gets brighter the harder you press
  analogWrite(LEDpin2, LEDbrightness2);
 
  delay(100);

   // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.println(1000);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}


