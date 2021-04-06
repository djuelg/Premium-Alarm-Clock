#include "RTCService.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void RTC_init()
{
    if (! rtc.begin()) {
      Serial.println("Couldn't find RTC");
      Serial.flush();
      abort();
    }

    if (rtc.lostPower()) {
      Serial.println("RTC lost power, please set the time!");
      // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

DateTime RTC_read_time()
{
  DateTime now = rtc.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    return now;
}

float RTC_read_temp()
{
  float temp = rtc.getTemperature();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  return temp;
}
