/*
  PrintTimes.ino - Library for calculating sunrise and sunset times based on current local time and position on Earth.
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

#include <Sun.h>

void setup() {
  Serial.begin(9600);
  delay(100);

  Sun sun(46.24, 15.27);

  unsigned long tm = 1486908295;
  Serial.print("Current time: "); Serial.println(tm);

  unsigned long rise = sun.getRise(tm);
  Serial.print("Sun rises at: "); Serial.println(rise);

  unsigned long set = sun.getSet(tm);
  Serial.print("Sun sets at: "); Serial.println(set);

  unsigned long day = sun.getDayLength(tm);
  Serial.print("Daylength in seconds: "); Serial.println(day);

  unsigned long night = sun.getNightLength(tm);
  Serial.print("Night length in seconds: "); Serial.println(night);
}

void loop() {

}
