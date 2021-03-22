#ifndef CLOCK_H
#define CLOCK_H

#include <arduino.h>    // Include access to Arduino functions and data types for this library.

/** A class to handle synchronization of timed tasks without pausing the program.
 *  Uses a unsigned long variable to keep track of system time when next timeout 
 *  will occur.
 */
class Timer
{
  public:
    bool hasExpired();
    void start(int timeout);
    Timer();
  private:
    unsigned long nextTimeout;
};

/**
 * The NumberDisplay class represents a digital number display that can hold
 * values from zero to a given limit. The limit can be specified when creating
 * the display. The values range from zero (inclusive) to limit-1. If used,
 * for example, for the seconds on a digital clock, the limit would be 60, 
 * resulting in display values from 0 to 59. When incremented, the display 
 * automatically rolls over to zero when reaching the limit.
 */
class NumberDisplay
{
  public:
    void increment();
    int getValue();
    NumberDisplay(int rollOverLimit);
    String getDisplayValue();
  private:
    int value;
    int limit;
};

/**
 * The ClockDisplay class implements a digital clock display for a
 * European-style 24 hour clock. The clock shows hours, minutes and seconds. The 
 * range of the clock is 00:00:00 (midnight) to 23:59:59 (one second before 
 * midnight).
 * 
 * The clock display receives "ticks" (via the timeTick method) every second
 * and reacts by incrementing the display. This is done in the usual clock
 * fashion: the hour increments when the minutes roll over to zero.
 */
class ClockDisplay
{
  public:
    String getTime();
    ClockDisplay();
    void timeTick();
    void setTime(int selected);
  private:
    NumberDisplay hours;
    NumberDisplay minutes;
    NumberDisplay seconds;
};

#endif
