# Arduino-Sun
Arduino library for calculating sunrise and sunset times.

Calculations are done using [the sunrise equation](https://guides.github.com/features/mastering-markdown/).

The library takes current time in [Unix Timestamp](https://en.wikipedia.org/wiki/Unix_time) format and returns sunrise and sunset times for the ongoing day in the same format.

Use of [Arduino Time library](http://playground.arduino.cc/Code/time) is recommended for timekeeping and converting between time formats.

## Usage
```cpp
// Initialize Sun object with local coordinates
Sun sun(46.24, 15.27);
// Current time (Unix Timestamp)
unsigned long tm = 1486908295
// Calculate time of sunrise for the ongoing day
unsigned long rise = sun.getRise(tm);
// Print results
Serial.print("Sun rises at: "); Serial.println(rise);
```
