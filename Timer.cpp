#include "clock.h"

bool Timer::hasExpired()
{
  return (millis()>nextTimeout);
}

void Timer::start(int timeout)
{
  nextTimeout = millis() + timeout;
}

Timer::Timer() : nextTimeout(0) {};
