/*
   A program to run a simple digital clock, with support for manually setting
   current time by use of SELECT and SET buttons. Using the SELECT button will
   allow the user to highlight values for seconds, minutes and hours respectively.
   Use of the SET button will allow adjustment of the highlighted values.
*/


// System states controlled by the SELECT button
const int S_RUN_CLOCK = 0;
const int S_SELECT_SECONDS = 1;
const int S_SELECT_MINUTES = 2;
const int S_SELECT_HOURS = 3;

// Pin allocation for SELECT and SET buttons.
const int SELECT_BTN = 7;
const int SET_BTN = 6;

const int LED_PIN = 12;

// Global state variable.
int currentState = S_RUN_CLOCK;

#include "clock.h"
#include <LiquidCrystal.h>


// initialize the LCD display with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Initialize a clockdisplay object
ClockDisplay myClock;

Timer timer1;

void setup() {
  pinMode(SELECT_BTN, INPUT);
  pinMode(SET_BTN, INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop() {
  // Get current time stored in myClock object in format HH:MM:SS
  String timeString = myClock.getTime();

  // Print current time on line 1
  lcd.setCursor(0, 0);
  lcd.print(timeString);

  switch (currentState) {
    case S_RUN_CLOCK:
      // Handle SELECT button:
      if (isButtonPressed(SELECT_BTN))
      {
        currentState = S_SELECT_SECONDS;
        printSelect(currentState);
      }
      // Update digital clock after 1 second
      if (timer1.hasExpired())
      {
        timer1.start(1000);
        myClock.timeTick();
      }
      break;

    case S_SELECT_SECONDS:
      // Handle SELECT button:
      if (isButtonPressed(SELECT_BTN))
      {
        currentState = S_SELECT_MINUTES;
        printSelect(currentState);
      }
      // Handle SET button
      if (isButtonPressed(SET_BTN))
      {
        // Increase seconds counter by 1
        myClock.setTime(currentState);
      }
      break;
    case S_SELECT_MINUTES:
      // Handle SELECT button:
      if (isButtonPressed(SELECT_BTN))
      {
        currentState = S_SELECT_HOURS;
        printSelect(currentState);
      }
      // Handle SET button
      if (isButtonPressed(SET_BTN))
      {
        // Increase minutes counter by 1
        myClock.setTime(currentState);
      }
      break;
    case S_SELECT_HOURS:
      // Handle SELECT button:
      if (isButtonPressed(SELECT_BTN))
      {
        currentState = S_RUN_CLOCK;
        printSelect(currentState);
      }
      // Handle SET button
      if (isButtonPressed(SET_BTN))
      {
        // Increase hours counter by 1
        myClock.setTime(currentState);
      }
      break;
  }

}
/*
    Detect button push AND subsequent release
*/
bool isButtonPressed(int pin)
{
  if (digitalRead(pin) == HIGH)
  {
    while (digitalRead(pin) == HIGH) {}
    return true;
  }
  else
  {
    return false;
  }
}
/* Highlight time value to be adjusted*/
void printSelect(int currentState) {
  lcd.setCursor(0, 1);
  lcd.print("        ");
  if (currentState != 0) {

    lcd.setCursor(3 * (3 - currentState), 1);
    lcd.print("^^");
  }
}
