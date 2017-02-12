/*
  Sun.cpp - Library for calculating sunrise and sunset times based on current local time and position on Earth.
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

#include "Sun.h"

const float pi = 3.14159265;

/*
 * Constructor. Latitude and longitude must be provided.
 */
Sun::Sun(float lat, float lon) {
  _lat = lat;
  _lon = lon;
}

/*
 * Calculates sunrise and sunset times based on current time. All times are in Unix Timestamp format.
 */
void Sun::getRiseSet(unsigned long unixTime, unsigned long &sunrise, unsigned long &sunset) {
  // Convert Julian day to Unix Timestamp
  unsigned long Jdate = (unsigned long) unixTime / 86400.0 + 2440587.5;
  // Number of days since Jan 1st, 2000 12:00
  float n = (float)Jdate - 2451545.0 + 0.0008;
  // Mean solar noon
  float Jstar = -_lon / 360 + n;
  // Solar mean anomaly
  float M = fmod((357.5291 + 0.98560028 * Jstar), 360);
  // Equation of the center
  float C = 1.9148 * sin(M / 360 * 2 * pi) + 0.02 * sin(2 * M / 360 * 2 * pi) + 0.0003 * sin(3 * M * 360 * 2 * pi);
  // Ecliptic longitude
  float lambda = fmod((M + C + 180 + 102.9372), 360);
  // Solar transit
  float Jtransit = Jstar + (0.0053 * sin(M / 360.0 * 2.0 * pi) - 0.0069 * sin(2.0 * (lambda / 360.0 * 2.0 * pi)));
  // Declination of the Sun
  float delta = asin(sin(lambda / 360 * 2 * pi) * sin(23.44 / 360 * 2 * pi)) / (2 * pi) * 360;
  // Hour angle
  float omega0 = 360 / (2 * pi) * acos((sin(-0.83 / 360 * 2 * pi) - sin(_lat / 360 * 2 * pi) * sin(delta / 360 * 2 * pi)) / (cos(_lat / 360 * 2 * pi) * cos(delta / 360 * 2 * pi)));
  // Julian day sunrise, sunset
  float Jset = Jtransit + omega0 / 360;
  float Jrise = Jtransit - omega0 / 360;
  // Convert to Unix Timestamp
  unsigned long unixRise = Jrise * 86400 + 946728000;
  unsigned long unixSet = Jset * 86400 + 946728000;
  sunrise = unixRise;
  sunset = unixSet; 
}

unsigned long Sun::getRise(unsigned long unixTime) {
  unsigned long rise;
  unsigned long set;
  getRiseSet(unixTime, rise, set);
  return rise;
}

unsigned long Sun::getSet(unsigned long unixTime) {
  unsigned long rise;
  unsigned long set;
  getRiseSet(unixTime, rise, set);
  return set;
}

unsigned long Sun::getDayLength(unsigned long unixTime) {
  unsigned long rise;
  unsigned long set;
  getRiseSet(unixTime, rise, set);
  return set - rise;
}

unsigned long Sun::getNightLength(unsigned long unixTime) {
  unsigned long rise;
  unsigned long set;
  getRiseSet(unixTime, rise, set);
  return 86400 - (set - rise);
}

