#include "clock.h"
const int SECONDS = 1;
const int MINUTES = 2;
const int HOURS = 3;

const int TEST = 12;

/**
   This method should get called once every second - it makes
   the clock display go one second forward.
*/
void ClockDisplay::timeTick()
{
  seconds.increment();
  if (seconds.getValue() == 0) {
    minutes.increment();
    if (minutes.getValue() == 0) {
      hours.increment();
    }
  }
}

/**
   Return the current time of this display in the format HH:MM:SS.
*/
String ClockDisplay::getTime()
{

  String timeString = hours.getDisplayValue() + ":" + minutes.getDisplayValue() + ":" + seconds.getDisplayValue();
  return timeString;
}

/* Function to adjust hours, minutes or seconds based on input
 *  argument "selected".
 */
void ClockDisplay::setTime(int selected)
{
  switch(selected)
  {
    case SECONDS:
    seconds.increment();
    break;
    case MINUTES:
    minutes.increment();
    break;
    case HOURS:
    hours.increment();
    break;
  }
}


/* Default Constructor. Initializes 3 member variables of type NumberDisplay.
 */
ClockDisplay::ClockDisplay(): hours(24), minutes(60), seconds(60)
{
}
