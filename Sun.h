/*
  Sun.h - Library for calculating sunrise and sunset times based on current local time and position on Earth.
  Calculations are based on Sunrise equation: https://en.wikipedia.org/wiki/Sunrise_equation
  Input and output times are in Unix Timestamp format (seconds since Jan 1, 1970, 00:00:00).
  
  Copyright (C) 2017  Nejc Planinsek

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef Sun_h
#define Sun_h

#include <arduino.h>

class Sun 
{
  public:
    Sun(float lat, float lon);
    void getRiseSet(unsigned long unixTime, unsigned long &sunrise, unsigned long &sunset);
    unsigned long getRise(unsigned long unixTime);
    unsigned long getSet(unsigned long unixTime);
    unsigned long getDayLength(unsigned long unixTime);
    unsigned long getNightLength(unsigned long unixTime);    
  private:
    float _lat;
    float _lon;
};

#endif
