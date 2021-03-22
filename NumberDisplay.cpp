#include "clock.h"
/* Member function to increment value in NumberDisplay instance.
    If new value >= limit for the object, the value rolls
    over and starts at 0.
*/
void NumberDisplay::increment()
{
  value += 1;
  value %= limit;
}

/**
  Member Funciton to access current value in a NumberDisplay object.
*/
int NumberDisplay::getValue()
{
  return value;
}

/**
   Return the display value (that is, the current value as a two-digit
   String. If the value is less than ten, it will be padded with a leading
   zero).
*/
String NumberDisplay::getDisplayValue()
{
  if (value < 10)
  {
    return "0" + String(value);
  }
  else
  {
    return String(value);
  }
}

/* Constructor for objects of class NumberDisplay.
    Set the limit at which the display rolls over.
*/
NumberDisplay::NumberDisplay(int rollOverLimit): value(0)
{
  limit = rollOverLimit;
}
